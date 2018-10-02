fn main() {
    let mut doors = vec![false; 100];

    for i in 0..100 {
        let mut j = i;
        while j < 100 {
            doors[j] = !doors[j];
            j += i + 1;
        }
    }

    for i in 0..100 {
        if doors[i] {
            println!("Door {} is open", i + 1);
        }
    }
}
