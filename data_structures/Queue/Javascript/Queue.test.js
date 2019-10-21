// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const Queue = require("./queue");

describe("Queue [data structure]", () => {
  const maxSize = 3;
  const q = new Queue(maxSize);

  afterEach(() => {
    q.clear();
  });

  it("should empty in the begining queue", () => {
    expect(q.count()).toEqual(0);
  });

  it("should return a message if dequeued from the empty queue", () => {
    let msg = "No element is present in the queue to dequeue.";
    expect(q.dequeue()).toEqual(msg);
  });

  it("should insert element in the queue", () => {
    q.enqueue(1);
    q.enqueue(5);
    expect(q.count()).toEqual(2);
  });

  it("should return the message if the capacity is full", () => {
    let msg =
      "Max capacity already reached. Remove element before adding a new one.";
    let capacity = q.getCapacity();
    while (capacity) {
      q.enqueue(capacity--);
    }
    expect(q.enqueue(1)).toEqual(msg);
  });

  describe("Pop feature of Queue", () => {
    beforeEach(() => {
      // enter 3 elements
      q.enqueue(1);
      q.enqueue(2);
      q.enqueue(3);
    });

    afterEach(() => {
      q.clear();
    });

    it("should pop the element from the queue", () => {
      q.dequeue();
      expect(q.count()).toEqual(2);
    });

    it("should pop the element from the front", () => {
      q.dequeue();
      expect(q.peek()).not.toEqual(1);
    });

    it("should clear the queue", () => {
      q.clear();
      expect(q.count()).toEqual(0);
    });
  });
});
