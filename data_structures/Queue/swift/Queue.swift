struct Queue<Element> {
    
    fileprivate var array: [Element] = []
    
    // Show the first element
    func peek() -> Element? {
        return array.first;
    }
    
    // Add an element to the queue
    mutating func enqueue(_ element: Element) {
        array.append(element)
    }
    
    // Remove the first element from the queue
    mutating func dequeue() -> Element? {
        guard !isEmpty() else {
            return nil
        }
        return array.removeFirst()
    }
    
    // Return number of elements in the queue
    func count() -> Int {
        return array.count
    }
    
    // Returns true when the queue is empty
    func isEmpty() -> Bool {
        return array.isEmpty
    }
    
}
