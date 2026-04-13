# Knowledge Base
_Managed by the tutor. Do not rewrite sections manually — append corrections under each section using `> correction:` blockquotes. The digest agent will reconcile._

---

## Learner Profile

- **Experimental files (`rough.c`)**: Use these to understand what the learner is curious about or struggling with, but do NOT strictly evaluate or penalize them. Focus formal evaluation on exercises (`que*.c`) and projects.

- **Primary goal**: Kernel engineering in the EU, targeting LFX Fall 2026 / Spring 2027, GSOC 2027
- **Current focus**: C mastery via K.N. King — "C Programming: A Modern Approach"
- **Month 1 deliverable**: Snake game using ncurses
- **Roadmap**: 24-month self-directed, structured
- **Style**: Prefers honest, strategic feedback over encouragement. Flags when understanding is shallow.

---

## Roadmap Progress

_Updated by the digest agent. Cross-reference with `kernel_roadmap.txt`._

- **Current roadmap month**: Month 2 (Apr 10 — May 10, 2026) — Pointers: The Critical Chapter
- **On track**: Chapters 8-11 complete ✅ | Snake game not started ⬜ | Month 1 deliverables not fully met
- **Next month**: Month 2 — Pointers (THE most important chapter). Ready for Chapter 12.

| Deliverable | Status |
|-------------|--------|
| King Chapters 8-11 complete with exercises | ✅ Done |
| Snake game — playable | ⬜ Not started |
| Can explain arrays, functions, program structure | 🔶 Not verified — probe in next review |

---

## Progress: K.N. King Chapters

| Chapter | Topic | Status | Notes |
|---------|-------|--------|-------|
| 2 | Fundamentals | ✅ Done | Multiple exercises + named programs (celsius, dweight, pun, parkinson) |
| 3 | Formatted I/O | ✅ Done | addfrac, conversion, exercises |
| 4 | Expressions | ✅ Done | upc + exercises |
| 5 | Selection (if/switch) | ✅ Done | broker, date, verify + 11 exercises |
| 6 | Loops | ✅ Done | square variants, checking, numdigits, label_behavior + 12 exercises |
| 7 | Basic Types | ✅ Done | length variants, sum2, verify + 15 exercises + ex_que15 |
| 8 | Arrays | ✅ Done | deal, display, interest, repdigit, reverse variants, rough + 17 exercises |
| 9 | Functions | ✅ Done | average, countdown, prime, pun2, qsort, rough + 18 exercises |
| 10 | Program Organization | ✅ Done | guess variants, poker + all exercises |
| 11 | Pointers | ✅ Done | maxmin.c, exercises (pass-by-reference, returning pointers) |
| 12 | Pointers and Arrays | 🔄 In Progress | reverse3.c |

---

## Concepts: Solid

- Pointer mechanics: `&` (address-of) and `*` (indirection) operators
- Pass-by-reference: returning multiple values via pointers (e.g. split_time, reduce)
- Returning pointers: understands stack frames, variable lifetime, and dangling pointers
- Refactoring globals: successfully converted poker.c global state to local variables passed by reference
- Memory representations: IEEE 754 (floating point) vs Two's complement (integers), strict aliasing violation
- Character literals vs Strings: Understands that `''` is invalid and ` ` represents 8 zero bits.

- Basic types: int, float, double, char — declaration, initialization, arithmetic
- Formatted I/O: printf/scanf format specifiers, field widths
- Control flow: if/else, switch/case, all loop forms (for, while, do-while)
- break/continue/goto — understands goto via label_behavior.c experiment
- Arrays: 1D declaration, initialization, traversal, passing to functions
- Basic functions: declaration, definition, parameters, return values, scope
- Modular thinking: separating programs across functions (chap9, chap10)
- Recursion: present in chap9 exercises (countdown, prime)

---

## Concepts: Shaky

- **Program organization (chap10)**: External variables, header separation — depth unclear
- **Array–function interaction**: Whether decay vs. copy semantics is fully internalized — not verified yet
- **qsort usage**: File exists but mental model of function pointers as comparators may be surface-level

---

## Identified Gaps

- [ ] Lvalues vs Rvalues (specifically regarding address-of operator returning an rvalue)
- [ ] Concurrency and Race Conditions (understanding why global variables are dangerous in kernels)
- [ ] Undefined Behavior and Strict Aliasing (needs broader coverage beyond type punning)
- [ ] Strings — not started (chap 13)
- [ ] Structs — not started (chap 16)
- [ ] Dynamic memory (malloc/free) — not started
- [ ] File I/O — not started
- [ ] Preprocessor, macros — not started
- [ ] Function pointers — surface exposure via qsort only
- [ ] Multi-file compilation, Makefiles — not yet practiced deliberately
- [ ] void* generics — not covered

