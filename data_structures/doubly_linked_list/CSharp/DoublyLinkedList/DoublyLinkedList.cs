using System;
using System.Collections;
using System.Collections.Generic;

namespace DoublyLinkedList
{
    public class DoublyLinkedList<T> : IEnumerable<T>
    {
        class Node
        {
            public T Data { get; set; }
            public Node Next { get; set; }
            public Node Previous { get; set; }

            public Node(T data)
            {
                Data = data;
            }
        }

        private Node _head, _tail;
        public T Head => _head == null ? throw new NullReferenceException() : _head.Data;
        public T Tail => _tail == null ? throw new NullReferenceException() : _tail.Data;
        public bool IsEmpty { get { return Count > 0 ? false : true; } }
        public int Count { get; private set; } = 0;

        public DoublyLinkedList() { }

        public DoublyLinkedList(IEnumerable<T> items)
        {
            foreach (var item in items)
            {
                AddTail(item);
            }
        }

        public void AddHead(T item)
        {
            var node = new Node(item);
            
            if (_head == null && _tail == null)
            {
                _head = node;
                _tail = node;
                Count += 1;
            }
            else
            {
                node.Next = _head;
                _head.Previous = node;
                Count += 1;
            }
            _head = node;
        }

        public void AddTail(T item)
        {
            var node = new Node(item);

            if (_tail == null && _head == null)
            {
                _head = node;
                _tail = node;
                Count += 1;
            }
            else
            {
                node.Previous = _tail;
                _tail.Next = node;
                Count += 1;
            }
            _tail = node;
        }

        public T RemoveHead()
        {
            if (_head == null) return default;

            var temp = _head.Next;
            _head = _head.Next;

            if (_head != null) _head.Previous = null;

            Count -= 1;

            if (temp == null) return default;
            return temp.Data;
        }

        public T RemoveTail()
        {
            if (_tail == null) return default;

            var temp = _tail.Previous;
            _tail = _tail.Previous;

            if (_tail != null) _tail.Next = null;

            Count -= 1;

            if (temp == null) return default;
            return temp.Data;
        }

        public bool Find(T item)
        {
            if (_head == null || _tail == null) return false;

            var node = _head;

            while (node.Data.Equals(item) == false)
            {
                if (node.Next == null)
                    return false;
                node = node.Next;
            }
            return true;
        }

        public bool Remove(int index)
        {
            if (_head == null || _tail == null) return false;

            var node = _head;

            for (int i = 0; i < Count; i++)
            {
                if (i == index) break;
                node = node.Next;
            }
            // Remove the node
            if (node == null) return false;
            bool isRemoved = NodeAwareRemove(node);
            return isRemoved;
        }

        private bool NodeAwareRemove(Node node)
        {
            if (node.Next != null && node.Previous != null)
            {
                // In between nodes
                node.Previous.Next = node.Next;
                node.Next.Previous = node.Previous;
                Count -= 1;
                return true;
            }

            if (node.Next != null && node.Previous == null)
            {
                // Head node
                RemoveHead();
                return true;
            }

            if (node.Previous != null && node.Next == null)
            {
                // Tail node
                RemoveTail();
                return true;
            }

            if (node.Next == null && node.Previous == null)
            {
                // Only node
                _head = null;
                _tail = null;
                Count -= 1;
                return true;
            }
            return false;
        }

        public int RemoveAll(T item)
        {
            if (_head == null || _tail == null) return -1;

            var node = _head;
            int numberRemoved = 0;

            while (node != null)
            {
                if (node.Data.Equals(item))
                {
                    if (NodeAwareRemove(node)) numberRemoved += 1;
                }
                node = node.Next;
            }
            return numberRemoved;
        }

        public T GetIndex(int index)
        {
            if (index < 0) throw new IndexOutOfRangeException();
            if (index > Count) throw new IndexOutOfRangeException();
            if (index == 0) return _head.Data;

            var temp = _head;

            for (int i = 0; i < Count; i++)
            {
                if (i == index) break;
                temp = temp.Next;
            }

            return temp.Data;
        }

        public bool SetIndex(int index, T item)
        {
            if (index < 0) throw new IndexOutOfRangeException();
            if (index > Count) throw new IndexOutOfRangeException();
            if (index == 0) _head.Data = item;

            var temp = _head;

            for (int i = 0; i < Count; i++)
            {
                if (i == index) break;
                temp = temp.Next;
            }

            temp.Data = item;
            return true;
        }

        public object this[int i]
        {
            get { return GetIndex(i); }
            set { SetIndex(i, (T)value); }
        }

        public IEnumerator<T> GetEnumerator()
        {
            var pointer = _head;
            while (pointer != null)
            {
                yield return pointer.Data;
                pointer = pointer.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}