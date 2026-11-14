# Episode 1 · 4 Ways to Make x == x + 1 True in C

In maths, x can never equal x + 1. In C, we make it TRUE in four different ways. Only the definition of `x` changes; the rest of the program stays the same.

| File | How x is defined | Result |
|---|---|---|
| `challenge.c` | `int x = 2;` | FALSE |
| `soln1.c` | `#define x 2 \| 0` | TRUE |
| `soln1b.c` | `#define x (2 \| 0)` | FALSE |
| `soln2.c` | `double x = 1e100;` | TRUE |
| `soln3.c` | `double x = 1.0 / 0.0;` | TRUE |
| `soln4.c` | `struct Empty {} items[2], *x = items;` | TRUE with gcc, FALSE with g++ |

## Run it
    gcc soln1.c && ./a.out
    g++ soln4.c && ./a.out     # the same file compiled as C++

## Why it works
1. **Macro:** the preprocessor substitutes the macro's tokens, so `x == x + 1` becomes `2 | 0 == 2 | 0 + 1`, which groups as `2 | (0 == 2) | (0 + 1)` = 3, and non-zero is true. With parentheses it becomes `2 == 3`.
2. **Googol:** `double` is IEEE 754 binary64 with 53 bits of precision. Near 1e100, neighbouring doubles are about 1.9 × 10^84 apart, so x + 1 rounds back to x. It already happens at 2^53 (round to nearest, ties to even).
3. **Infinity:** with IEEE 754 arithmetic and the default non-trapping behaviour, 1.0 / 0.0 is +∞, and +∞ + 1 is still +∞.
4. **Empty structs:** GNU C gives an empty struct size zero, so x + 1 points to the same address. Standard C requires at least one member; C++ gives each element a nonzero size, so there x + 1 moves on.

Tested with GCC on Ubuntu.

## Challenge
Can you write a different one-line macro that also makes this print TRUE? Answer in the YouTube comments.
