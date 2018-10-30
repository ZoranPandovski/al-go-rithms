import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Huffman {

    public static void main(String[] args) throws FileNotFoundException {
        long startTime = System.currentTimeMillis();
        new Huffman().run();
        long finishTime = System.currentTimeMillis();
        System.out.println(finishTime - startTime + "ms");
    }

    private void run() throws FileNotFoundException {
        Scanner input = new Scanner(new File("input.txt"));
        StringBuilder s = new StringBuilder();
        while (input.hasNextLine()) {
            s.append(input.nextLine()).append("\n");
        }

        Map<Character, Integer> charCount = charCounter(s.toString());
        printTable(charCount);

        Map<Character, LeafNode> charNodes = new HashMap<>();

        Node root = createHuffmanTree(charNodes, charCount);

        if (charCount.size() == 1) {
            root.code = "0";
        } else {
            root.buildCode("");
        }
        StringBuilder encodedString = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            encodedString.append(charNodes.get(c).code);
        }

        System.out.println(encodedString);
        FileHelper.writeToFile("encoded.txt", encodedString.toString());
        String decodedString = decode(encodedString.toString(), charNodes);
        System.out.println(decodedString);
        FileHelper.writeToFile("decoded.txt", decodedString);
    }

    private String decode(String encodedString, Map<Character, LeafNode> charNodes) {
        StringBuilder code = new StringBuilder();
        StringBuilder decodedString = new StringBuilder();
        for (char c : encodedString.toCharArray()) {
            code.append(c);
            for (Map.Entry<Character, LeafNode> entry : charNodes.entrySet()) {
                if (code.toString().equals(entry.getValue().code)) {
                    decodedString.append(entry.getValue().symbol);
                    code.setLength(0);
                }
            }
        }
        return decodedString.toString();
    }

    private Map<Character, Integer> charCounter(String s) {
        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            if (charCount.containsKey(c)) {
                charCount.put(c, charCount.get(c) + 1);
            } else {
                charCount.put(c, 1);
            }
        }
        return charCount;
    }

    private void printTable(Map<?, ?> map) {
        for (Map.Entry<?, ?> entry : map.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }

    private Node createHuffmanTree(Map<Character, LeafNode> charNodes, Map<Character, Integer> charCount) {
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
        for (Map.Entry<Character, Integer> entry : charCount.entrySet()) {
            LeafNode node = new LeafNode(entry.getKey(), entry.getValue());
            charNodes.put(entry.getKey(), node);
            priorityQueue.add(node);
        }
        while (priorityQueue.size() > 1) {
            Node first = priorityQueue.poll();
            Node second = priorityQueue.poll();
            InternalNode node = new InternalNode(first, second);
            priorityQueue.add(node);
        }
        return priorityQueue.poll();
    }

}
