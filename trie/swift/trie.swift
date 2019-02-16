import Foundation

class TrieNode {
    private var charMap: [Character: TrieNode]
    public var size: Int
    
    init() {
        charMap = [:]
        size = 0
    }
    
    public func add(c: Character) {
        if let _ = self.charMap[c] {
            // do nothing if exists
        } else {
            self.charMap[c] = TrieNode()
        }
    }
    
    public func getChild(c: Character) -> TrieNode? {
        return self.charMap[c]
    }
}

class Trie {
    private var root: TrieNode
    
    init() {
        root = TrieNode()
    }
    
    init(words: [String]) {
        root = TrieNode()
        for word in words {
            self.add(word: word)
        }
    }
    
    public func add(word: String) {
        var current = root
        for c in word {
            current.add(c: c)
            current = current.getChild(c: c)!
            current.size = current.size + 1
        }
    }
    
    public func find(prefix: String) -> Int {
        var current = root
        for c in prefix {
            if let childNode = current.getChild(c: c) {
                current = childNode
            } else {
                return 0
            }
        }
        
        return current.size
    }
}

