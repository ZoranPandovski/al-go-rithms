// Jump Search implementation in Rust by Jay9596
use std::cmp::min;

fn jump_search(arr: Vec<i32>,n :i32) -> i32 {
    let len = arr.len();
    //Step size calculated usinf length of array
    let mut step = (len as f64).sqrt() as usize;
    let mut prev: usize = 0;
    
    //Jumps block using step size
    while arr[min(step, len)-1] < n {
        prev = step;
        step += step;
        if prev >= len {
            return -1
        }
    }
    // Linear search
    while arr[prev] < n {
        prev += 1 ;
        if arr[prev] == (min(step, len)) as i32 {
            return -1
        }
    }
    // Element found
    if arr[prev] == n {
        return prev as i32
    }
    -1
}

fn main() {
    let arr = vec![0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 144, 233, 377, 610];
    println!("Number {} is at index {}",55,jump_search(arr,55));
}