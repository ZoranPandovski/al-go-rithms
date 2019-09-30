use std::io;

fn fact(n:i32) -> f64 {
    match n {
        0 => 1.0,
        _ => n as f64 * fact(n-1)
    }
}

fn main() {
    println!("Enter a number");
    let mut num = String::new();
    io::stdin().read_line(&mut num);
    let num : i32 = num.trim().parse().unwrap();
    println!("factorial of {} = {}",num,fact(num));
}