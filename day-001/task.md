## CODING TASK:

Write a program that implements a **simple calculator** using a switch statement.

### Requirements:

**Input format:**
```
Enter an expression: 10 + 5
Value of expression: 15
```

**Supported operators:** `+`, `-`, `*`, `/`, `%`

**Specifications:**
1. Read two operands and one operator from user
2. Use `scanf()` with format: `"%lf %c %lf"` to read: `operand1 operator operand2`
3. Use a **switch statement** on the operator character
4. Handle division by zero (print error message)
5. Handle modulo with non-integers (print error or cast to int)
6. Handle invalid operators (print "Invalid operator")

### Challenge Extensions (prove depth):
1. **Operator precedence check:**
   - If user enters: `5 + 3 * 2`
   - Your program should calculate `5 + 3 = 8`, then tell user "Note: This calculator evaluates left to right, not by precedence"

2. **Short-circuit verification:**
   - Add a case for division that checks denominator BEFORE attempting division
   - Add comments explaining why you check in that order
