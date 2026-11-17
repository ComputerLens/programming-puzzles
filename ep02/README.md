# How Many NaNs Fit in a Set? (Python, JavaScript, Java, Go)

Episode 02 of Programming Puzzles by [Computer Lens](https://www.youtube.com/@ComputerLens).

Let `x` be NaN (not a number) and `y = x + 1`, which is also NaN. Insert `x`, `x` again, and `y` into an empty collection. How many entries will each language keep? Can you look up `x`, the stored `y`, or a freshly computed `x + 1`?

## Run the examples

Run these commands from the directory containing the source files.

### C opener

```sh
gcc -std=c17 -O2 twist.c -o twist
./twist
```

The program prints `0` for both `x == x` and `x == x + 1`. Both comparisons are false.

### The four collections

Use CPython for the Python example, Node.js for JavaScript, and Java 11 or later for Java source-file mode.

```sh
python3 nan_set.py
node nan_set.js
java NanSet.java
go run nan_set.go
```

### Rust bonus

```sh
rustc nan_set.rs
```

Expect a compile error at `s.insert(x)`. Calling `HashSet::insert` requires the element type to implement `Eq` and `Hash`. Rust's `f64` implements neither.

## Expected results

| Runtime | Collection | Size | Finds `x` | Finds stored `y` | Finds a fresh `x + 1` |
|---|---|---:|---|---|---|
| CPython | `set` | 2 | `True` | `True` | `False` |
| JavaScript | `Set` | 1 | `true` | `true` | `true` |
| Java | `HashSet<Double>` | 1 | `true` | `true` | `true` |
| Go | `map[float64]bool` | 3 | `false` | `false` | `false` |

- **CPython** recognises the same float object on repeat insertion and lookup. Calculating `x + 1` again creates a fresh NaN object, so that lookup misses.
- **JavaScript** uses SameValueZero for `Set`, so NaN values match each other.
- **Java** boxes the primitive `double` values as `Double`. The boxed equality and hash rules treat all NaNs as a single member.
- **Go** compares float keys using `==`. A NaN key matches no key, so all three assignments create entries and all three lookups miss. A missing key returns `false`, the zero value of `bool`. The program prints `map[NaN:true NaN:true NaN:true]`.

## Try it yourself

Insert `+0.0` and `-0.0` into an empty collection in each of the four languages. Which collection keeps both values as separate entries?
