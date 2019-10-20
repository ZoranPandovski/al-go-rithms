using System;

namespace data_structures.Stack.CSharp
{
    public class Stack
    {
        private int _indexRunner;
        private object[] _storage;
        private const int LAST_INDEX = -1;

        public Stack(int length)
        {
            _indexRunner = LAST_INDEX;
            _storage = new object[length];
        }

        public void Push(object obj)
        {
            if (_indexRunner == _storage.Length - 1) { throw new OverflowException("stack is overflow"); }
            _storage[++_indexRunner] = obj;
        }

        public object Pop()
        {
            if (_indexRunner == LAST_INDEX) { throw new OverflowException("nothing in stack right now"); }
            return _storage[_indexRunner--];
        }

        public int Size() => _indexRunner + 1;
    }
}
