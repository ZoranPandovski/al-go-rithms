interface ISet<T> {
	readonly size: number;
	add(value: T): ISet<T>;
	delete(value: T): ISet<T>;
	has(value: T): boolean;
	[Symbol.iterator](): IterableIterator<T>;
}

class SetImpl<T> implements ISet<T> {
	private _size: number = 0;
	private _set: Array<T> = [];
	private _currentIndex = 0;

	get size(): number {
		return this._size;
	}

	public add(value: T): ISet<T> {
		if (!this._set.includes(value))
			this._set.push(value);

		return this;
	}

	public delete(value: T): ISet<T> {
		this._set.filter(element => element !== value);

		return this;
	}

	public has(value: T): boolean {
		return this._set.includes(value);
	}

	public next(): IteratorResult<T> {
		if (this._currentIndex < this._set.length) {
			let currentIndex = this._currentIndex;
			this._currentIndex++;
			return { done: false, value: this._set[currentIndex] }
		}

		return { done: true, value: undefined };
	}

	[Symbol.iterator](): IterableIterator<T> {
		return this;
	}
}

let testSet: ISet<number> = new SetImpl();
testSet.add(1);
testSet.add(2);
testSet.add(3);

for (let element of testSet) {
	console.log(element);
}
