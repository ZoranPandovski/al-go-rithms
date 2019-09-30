/**
 * @author Lucas Gomes Dantas
 * @date June the 18th, 2018
 * My implementation of a simple Trie, developed while studying at UFRN, Brazil.
 */

import java.util.ArrayList;

/**
 * The type Trie.
 */
public class Trie
{
    private Node root;

    /**
     * Instantiates a new Trie with root being an empty string.
     */
    public Trie() { root = new Node(""); }

    /**
     * Receives word from the client, breaks it down to chars and inserts the new word on the Trie.
     *
     * @param data New word to be inserted.
     */
    public void insert(String data)
    {
        String[] chars = data.split("");
        Node current = root;
        int count = 0;
        for (String e : chars)
        {
            // Create a new node with the character and checks if he already exists on trie
            Node newNode = new Node(e);
            if ( ! current.hasChild(e) )
            {
                current.addChild(e, newNode);
                newNode.parent = current;
            }
            // Advances node
            current = current.getChild(e);
            // If it is the last char of the string, it needs to have its flag active
            if ( count++ == chars.length - 1 ) { newNode.endWord = true; }
        }
    }

    /**
     * Search if a given word exists on the Trie.
     *
     * @param word Word to be searched
     * @return True if the word exists, false otherwise.
     */
    public boolean search(String word)
    {
        String[] chars = word.split("");
        int count = 0;
        Node current = root;
        for (String e : chars)
        {
            if( current.hasChild(e) )
            {
                current = current.getChild(e);
                count++;
            }
        }
        /* Saying that a word exists on Trie means that all of its chars are stored and the node
           is flagged as end of the word. */
        return (count == chars.length) && (current.endWord);
    }

    /**
     * Print all the words that are stored on this Trie.
     */
    public void print()
    {
        ArrayList<String> words = new ArrayList<>();
        for ( String e : getWords(root, words, "") ) { System.out.println(e); }
    }

    /**
     * Receives a prefix (it does not matter if the prefix is a full word) and searchs for all words
     * derived from this prefix.
     *
     * @param prefix The prefix which all words must contain
     * @return wordsFromPrefix An ArrayList with all the words derived from the prefix
     */
    public ArrayList<String> getWordsFromPrefix(String prefix)
    {
        Node current = searchNodeByPrefix(prefix);
        if (current != null)
        {
            ArrayList<String> wordsFromPrefix = new ArrayList<>();

            // Gets all the words that begin with the given prefix
            wordsFromPrefix = getWords(current, wordsFromPrefix, "");

            // The words will come without the prefix, so in this loop we add the prefix to them
            for (int i = 0; i < wordsFromPrefix.size(); i++)
            {
                String word = prefix + wordsFromPrefix.get(i);
                wordsFromPrefix.set(i, word);
            }

            // And now we add the prefix itself to the list
            wordsFromPrefix.add(prefix);

            return wordsFromPrefix;
        }
        return null;
    }

    /**
     * Delete a given word from the Trie, verifying all four cases of deletion.
     * Case 1 - The word is not on the Trie;
     * Case 2 - The node where the word ends is a leaf;
     * Case 3 - The node where the word ends is not a leaf;
     * Case 4 - The node's parents have a fork
     *
     * @param word The word to be deleted from the Trie
     * @return True if the word was deleted, false otherwise
     */
    public boolean delete(String word)
    {
        Node current = searchNodeEnd(word);

        // The word is not on the trie and we cannot delete her
        if (current == null) { return false; }

        /*
            Now there are three cases we must check

            1 - Node does not have any children
            2 - Node has more children
            3 - Nodes parents have children
        */

        // Case 2 is easier to deal with, so we begin with it
        if ( current.hasChildren() ) { current.endWord = false; return true; }

        // Case 1 and 3 are quite similar on implementation, so now is their turn
        while ( current != root )
        {
            // Checks if parent has more children (fork) - if so, stops deleting there
            if ( current.parent.hasFork() ) { current.parent.removeChild(current.data); return true; }

            // Removes child from the trie
            if ( !current.hasChildren() ) { current.parent.removeChild(current.data); }

            current = current.parent;
        }
        return true;
    }

    private Node searchNodeByPrefix(String prefix)
    {
        String[] chars = prefix.split("");
        Node current = root;
        int count = 0;
        for (String e : chars)
        {
            if ( current.hasChild(e) )
            {
                current = current.getChild(e);
                count++;
            }
        }
        return count == chars.length ? current : null;
    }

    private Node searchNodeEnd(String prefix)
    {
        String[] chars = prefix.split("");
        Node current = root;
        int count = 0;
        for (String e : chars)
        {
            if ( current.hasChild(e) )
            {
                current = current.getChild(e);
                count++;
            }
        }
        return count == chars.length && current.endWord ? current : null;
    }

    private ArrayList<String> getWords(Node current, ArrayList<String> words, String data)
    {
        for ( Node child : current.getChildren().values() )
        {
            if (child.endWord) { words.add(data + child.data); }
            if ( child.hasChildren() ) { getWords(child, words, data + child.data); }
        }
        return words;
    }
}