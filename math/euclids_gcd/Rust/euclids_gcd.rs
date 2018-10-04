fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = a % b;
        a = b;
        b =  temp;       
    }
    a
}

fn main() {
    let a = 10;
    let b = 15;
    println!("GCD({}, {}) = {}",a,b,gcd(a,b));
    
    let a = 35;
    let b = 10;
    println!("GCD({}, {}) = {}",a,b,gcd(a,b));

    
    let a = 31;
    let b = 2;
    println!("GCD({}, {}) = {}",a,b,gcd(a,b));
}
