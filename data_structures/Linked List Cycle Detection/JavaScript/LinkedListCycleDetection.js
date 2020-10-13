
function ListNode(val) {
    this.val = val;
    this.next = null;
}


/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if(!head) {
        return false;
    }
    let ptr1 = head;
    let ptr2 = head.next;
    let isCycle = true;
    while(ptr1 && ptr2) {
        if(ptr1 === ptr2) {
            break;
        }
        ptr1 = ptr1.next;
        ptr2 = ptr2.next ? ptr2.next.next : ptr2.next;
    }
    if(!ptr1 || !ptr2) {
        isCycle = false;
    }
    return isCycle;
};

var run = function() {
    let a = new ListNode(1);
    let b = new ListNode(2);
    let c = new ListNode(3);
    let d = new ListNode(4);
    let e = new ListNode(5);

    a.next = b;
    b.next = c;
    c.next = d;
    d.next = e;
    e.next = b;

    return hasCycle(a);
}