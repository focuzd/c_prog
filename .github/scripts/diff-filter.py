#!/usr/bin/env python3
"""
diff-filter.py — filters git diff output before feeding to the digest agent

Usage:
  git diff <since>..<until> -- '*.c' | python3 diff-filter.py

Strips:
  - Whitespace-only changes
  - Binary files
  - Compiled artifacts (no extension)
  - Changes under 3 meaningful lines (too trivial to analyze)

Outputs:
  Filtered diff to stdout, or exits with code 1 if nothing meaningful remains
"""

import sys
import re

def is_meaningful_hunk(hunk_lines):
    """A hunk is meaningful if it has 3+ added/removed non-whitespace lines."""
    meaningful = [
        l for l in hunk_lines
        if (l.startswith('+') or l.startswith('-'))
        and not l.startswith('+++')
        and not l.startswith('---')
        and l[1:].strip()  # not whitespace-only
    ]
    return len(meaningful) >= 3

def filter_diff(raw):
    output = []
    current_file_lines = []
    current_file_is_c = False
    in_hunk = False
    current_hunk = []
    file_has_meaningful = False

    lines = raw.splitlines(keepends=True)
    i = 0

    while i < len(lines):
        line = lines[i]

        if line.startswith('diff --git'):
            # flush previous file
            if current_file_is_c and file_has_meaningful:
                output.extend(current_file_lines)

            current_file_lines = [line]
            current_file_is_c = False
            file_has_meaningful = False
            in_hunk = False
            current_hunk = []

        elif line.startswith('--- ') or line.startswith('+++ '):
            current_file_lines.append(line)
            if line.endswith('.c\n') or line.endswith('.c'):
                current_file_is_c = True

        elif line.startswith('@@'):
            # flush previous hunk
            if current_hunk and is_meaningful_hunk(current_hunk):
                current_file_lines.extend(current_hunk)
                file_has_meaningful = True
            current_hunk = [line]

        elif current_hunk is not None:
            current_hunk.append(line)
            current_file_lines.append(line) if not in_hunk else None

        else:
            current_file_lines.append(line)

        i += 1

    # flush last hunk and file
    if current_hunk and is_meaningful_hunk(current_hunk):
        current_file_lines.extend(current_hunk)
        file_has_meaningful = True

    if current_file_is_c and file_has_meaningful:
        output.extend(current_file_lines)

    return ''.join(output)

if __name__ == "__main__":
    raw = sys.stdin.read()
    result = filter_diff(raw)
    if not result.strip():
        sys.exit(1)
    print(result)
