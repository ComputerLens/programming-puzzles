# ep03 · BlackJack or JackBlack? Same C Code, Two Compilers

The same C file prints `JackBlack` when built with GCC and `BlackJack` when built with Clang. Both compilers are right: C leaves the order in which a function's arguments are evaluated **unspecified**. The program is valid C; the standard simply allows more than one result.

| File | What it shows |
|---|---|
| `word_order.c` | `printf("%s%s\n", say("Black"), say("Jack"));` where `say()` prints its word and returns `""` |
| `word_order_fixed.c` | The two calls moved into separate statements, so the order is fixed |
| `score.c` | `add(reset(), double_score())` where both functions change the same global |
| `score_plus.c` | The same calls joined with `+` instead of `add` |
| `score_fixed.c` | `reset()` and `double_score()` in separate statements |

## Run

```bash
gcc word_order.c && ./a.out
clang word_order.c && ./a.out
```

To run the other examples, replace `word_order.c` in both commands with a filename from the table.

## Output we observed

Built with plain `gcc file.c` and `clang file.c` (default flags) on x86-64 Linux with GCC 15.2 and Clang 21.1 (the versions used in the video), and also with GCC 13.3 and Clang 18.1:

| Program | GCC | Clang |
|---|---|---|
| `word_order` | `JackBlack` | `BlackJack` |
| `word_order_fixed` | `BlackJack` | `BlackJack` |
| `score` | `23` | `9` |
| `score_plus` | `9` | `9` |
| `score_fixed` | `9` | `9` |

`score_plus` gives the same answer on both compilers here, but the order of the operands of `+` is just as unspecified. Agreement on one setup is not a guarantee. Other compiler versions, targets or flags may choose differently; only the `_fixed` versions are guaranteed.

The two compilers' default C standards may differ. That doesn't change the puzzle: the order of argument evaluation is unspecified in every C standard.