---

## Projects

### password-manager
- **Status**: Exists (passman.c), has a README.c (unusual — review intent)
- **Assessment**: Unknown depth. Uses file I/O (passvoid.txt) suggesting chap14+ territory or self-directed exploration
- **Tutor note**: Read this file carefully — it may reveal understanding ahead of or misaligned with chapter progress

### curl/fetch.c
- **Status**: Exists — suggests libcurl usage or raw socket work
- **Tutor note**: If self-directed, this is significant. Verify what's actually in it.

### Snake (ncurses)
- **Status**: Not started in repo yet — Month 1 deliverable
- **Design already reasoned**: 1D array grid with `row * cols + col` indexing, game loop structure thought through
- **Next**: Begin implementation after reaching comfortable pointer foundation

---

## Mental Models

- **Lvalues vs Rvalues**: Now understands that `*p` yields an lvalue (the object itself), but applying the address-of operator `&(*p)` yields an rvalue (a raw memory address) which cannot be modified or assigned to.
- Pointer interpretation: Understands that casting pointers changes how the underlying bits are read, not the bits themselves.
- "Array name = address of first element, not a pointer variable" — conceptually stated but not yet tested under pointer chapter.
- Loop selection instinct: seems solid given volume of chap6 exercises.

---

## Session Log Summary

_Appended by review agent after each session. Empty until first session runs._

---

## Tutor Flags

- `chap10/rough.c` — testing empty char literal `''`. Clarify difference between empty string `""` and chars.
- `qsort.c` in chap9 — verify the comparator function understanding in next review.
- `password-manager` and `curl/fetch.c` — digest agent should read these on first run and update this knowledge base.

---

## Digest — 2026-04-12

**Summary**: The learner added textbook code for Chapter 11 (maxmin.c) and two experimental files (rough.c). These experimental files show a strong habit of exploring edge cases, which is excellent for a systems programmer, but highlight current misunderstandings regarding character literals and pointer type safety.

**Changes detected**: `chap10/rough.c`, `chap11/maxmin.c`, `chap11/rough.c`
**Code quality issues**: `chap10/rough.c` contains `char ch = '';` which is invalid C and will not compile. `chap11/rough.c` intentionally assigns `&x` (a `double*`) to `p` (an `int*`), invoking incompatible pointer warnings and undefined behavior upon dereference.
**Mental model observations**: The learner is actively testing the boundaries of the language (UB, invalid literals) via `rough.c` files. This is a great mindset for a kernel developer. However, they need to conceptually separate memory bits from types, understanding that an `int*` reading a `double`'s memory will read IEEE 754 bits, not perform a value conversion to `3`.
**Concepts promoted/demoted**: None.
**New gaps identified**: Pointer strict aliasing / memory representation differences (int vs double), invalid empty character literals.
**Roadmap status**: On track for Month 2 (Pointers). Exploring chap11 textbook examples and pointer behavior.

---

## Digest — 2026-04-13

**Summary**: The learner completed Chapter 10 exercises and Chapter 11 (Pointers) exercises. They successfully demonstrated pass-by-reference to eliminate global variables in `poker.c` and grasped the subtle difference between lvalues and rvalues when using the indirection operator.

**Changes detected**: `chap10/que1.c` through `chap10/que7.c`, `chap11/que1.c` through `chap11/que4.c`.
**Code quality issues**: Array bounds in `split_date` (chap11/que1-7.c) could overflow if `day_of_year` > 366. Otherwise, excellent reasoning in `find_two_largest` handling edge cases.
**Mental model observations**: The comment in `chap11/que1.c` explicitly states that `*p` gives the object itself, not just the value, which perfectly aligns with systems-level lvalue/rvalue understanding.
**Concepts promoted/demoted**: Promoted pointer mechanics, pass-by-reference, and returning pointers to Solid.
**New gaps identified**: None.
**Roadmap status**: On track for Month 2 (Pointers). Ready for Chapter 12 (Pointers and Arrays).
---

## Digest — 2026-04-14

**Summary**: The learner added `reverse3.c`, a textbook example from Chapter 12 demonstrating array traversal using pointers. Since there is no original exercise code (`que*.c`), no new mental models can be verified yet, but they have begun the critical Pointers and Arrays chapter.

**Changes detected**: `chap12/reverse3.c`
**Code quality issues**: None (textbook code).
**Mental model observations**: The learner is moving into pointer arithmetic, comparing pointers (`p < a + N`), and using pointers to iterate through arrays.
**Concepts promoted/demoted**: None.
**New gaps identified**: None.
**Roadmap status**: On track. Started Chapter 12 (Pointers and Arrays).
