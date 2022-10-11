
from collections import deque


class Deque:
    def __init__(self):
        self.dp = deque([])

    def insetion_back(self, data):
        self.dq.append(data)
        pass

    def insetion_front(self, data):
        self.dp.appendleft(data)

    def removea_back(self):
        self.dp.pop()

    def remove_front(self):
        self.dp.popleft()

    def print_dequeue(self):
        print(self.dp)


dq = Deque()
dq.insetion_front(1)
dq.insetion_back(2)
dq.print_dequeue()
dq.insetion_front(0)
dq.remove_front()
dq.print_dequeue()
dq.removea_back()
dq.print_dequeue()
