# C Programming → Linux Kernel Engineering

## What This Repo Is

A self-directed C programming learning repo following a 24-month roadmap toward Linux kernel engineering (GSOC 2027, LFX, EU systems roles). Currently in **Phase 1: C & Systems Literacy** — working through K.N. King's "C Programming: A Modern Approach".

## Roadmap Context

The learner is following `kernel_roadmap.txt` in this repo. Key milestones:
- **Phase 1** (Mar–Sep 2026): C mastery via K.N. King → Snake game → string library → custom malloc → DSA → mini shell → HTTP server
- **Phase 2** (Sep 2026–Mar 2027): Computer architecture → performance optimization → database internals → container runtime → Redis clone → GSOC application
- **Phase 3** (Mar–Jul 2027): OS theory (xv6/OSTEP) → kernel modules → eBPF → first kernel patches → subsystem specialization

Current position: Chapter 10 complete, Chapter 11 (Pointers) next. Month 1 deliverable: Snake game with ncurses.

## Repo Structure

- **`chap*`** directories: K.N. King textbook work. Named programs (e.g., `poker.c`, `qsort.c`) are textbook example code, not original creations. `que*.c` files are exercises — these are where the learner's own thinking shows.
- **`day-*`** directories: Daily practice sessions.
- **`password-manager/`**, **`curl/`**: Self-directed projects — these are original work and should be evaluated more carefully.

## Tutor System

This repo has a spaced-repetition tutor system. State lives in `.tutor/`:

- **`knowledge-base.md`** — The learner's current understanding: solid concepts, shaky concepts, identified gaps, mental models, tutor flags. **Read this first before any tutor operation.**
- **`queue.json`** — SRS question queue. Managed by `srs.py`. Questions have IDs, scores, rubrics, and due dates.
- **`session-log.md`** — Append-only history of all review sessions.

Scripts in `.tutor/scripts/`:
- **`srs.py`** — Queue scheduler. Commands: `due` (get due questions), `add <json>` (add new questions), `update <json>` (update scores after grading).
- **`diff-filter.py`** — Filters git diffs to remove whitespace-only and trivial changes. Pipe git diff into stdin.

Evaluation rules in `.tutor/prompts/`:
- **`digest.md`** — Rules for analyzing code changes and generating questions.
- **`review.md`** — Rules for grading answers (1-5 scale).

## Tutor Goal

The primary goal is to **improve the learner's mental models** and help them write better code. Specifically:
- **Flag problems** in the learner's current code — don't just check correctness, check quality and understanding
- **Build deep understanding** — the learner must internalize concepts at a level required for kernel work, not just pass exercises
- **Evaluate against the roadmap** — if the learner is in Month 2 (Pointers), ensure pointer fundamentals are being internalized, not surface-level
- **Be honest about gaps** — shallow understanding of memory, pointers, or undefined behavior is not acceptable for someone targeting kernel engineering
- **Focus on exercise code (`que*.c`)** for understanding the learner's thinking; textbook programs in `chap*` are reference implementations

## Learner Profile

- **Goal**: Linux kernel engineering — GSOC 2027, LFX mentorship, EU systems internship
- **Commitment**: 2 hours daily, no AI code generation, man pages and docs only
- **Style**: Prefers honest, strategic feedback over encouragement. Flag shallow understanding.
- **Current progress**: K.N. King Chapters 2-10 complete. Chapter 11 (Pointers) is next.
- **Debt ledger**: ₹500 per missed day → charity upon first salary. Current: ₹5500

## Commands

- `/project:tutor-digest` — Analyze code changes since last run, update knowledge base, generate SRS questions
- `/project:tutor-review` — Interactive review session: present due questions, grade answers, update state
