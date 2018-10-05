import java.util.HashMap;

class TrieNode {
    char letter;
    HashMap<Character, TrieNode> nodes;
    public TrieNode(char letter) {
        this.letter = letter;
        nodes = new HashMap<>();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        TrieNode trieNode = (TrieNode) o;

        if (letter != trieNode.letter) return false;
        if (nodes.size() != trieNode.nodes.size()) return false;
        for(char c : nodes.keySet()){
            return trieNode.contains(c) && nodes.get(c).equals(trieNode.nodes.get(c));
        }
        return true;
    }

    @Override
    public int hashCode() {
        int result = letter;
        result = 31 * result + (nodes != null ? nodes.hashCode() : 0);
        result = 31 * result + (nodes != null ? nodes.hashCode() : 0);
        return result;
    }

    public TrieNode add(TrieNode node){
        if(nodes.containsKey(node.letter)) return nodes.get(node.letter);
        else {
            nodes.put(node.letter, node);
            return node;
        }
    }

    public boolean contains(char letter){
        return nodes.containsKey(letter);
    }
}

public class Trie {
    // Special Word Ending Character
    private char endingWordCharacter = '~';
    private TrieNode root;

    public Trie() {
        root = new TrieNode(endingWordCharacter);
    }

    public void insert(String word) {
        word = word + endingWordCharacter;
        TrieNode tail = null;
        for (int i = 0; i < word.length(); i++) {
            if (i == 0) {
                tail = root.add(new TrieNode(word.charAt(i)));
            } else {
                tail = tail.add(new TrieNode(word.charAt(i)));
            }
        }
    }

    public boolean search(String word) {
        return startsWith(word + endingWordCharacter);
    }

    public boolean startsWith(String prefix) {
        TrieNode prev = null;
        for (int i = 0; i < prefix.length(); i++) {
            if (i == 0) {
                if (!root.contains(prefix.charAt(i))) {
                    return false;
                } else {
                    prev = root.nodes.get(prefix.charAt(i));
                }
            } else {
                if (!prev.contains(prefix.charAt(i))) {
                    return false;
                } else {
                    prev = prev.nodes.get(prefix.charAt(i));
                }
            }
        }
        return true;
    }

}
