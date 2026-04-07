# GitHub Tutor

Automated spaced repetition and code evaluation running inside this repo.

---

## How it works

**Daily digest** (auto, 2 AM UTC / ~7:30 AM IST):
- Diffs all `.c` files since last run
- Feeds changes to GPT-4o → updates `knowledge-base.md` + generates new questions
- Commits silently

**Review session** (manual):
1. Go to **Actions → Review Session → Run workflow**
2. A GitHub Issue is created with 4 questions due today
3. Answer in a single comment on the issue (label answers Q1, Q2, etc.)
4. o3-mini grades your answers → posts scores + feedback as a reply comment
5. Queue updated, session appended to log

---

## Files

```
.github/
  tutor/
    knowledge-base.md    ← your learning state. read this.
    queue.json           ← question scheduling (don't edit manually)
    session-log.md       ← append-only history of all sessions
  prompts/
    digest.md            ← tutor behavior for digest runs
    review.md            ← tutor behavior for review + grading
  scripts/
    srs.py               ← scheduling logic
    diff-filter.py       ← strips noise from diffs
  workflows/
    digest.yml
    review.yml
```

---

## Setup (one-time)

1. Make sure GitHub Actions has write permissions: **Settings → Actions → General → Workflow permissions → Read and write**
2. The `GITHUB_TOKEN` secret is automatic — GitHub Education gives you model access through it
3. Create the `review-session` label: **Issues → Labels → New label** → name it `review-session`
4. Push these files to your repo and the first digest will run at 2 AM UTC, or trigger it manually

---

## Tuning

- Change cron schedule in `digest.yml` if you want a different time
- Edit `prompts/digest.md` to change what the tutor focuses on (e.g., as you move into pointer chapters, you can tell it to be stricter about memory safety)
- You can manually add corrections to `knowledge-base.md` using `> correction:` blockquotes — the digest agent will reconcile them

---

## Current focus

K.N. King — C Programming: A Modern Approach  
Next: Chapter 11 (Pointers)  
Month 1 deliverable: Snake with ncurses  
Target: LFX Fall 2026 application window (May 14–27 for Spring 2027)
