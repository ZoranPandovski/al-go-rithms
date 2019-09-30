struct Stack<T> {
    data: Vec<T>,
}

impl<T> Stack<T> {
    //  Returns a new Stack
    fn new() -> Stack<T> {
        Stack { data: vec![] }
    }

    // Pushes the elemnt to top of stack
    fn push(&mut self, e: T) {
        self.data.push(e)
    }

    // Returns Option with top element of the stack
    fn pop(&mut self) -> Option<T> {
        self.data.pop()
    }

    // Returns true if stack is empty
    fn is_empty(&self) -> bool {
        self.data.is_empty()
    }

    // Returns length of Stack
    fn len(&self) -> usize {
        self.data.len()
    }
}
