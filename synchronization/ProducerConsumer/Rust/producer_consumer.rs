// mpsc is Multiple Producer, Single Consumer.
use std::sync::mpsc;
use std::thread;

fn main() {
    // Make channels for sending and receiving
    let (send, recv) = mpsc::channel();
    let (send_done, recv_done) = mpsc::channel();

    for i in 0..10 {
        let tx = send.clone();
        let send_d = send_done.clone();

        // Spawn a thread and send data from inside the thread
        thread::spawn(move || {
            tx.send(i).unwrap();
            
            // At the last number send the done message
            match i {
                9 => send_d.send(true).unwrap(),
                _ => send_d.send(false).unwrap(),
            };
        });
    }

    // Loop is an infinite loop that runs until the done message is not received.
    loop {
        println!("{}", recv.recv().unwrap_or(-1));
        if recv_done.recv().unwrap_or(false) {
            break;
        }
    }
}
