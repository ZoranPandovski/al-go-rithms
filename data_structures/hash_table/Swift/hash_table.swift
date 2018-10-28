import Foundation

struct HashTable<Key: Hashable, Value> {
    
    private var buckets: [HashNode<Key, Value>?]
    private var capacity: Int
    private(set) var collisions = 0
    private(set) var count = 0
    public var isEmpty: Bool { return count == 0 }
    
    init(capacity: Int) {
        buckets = [HashNode<Key, Value>?](repeating: nil, count: capacity)
        self.capacity = capacity
    }
    
    // Adds key value pair to buckets. Updates value if key already exists
    mutating func addUpdate(key: Key, value: Value) {
        let hashIndex = index(forKey: key)
        let destNode = buckets[hashIndex]
        
        if destNode == nil {
            count += 1
            buckets[hashIndex] = HashNode(key: key, value: value)
        } else {
            var curNode = destNode
            while curNode != nil {
                if curNode!.key == key {
                    collisions += 1
                    curNode!.value = value
                    return
                }
                curNode = curNode!.nextNode
            }
            
            count += 1
            buckets[hashIndex] = HashNode(key: key, value: value, nextNode: destNode)
        }
    }
    
    func value(forKey key: Key) -> Value? {
        let hashIndex = index(forKey: key)
        var node = buckets[hashIndex]
        
        if node == nil {
            return nil
        }
        
        while node != nil {
            if node!.key == key {
                return node!.value
            }
            node = node!.nextNode
        }
        
        return nil
    }
    
    // Returns the value of the removed element if found, nil otherwise
    mutating func remove(atKey key: Key) -> Value? {
        let hashIndex = index(forKey: key)
        var node = buckets[hashIndex]
        
        if node == nil {
            return nil
        }
        
        var prevNode: HashNode<Key, Value>?
        while node != nil {
            if node!.key == key {
                if prevNode == nil {
                    if node!.nextNode == nil {
                        buckets[hashIndex] = nil
                    } else {
                        buckets[hashIndex] = node!.nextNode
                    }
                } else if node!.nextNode == nil {
                    prevNode!.nextNode = nil
                } else {
                    prevNode!.nextNode = node!.nextNode
                }
                count -= 1
                return node!.value
            }
            prevNode = node
            node = node!.nextNode
        }
        
        return nil
    }
    
    private func index(forKey key: Key) -> Int {
        return abs(key.hashValue) % buckets.count
    }
    
}


class HashNode<Key, Value> {
    
    var key: Key
    var value: Value
    var nextNode: HashNode?
    
    init(key: Key, value: Value, nextNode: HashNode? = nil) {
        self.key = key
        self.value = value
        self.nextNode = nextNode
    }
    
}

