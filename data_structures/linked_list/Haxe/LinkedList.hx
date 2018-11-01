class LinkedList<T> {

    /**
     * The length of `this` list.
     */
    public var length(default, null):Int;

    /**
     * The first item in the list or null
     */
    public var first(get, never):Null<T>;
    inline function get_first():Null<T> {
        return head == null ? null : head.item;
    }

    /**
     * The last item in the list or null
     */
    public var last(get, never):Null<T>;
    inline function get_last():Null<T> {
        return tail == null ? null : tail.item;
    }

    var head:ListNode<T>;
    var tail:ListNode<T>;

    public function new() {
        length = 0;
    }

    /**
     * Adds given item to the end of the list
     * @param item 
     * @return T
     */
    public function append(item:T):T {
        var n = new ListNode(item, null);
        if(head == null)    head = n;
        else                tail.next = n;

        tail = n;
        length++;

        return item;
    }

    /**
     * Adds given item to the beginning of the list
     * @param item 
     * @return T
     */
    public function prepend(item:T):T {
        var n = new ListNode(item, head);
        head = n;
        if(tail == null)    tail = n;
        length++;

        return item;
    }

    /**
     * Checks if list has no items
     * @return Bool
     */
    public inline function isEmpty():Bool {
        return length == 0;
    }

    /**
     * Clears the list
     */
    public inline function clear() {
        head = tail = null;
        length = 0;
    }

    /**
     * Gets item at given index or null
     * @param index 
     * @return Null<T>
     */
    public function getItemAt(index:Int):Null<T> {
        var curr = head;
        var cntr = 0;
        while (curr != null) {
            if(cntr++ == index) return curr.item;
            else                curr = curr.next;
        }
        return null;
    }

    /**
     * Removes given item from the list and returns true if it was successfully removed
     * @param item 
     * @return Bool
     */
    public function remove(item:T):Bool {
        var curr = head;
        var prev:ListNode<T> = null;
        while(curr != null) {
            if(curr.item == item) {
                if(prev == null)    head = curr.next;
                else                prev.next = curr.next;
                
                if(tail == curr)    tail = prev;
                length--;
                return true;
            }
            prev = curr;
            curr = curr.next;
        }
        return false;
    }

    /**
     * Removes the first item from the list and returns that item.
     * @return Null<T>
     */
    public function shift():Null<T> {
        if(head == null)    return null;

        var item = head.item;
        head = head.next;

        if(head == null)    tail = null;

        length--;
        return item;
    }

    /**
     * Calls `fn` for each item of the list.
     * @param fn function with two arguments, where first arg is an item, second is an index of the item
     */
    public function iterate(fn:T->Int->Void) {
        var curr = head;
        var i = 0;
        while(curr != null) {
            fn(curr.item, i++);
            curr = curr.next;
        }
    }
    
}

private class ListNode<T> {

    public var item:T;
	public var next:ListNode<T>;

    public function new(item:T, next:ListNode<T>){
        this.item = item;
        this.next = next;
    }
}