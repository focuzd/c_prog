# C Tutor — Spaced Repetition via Claude Code

Automated spaced repetition and code evaluation powered by **Claude Code** + **Antigravity free inference** via [antigravity-claude-proxy](https://github.com/badrisnarayanan/antigravity-claude-proxy).

Tuned to a **24-month Linux kernel engineering roadmap** (GSOC 2027, LFX, EU systems roles).

---

## How it works

Claude Code acts as a strict tutor — reading your code, analyzing diffs, flagging problems, testing mental models, and tracking your progress against the kernel roadmap. Antigravity provides free model inference via the proxy.

### Two commands

| Command | Mode | What it does |
|---------|------|-------------|
| `/project:tutor-digest` | Can run headless | Diffs `.c` files since last run → flags code problems → updates mental model state → generates SRS questions |
| `/project:tutor-review` | Interactive | Presents due questions → you answer → grades on mental model depth → updates queue + session log |

---

## Setup (one-time)

### 1. Install Claude Code

```bash
npm install -g @anthropic-ai/claude-code
```

### 2. Install & start the proxy

```bash
npx antigravity-claude-proxy@latest start
```

On first run, link your Google account:
- Open http://localhost:8080 → Accounts → Add Account
- Or: `npx antigravity-claude-proxy@latest accounts add`

### 3. Configure Claude Code

Edit `%USERPROFILE%\.claude\settings.json`:

```json
{
  "env": {
    "ANTHROPIC_AUTH_TOKEN": "test",
    "ANTHROPIC_BASE_URL": "http://localhost:8080",
    "ANTHROPIC_MODEL": "claude-sonnet-4-6-thinking",
    "ANTHROPIC_DEFAULT_SONNET_MODEL": "claude-sonnet-4-6-thinking"
  }
}
```

### 4. Verify

```bash
# Check proxy is running
curl http://localhost:8080/health

# Launch Claude Code in this repo
cd c_prog
claude
```

---

## Daily workflow

1. Write code — exercises, projects, experiments
2. Commit your `.c` files
3. Run `/project:tutor-digest` — Claude flags problems in your code, updates your knowledge profile, generates questions aimed at your weakest mental models
4. Run `/project:tutor-review` — answer due questions, get honest grading

For headless digest (no interaction needed):

```bash
claude -p "/project:tutor-digest" --allowedTools "Read,Edit,Bash,Write"
```

---

## Files

```
.claude/
  commands/
    tutor-digest.md          ← digest workflow instructions
    tutor-review.md          ← review workflow instructions
.tutor/
    knowledge-base.md        ← your learning state (read this!)
    queue.json               ← question scheduling (managed by srs.py)
    session-log.md           ← append-only history of all sessions
    .last_digest_sha         ← tracks what's already been digested
  prompts/
    digest.md                ← evaluation rules for code analysis
    review.md                ← grading rubric for review sessions
  scripts/
    srs.py                   ← SRS scheduling logic
    diff-filter.py           ← strips noise from diffs
CLAUDE.md                    ← project context for Claude Code
kernel_roadmap.txt               ← the 24-month roadmap
```

---

## Tuning

- Edit `.tutor/prompts/digest.md` to change what the tutor focuses on (e.g., as you enter pointer chapters, tighten rules around memory safety)
- Edit `.tutor/prompts/review.md` to adjust grading strictness
- Manually append `> correction:` blockquotes to `knowledge-base.md` — the digest agent will reconcile them
- Edit `CLAUDE.md` to update learner profile, roadmap position, or goals

---

## Current focus

K.N. King — C Programming: A Modern Approach
Next: Chapter 11 (Pointers)
Month 1 deliverable: Snake with ncurses
Target: LFX Fall 2026 / GSOC 2027
