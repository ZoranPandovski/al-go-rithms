// In mathematics an automorphic number (sometimes referred to as a circular number)
// is a number whose square "ends" in the same digits as the number itself.

fn list_automorphic_numbers(start: i32, end: i32) {
    (start..end)
        .filter(|&n| is_automorphic(n as i128))
        .for_each(|n| println!("{}\t=>\t{}", n, n.pow(2)))
}

fn is_automorphic(n: i128) -> bool {
    let n_str = n.to_string();
    let sq_str = n.pow(2).to_string();
    n_str == sq_str[(sq_str.len() - n_str.len())..]
}

fn main() {
    list_automorphic_numbers(1, 10000)
}

#[test]
fn simple_test() {
    assert!(is_automorphic(5));
    assert!(is_automorphic(6));
    assert!(is_automorphic(76));
    assert!(is_automorphic(376));
    assert!(is_automorphic(890625));
}
