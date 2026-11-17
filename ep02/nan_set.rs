use std::collections::HashSet;

fn main() {
    let x = f64::NAN;
    let mut s = HashSet::<f64>::new();
    s.insert(x);
}
