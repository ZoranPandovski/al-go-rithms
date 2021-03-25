class Stack:
  def __init__(self, data=[]):
    self.Stack = data
  def __repr__(self):
    return self.Stack
  def push(self, item):
    self.stack.append(item)
  def pop(self):
    self.stack.pop(-1)
  def peek(self):
    return self.stack[-1]
  def isEmpty(self):
    return len(self.Stack) > 0
