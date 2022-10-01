interface Queue<T> {
	readonly length: number;
	enqueue(value: T): number;
	dequeue(): T | undefined;
	peek(): T | undefined;
	isEmpty(): boolean;
	[Symbol.iterator](): IterableIterator<T>;
}

class QueueImpl<T> implements Queue<T> {
	private _store: Array<T> = [];

	get length(): number {
		return this._store.length;
	}

	public enqueue(value: T): number {
		this._store.push(value);

		return this._store.length;
	}

	public dequeue(): T | undefined {
		if (this.isEmpty()) return undefined;

		return this._store.shift();
	}

	public peek(): T | undefined {
		if (this.isEmpty()) return undefined;

		return this._store[0];
	}

	public isEmpty() {
		return this._store.length === 0;
	}

	public next(): IteratorResult<T> {

		if (!this.isEmpty()) {
			return { done: false, value: this.dequeue() as any as T }
		}

		return { done: true, value: undefined };
	}

	[Symbol.iterator](): IterableIterator<T> {
		return this;
	}
}

let testQueue: Queue<number> = new QueueImpl();
console.log(`The queue is currently ${testQueue.length} items long`);
testQueue.enqueue(3);
testQueue.enqueue(4);
testQueue.enqueue(5);
console.log(`The queue is currently ${testQueue.length} items long`);
console.log('\nThe items in the queue are:');
for (let item of testQueue) {
	console.log(item);
}
console.log(`\nThe queue is now ${testQueue.isEmpty() ? "empty" : "not empty"}`);
