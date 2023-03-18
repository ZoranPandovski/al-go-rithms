import heapq

class PriorityQueue:
    def __init__(self):
        self._heap = []

    def push(self, priority, item):
        heapq.heappush(self._heap, (priority, item))

    def pop(self):
        priority, item = heapq.heappop(self._heap)
        return item

    def is_empty(self):
        return len(self._heap) == 0

    def size(self):
        return len(self._heap)

    def top(self):
        if self.is_empty():
            raise Exception("Priority queue is empty")
        priority, item = self._heap[0]
        return item
