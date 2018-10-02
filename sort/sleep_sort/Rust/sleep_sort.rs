// This is dependant on the system threads, thus can produce different outputs each time 

use std::thread;
use std::time::Duration;
use std::sync::mpsc;

fn main() {
    let nums = vec![10, 2, 3, 11, 4, 6, 7, 1, 9, 8, 5, 10];
    let (tx, rx) = mpsc::channel();

    for i in 0..nums.len() {
        let tx = tx.clone();
        let num = nums[i];
        thread::spawn(move || {
            sleep_thread(num, tx);
        });
    }

    for _ in 0..nums.len() {
        println!("{}", rx.recv().unwrap());
    }
    
}

// Each thread sleeps for 'n' milli seconds before sending the data to receiver.
fn sleep_thread(i: i32, tx: mpsc::Sender<i32>) {
    thread::sleep(Duration::from_millis(i as u64));
    tx.send(i).unwrap();
}
