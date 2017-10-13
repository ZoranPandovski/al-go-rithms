fn check_strong_number(mut n: i32) -> bool {
    let temp = n;
    let mut sum = 0;
    while n > 0 {
        
        let r = n % 10;
        n /= 10;
        sum += fact(r);
    }
    if sum == temp {
        return true
    }
    false
}

fn fact(n :i32) -> i32 {
    match n {
        0 => 1,
        _ => n * fact(n-1)
    }
}

fn main() {
    let num = 145;
    if check_strong_number(num) {
        println!("{} is a strong number", num);
    }else {
        println!("{} is not a strong number", num);
    }
}