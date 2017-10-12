fn search(vec: &[i32], n: i32) -> i32 {
    for i in 0..vec.len() {
        if vec[i] == n {
            return i as i32;
        }
    }
    -1
}

fn main() {
    let arr = vec![14, 7, 8, 42, 99, 32, 76, 88, 1];
    let num = 42;
    let index =  search(&arr, num);
    if index != -1 {
        println!("Found {}, at index {}", num, index);
    }else {
        println!("{} not found!", num);
    }
}