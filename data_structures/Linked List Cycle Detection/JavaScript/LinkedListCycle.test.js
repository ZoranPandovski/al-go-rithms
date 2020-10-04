const LinkedList = require("./LinkedListCycle");
const { Node, CycleDetector } = LinkedList;

describe("CycleDetector", () => {
	let head;
	let tail;

	beforeEach(() => {
		const a = new Node(1);
		const b = new Node(2);
		const c = new Node(3);
		const d = new Node(4);
		const e = new Node(5);
		const f = new Node(6);

		a.next = b;
		b.next = c;
		c.next = d;
		d.next = e;
		e.next = f;
		f.next = null;

		head = a;
		tail = f;
	});

	test("Linked List with cycle", () => {
		tail.next = head;
		expect(CycleDetector(head)).toBe(true);
	});

	test("Self linked Node", () => {
		head.next = head;
		expect(CycleDetector(head)).toBe(true);
	});

	test("Linked List without cycle", () => {
		expect(CycleDetector(head)).toBe(false);
	});

	test("Null value on head", () => {
		expect(CycleDetector(null)).toBe(false);
	});

	test("Null value on head.next", () => {
		head.next = null;
		expect(CycleDetector(head)).toBe(false);
	});
});
