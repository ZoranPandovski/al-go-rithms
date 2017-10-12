use std::cmp;

/// Returns a vector containing the fibonacci sequence, up to n numbers.
fn fib(n: u32) -> Vec<u32> {
    let mut n2 = n;
    let mut f = vec![];

    if n == 0 {
        return f;
    }

    while n2 > cmp::max(n-2, 0) {
        f.push(1);
        n2 -= 1;
    }

    while n2 > 0 {
        let length = f.len();
        let a = f[length-1];
        let b = f[length-2];
        f.push(a+b);
        n2 -= 1;
    }

    f
}
