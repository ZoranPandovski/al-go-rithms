fn euler_totient(n: i32) -> i32 {
    let mut count = 1;
    for i in 2..n {
        if gcd(n,i) == 1 {
            count += 1;
        }
    }
    count
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    if a == 0 {
        return b
    }
    while b != 0 {
        let temp = a % b;
        a = b;
        b =  temp;       
    }
    a
}

fn main() {
    println!("{}",euler_totient(5));
}

// To Complie and run the test
/// `rustc --test .\euler_totient.rs`
/// `.\euler_totient.exe`
#[test]
fn euler_totient_test() {
    assert_eq!(1, euler_totient(1));
    assert_eq!(1, euler_totient(2));
    assert_eq!(2, euler_totient(3));
    assert_eq!(2, euler_totient(4));
    assert_eq!(4, euler_totient(5));
    assert_eq!(2, euler_totient(6));
}