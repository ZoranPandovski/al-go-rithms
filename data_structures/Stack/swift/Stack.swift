struct Stack<Element> {
    
    fileprivate var array: [Element] = []
    
    // Show top (last) element
    func peek() -> Element? {
        return array.last;
    }
    
    // Add an element to the stack
    mutating func push(_ element: Element) {
        array.append(element)
    }
    
    // Remove top (last) element from the stack
    mutating func pop() -> Element? {
        return array.popLast()
    }
    
    // Return number of elements in the stack
    func count() -> Int {
        return array.count
    }
    
    // Returns true when the stack is empty
    func isEmpty() -> Bool {
        return array.isEmpty
    }
    
}
