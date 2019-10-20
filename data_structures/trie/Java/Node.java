/**
 * @author Lucas Gomes Dantas
 * @date June the 18th, 2018
 * My implementation of a Node for a Trie, developed while studying at UFRN, Brazil.
 */

import java.util.HashMap;
import java.util.Map;

/**
 * The type Node.
 */
public class Node
{
    /**
     * Data that the node will hold. For this kind of Trie, it will be only single characteres.
     */
    String data;

    /**
     * Reference to the "Parent" Node.
     */
    Node parent;

    /**
     * Flag that indicates if this Node is the end of a word.
     */
    boolean endWord;

    private Map<String, Node> children;

    /**
     * Returns all the children of this Node, or forks.
     *
     * @return the children
     */
    public Map<String, Node> getChildren() { return children; }

    /**
     * Instantiates a new Node.
     *
     * @param data The value that will be stored at the Node.
     */
    public Node(String data)
    {
        this.data = data;
        parent = null;
        endWord = false;
        children = new HashMap<>();
    }

    /**
     * Checks if this Node has a child with the given key.
     *
     * @param key The key to be checked
     * @return True if there's any child with the given key, false otherwise
     */
    public boolean hasChild(String key) { return children.containsKey(key); }

    /**
     * Receives a key and returns to the client the child Node that matches the key.
     *
     * @param key The child's key
     * @return Node with a matching key
     */
    public Node getChild(String key) { return children.get(key); }

    /**
     * Adds a new child to this Node.
     *
     * @param key  The new child's key
     * @param child The Node to be added as child
     */
    public void addChild(String key, Node child) { children.put(key, child); }

    /**
     * Verifies if this Node has any child.
     *
     * @return True if it has, false otherwise.
     */
    public boolean hasChildren() { return !children.isEmpty(); }

    /**
     * Remove child with a given key from this Node.
     *
     * @param key Key of the child to be removed.
     */
    public void removeChild(String key) { children.remove(key); }

    /**
     * Verifies if this Node has multiple children, i.e. its a fork.
     *
     * @return True if has, false otherwise.
     */
    public boolean hasFork() { return children.size() > 1; }

    public String toString() { return data; }
}