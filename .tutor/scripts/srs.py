#!/usr/bin/env python3
"""
srs.py — manages the question queue scheduling

Usage:
  python3 srs.py due              → prints JSON of questions due today
  python3 srs.py update <grades>  → updates queue.json with grade results
                                    grades is a JSON string: [{"id": "slug", "score": 4}, ...]
  python3 srs.py add <questions>  → appends new questions from digest output
                                    questions is a JSON string (array)

Scheduling uses a simplified SM-2 algorithm:
  - Base intervals vary by score (1-5)
  - Consecutive correct answers (score >= 4) expand the interval via a multiplier
  - Kernel-critical concepts (pointers, memory, undefined behavior) use shorter intervals
  - A score drop after consecutive successes resets the streak
"""

import json
import sys
from datetime import date, timedelta

QUEUE_PATH = ".tutor/queue.json"

# Base intervals by score (days)
BASE_INTERVALS = {
    5: 14,
    4: 7,
    3: 3,
    2: 1,
    1: 1,
}

# Concepts that get shorter intervals (kernel-critical)
KERNEL_CRITICAL = {
    "pointers", "pointer arithmetic", "memory", "malloc", "free",
    "dynamic memory", "undefined behavior", "stack", "heap",
    "buffer overflow", "dangling pointer", "null pointer",
    "array decay", "void pointer", "function pointer",
    "type casting", "implicit conversion",
}

def is_kernel_critical(question):
    """Check if a question covers a kernel-critical concept."""
    concept = question.get("concept", "").lower()
    return any(kc in concept for kc in KERNEL_CRITICAL)

def consecutive_correct(score_history):
    """Count consecutive scores >= 4 from the end of history."""
    count = 0
    for score in reversed(score_history):
        if score >= 4:
            count += 1
        else:
            break
    return count

def compute_interval(score, question):
    """Compute next review interval based on score, history, and concept criticality."""
    base = BASE_INTERVALS.get(score, 3)
    history = question.get("score_history", [])

    if score >= 4:
        streak = consecutive_correct(history)
        # Expand interval: base * 1.5^streak, capped at 60 days
        multiplier = min(1.5 ** streak, 4.0)
        interval = int(base * multiplier)
        interval = min(interval, 60)
    else:
        # Score <= 3: reset to short interval regardless of history
        interval = base

    # Kernel-critical concepts: cap interval more aggressively
    if is_kernel_critical(question):
        interval = min(interval, 21)  # never more than 3 weeks for critical concepts
        if score <= 3:
            interval = 1  # review tomorrow

    return interval

def load():
    with open(QUEUE_PATH) as f:
        return json.load(f)

def save(data):
    with open(QUEUE_PATH, "w") as f:
        json.dump(data, f, indent=2)

def due_today():
    data = load()
    today = date.today().isoformat()
    due = [q for q in data["queue"] if q["next_due"] is None or q["next_due"] <= today]
    # sort: never-asked first, then by next_due ascending
    due.sort(key=lambda q: (q["next_due"] is not None, q["next_due"] or ""))
    print(json.dumps(due, indent=2))

def update(grades_json):
    grades = json.loads(grades_json)
    data = load()
    today = date.today()
    grade_map = {g["id"]: g["score"] for g in grades}

    for q in data["queue"]:
        if q["id"] in grade_map:
            score = grade_map[q["id"]]
            q["score_history"].append(score)
            interval = compute_interval(score, q)
            q["next_due"] = (today + timedelta(days=interval)).isoformat()
            q["last_asked"] = today.isoformat()

    data["meta"]["last_updated"] = today.isoformat()
    save(data)
    print(f"Updated {len(grades)} questions.")

def add(questions_json):
    questions = json.loads(questions_json)
    data = load()
    existing_ids = {q["id"] for q in data["queue"]}
    added = 0

    for q in questions:
        if q["id"] not in existing_ids:
            q["next_due"] = date.today().isoformat()  # due immediately
            q["last_asked"] = None
            q["score_history"] = []
            data["queue"].append(q)
            added += 1

    data["meta"]["total_questions"] = len(data["queue"])
    data["meta"]["last_updated"] = date.today().isoformat()
    save(data)
    print(f"Added {added} new questions. Total: {data['meta']['total_questions']}")

if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else ""
    if cmd == "due":
        due_today()
    elif cmd == "update" and len(sys.argv) > 2:
        update(sys.argv[2])
    elif cmd == "add" and len(sys.argv) > 2:
        add(sys.argv[2])
    else:
        print(__doc__)
        sys.exit(1)
