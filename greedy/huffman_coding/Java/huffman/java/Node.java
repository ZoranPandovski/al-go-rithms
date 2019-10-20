public class Node implements Comparable<Node> {
    final int frequency;
    String code;

    public Node(int frequency) {
        this.frequency = frequency;
    }

    void buildCode(String code) {
        this.code = code;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(frequency, o.frequency);
    }
}
