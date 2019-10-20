public class InternalNode extends Node {
    Node left;
    Node right;

    public InternalNode(Node left, Node right) {
        super(left.frequency + right.frequency);
        this.left = left;
        this.right = right;
    }

    @Override
    void buildCode(String code) {
        super.buildCode(code);
        left.buildCode(code + "0");
        right.buildCode(code + "1");
    }
}
