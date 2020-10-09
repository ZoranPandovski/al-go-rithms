use std::io;

fn is_prime(n: i32) -> bool {
    for a in 2..n {
        if n % a == 0 {
            return false;
        }
    }
    true
}

fn main() {
    println!("Enter value");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    for i in 2..n{
        if(is_prime(i)){
            println!("{}", i);
        }
    }
}
