class Node {
	constructor(value) {
		this.value = value;
		this.next = null;
	}
}

function CycleDetector(head) {
	if (!head || !head.next) {
		return false;
	}

	let slow = head;
	let fast = head.next;

	while (fast.next && fast.next.next) {
		slow = slow.next;
		fast = fast.next.next;

		if (slow === fast) {
			return true;
		}
	}

	return false;
}

module.exports = { Node, CycleDetector };
