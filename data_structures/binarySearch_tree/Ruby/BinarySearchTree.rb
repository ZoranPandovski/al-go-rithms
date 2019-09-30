class BinarySearchTree

  attr_reader :head

  def initialize
    @head = nil
  end

  def append(n)
    return @head = Node.new(n) unless @head
    @head.append(n)
  end

  def search(n)
    return nil unless @head

    current = @head
    loop do
      return current if current.nil? || current.value == n
      current = (n < current.value) ? current.left : current.right
    end
  end

  def print_inorder
    @head.inorder
  end

  def print_preorder
    @head.preorder
  end

  def print_postorder
    @head.postorder
  end

  private

  Node = Struct.new(:value, :left, :right) do
    def append(n)
      if(n < value)
        return self.left = Node.new(n) unless left
        left.append(n)
      else
        return self.right = Node.new(n) unless right
        right.append(n)
      end
    end

    def inorder
      left.inorder if left
      puts value
      right.inorder if right
    end

    def preorder
      puts value
      left.inorder if left
      right.inorder if right
    end

    def postorder
      left.inorder if left
      right.inorder if right
      puts value
    end

    def to_s
      value.to_s
    end
  end
end
