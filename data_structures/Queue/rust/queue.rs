struct Queue<T> {
    data: Vec<T>
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue{data: vec![]}
    }

    fn enqueue(&mut self, e: T) {
        self.data.push(e)
    }

    fn dequeue(&mut self) -> Option<T> {
        if self.data.is_empty() {
            return None;
        }
        Some(self.data.remove(0))
    }

    fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    fn peek(&self) -> Option<&T> {
        if self.data.is_empty() {
            return None;
        }
        let e = &self.data[0];
        Some(e)
    }
}
