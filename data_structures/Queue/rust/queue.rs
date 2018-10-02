struct Queue<T> {
    data: Vec<T>
}

impl<T> Queue<T> {
    // Returns a new Queue object
    fn new() -> Queue<T> {
        Queue{data: vec![]}
    }

    // Adds the element to the end of the list
    fn enqueue(&mut self, e: T) {
        self.data.push(e)
    }

    // Returns an Option with first element of the list,
    // if it is empty retruns None
    fn dequeue(&mut self) -> Option<T> {
        if self.data.is_empty() {
            return None;
        }
        Some(self.data.remove(0))
    }

    // Returs true if queue is empty
    fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    // Returns an Option with the first element, if queue is empty gives None
    // This does not remove the element, just displays it.
    fn peek(&self) -> Option<&T> {
        if self.data.is_empty() {
            return None;
        }
        let e = &self.data[0];
        Some(e)
    }

    // Returns the length of queue
    fn len(&self) -> usize {
        self.data.len()
    }
}
