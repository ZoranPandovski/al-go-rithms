use std::io;
use std::io::Write;
fn collatz(n: u64) -> Vec<u64> {
    if n == 1 {
        return vec![n];
    }
    let mut result = vec![n];
    if n % 2 == 0 {
        result.append(&mut collatz(n/2));
    } else {
        result.append(&mut collatz(n*3 + 1));
    }
    result
}
fn main() {
    print!("Enter a number to display its collatz sequence: ");
    io::stdout().flush().unwrap();
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    match s.trim_right().parse::<u64>() {
        Ok(n) => println!("Collatz sequence: {:?}", collatz(n)),
        Err(_) => println!("Invalid number."),
    }
}
