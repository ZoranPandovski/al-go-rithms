use std::io;

fn main() {
    let mut state: i32 = 0;

    while state != 25 {
        let mut coin = String::new();

        println!("Balance: {}", state);
        println!("Insert a coin (pennt, nickel, dime, quarter)");
        
        io::stdin().read_line(&mut coin)
                .expect("Failed to read line");

        match coin.trim() {
            "penny" => state += 1,
            "nickel" => state += 5,
            "dime" => state += 10,
            "quarter" => state += 25,
            _ => println!("Not a coin"),
        };
    }

    println!("Here's your quarter");
}
