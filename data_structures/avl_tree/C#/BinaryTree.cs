using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree
{
    /// <summary>
    /// This class is implmentation of the BinaryTree data structure. It serves as the foundation
    /// of the more advanced form of binary trees. This class contains knowledge of the Root 
    /// which is the initial node within the tree and can be used as the starting point to navigate
    /// to all other nodes within the tree. This implementation also contains a number of virtual 
    /// functions which are used to interact with the nodes the tree holds. These are marked as 
    /// virtual functions as they will be improved within the children of this class as they begin 
    /// to improve insertion interaction function will also benefit from these improvements. The 
    /// class also contains a number of traversal functions in addition to tree statistics.
    /// </summary>
    /// <typeparam name="TKey">Type of Key must implemented IComparable.</typeparam>
    /// <typeparam name="TValue">Type of Value must implemented IComparable.</typeparam>
    public class BinaryTree<TKey, TValue> 
        where TKey : IComparable<TKey> 
        where TValue : IComparable<TValue>
    {
        /// <summary>
        /// The initial node within the tree. This provides access to entirety of tree.
        /// </summary>
        public Node<TKey, TValue> Root;

        /// <summary>
        /// Construct a new binary tree with null Root.
        /// </summary>
        public BinaryTree() { Root = null; }

        /// <summary>
        /// Construct a new binary tree with Root containg the following Key/Value node pair.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public BinaryTree(TKey Key, TValue Value) { Root = new Node<TKey, TValue>(Key, Value); }

        /// <summary>
        /// Create a new node within the binary tree with the supplied Key and Value. Actual 
        /// implementation is left to the children of this class.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public virtual void Create(TKey Key, TValue Value) { }

        /// <summary>
        /// Fetch a value stored within the binary tree with a node identified by the supplied Key.
        /// The function works by iterating over an inOrder traversal of the tree comparing each 
        /// node until either the node being searched for has been found and returned or no node 
        /// has been found. 
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <returns>Value that corresponds to the supplied Key.</returns>
        public virtual TValue Get(TKey Key)
        {
            foreach(Node<TKey, TValue> node in inOrder(Root))
            {
                if (node.Key.CompareTo(Key) == 0) return node.Value;
            }
            return default(TValue);
        }

        /// <summary>
        /// Edit a pre-existing node within the binary tree with the supplied Key and Value. Actual 
        /// implementation is left to the children of this class.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node about to be updated.</param>
        /// <param name="Value">Actual data being used to update the node.</param>
        public virtual void Edit(TKey Key, TValue Value) { }

        /// <summary>
        /// Delete a pre-existing node within the binary tree with the supplied Key. Actual 
        /// implementation is left to the children of this class.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node about to be deleted.</param>
        public virtual void Delete(TKey Key) { }

        /// <summary>
        /// Traverse the entire searching for the node in question, returning a boolean stating if 
        /// the tree contains that node.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node being located.</param>
        /// <returns></returns>
        public virtual bool Contains(TKey Key)
        {
            foreach (Node<TKey, TValue> node in inOrder(Root))
            {
                if (node.Key.CompareTo(Key) == 0) return true;
            }
            return false;
        }

        /// <summary>
        /// InOrder traversal of the binary tree. Construct a list of each node visited protecting 
        /// the order taken.
        /// </summary>
        /// <returns>List of keys that can be used to identify an indivdual node.</returns>
        public List<TKey> InOrder()
        {
            List<TKey> keys = new List<TKey>();
            foreach(Node<TKey, TValue> node in inOrder(Root))
            {
                keys.Add(node.Key);
            }
            return keys;
        }

        /// <summary>
        /// Recursive function to implement tree traversal with each visited node being yield upon 
        /// and returning straight back to current position within the tree traversal. 
        /// </summary>
        /// <param name="node">Current node being visited.</param>
        /// <returns>IEnumerable object holding the current node visited.</returns>
        private IEnumerable<Node<TKey, TValue>> inOrder(Node<TKey, TValue> node)
        {
            if(node != null)
            {
                foreach (Node<TKey, TValue> leftNode in inOrder(node.Left))
                {
                    yield return leftNode;
                }
                yield return node;
                foreach (Node<TKey, TValue> rightNode in inOrder(node.Right))
                {
                    yield return rightNode;
                }
            }
            else
            {
                yield break;
            }
        }

        /// <summary>
        /// PreOrder traversal of the binary tree. Construct a list of each node visited protecting 
        /// the order taken.
        /// </summary>
        /// <returns>List of keys that can be used to identify an indivdual node.</returns>
        public List<TKey> PreOrder()
        {
            List<TKey> keys = new List<TKey>();
            foreach (Node<TKey, TValue> node in preOrder(Root))
            {
                keys.Add(node.Key);
            }
            return keys;
        }

        /// <summary>
        /// Recursive function to implement tree traversal with each visited node being yield upon 
        /// and returning straight back to current position within the tree traversal. 
        /// </summary>
        /// <param name="node">Current node being visited.</param>
        /// <returns>IEnumerable object holding the current node visited.</returns>
        private IEnumerable<Node<TKey, TValue>> preOrder(Node<TKey, TValue> node)
        {
            if (node != null)
            {
                yield return node;
                foreach (Node<TKey, TValue> leftNode in preOrder(node.Left))
                {
                    yield return leftNode;
                }
                foreach (Node<TKey, TValue> rightNode in preOrder(node.Right))
                {
                    yield return rightNode;
                }
            }
            else
            {
                yield break;
            }
        }

        /// <summary>
        /// PreOrder traversal of the binary tree. Construct a list of each node visited protecting 
        /// the order taken.
        /// </summary>
        /// <returns>List of keys that can be used to identify an indivdual node.</returns>
        public List<TKey> PostOrder()
        {
            List<TKey> keys = new List<TKey>();
            foreach (Node<TKey, TValue> node in postOrder(Root))
            {
                keys.Add(node.Key);
            }
            return keys;
        }

        /// <summary>
        /// Recursive function to implement tree traversal with each visited node being yield upon 
        /// and returning straight back to current position within the tree traversal. 
        /// </summary>
        /// <param name="node">Current node being visited.</param>
        /// <returns>IEnumerable object holding the current node visited.</returns>
        private IEnumerable<Node<TKey, TValue>> postOrder(Node<TKey, TValue> node)
        {
            if (node != null)
            {
                foreach (Node<TKey, TValue> leftNode in postOrder(node.Left))
                {
                    yield return leftNode;
                }
                foreach (Node<TKey, TValue> rightNode in postOrder(node.Right))
                {
                    yield return rightNode;
                }
                yield return node;
            }
            else
            {
                yield break;
            }
        }

        /// <summary>
        /// Node population within the tree. 
        /// </summary>
        /// <returns>Number of nodes contained within this tree.</returns>
        public int GetNodeCount()
        {
            return getNodeCount(Root);
        }

        /// <summary>
        /// Recursive function to calculate number of node within the tree.
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private int getNodeCount(Node<TKey, TValue> node)
        {
            return node != null ? 1 + getNodeCount(node.Left)
                + getNodeCount(node.Right) : 0;
        }
        
        /// <summary>
        /// Get the height of the tree. Largest distance between leaf and Root.
        /// </summary>
        /// <returns>Integer value outlining the height of the tree.</returns>
        public int GetHeight()
        {
            return getHeight(Root);
        }

        /// <summary>
        /// Recursive function calculates the height of the tree.
        /// </summary>
        /// <param name="node">Current node visited.</param>
        /// <returns>Current height of visited node.</returns>
        protected int getHeight(Node<TKey, TValue> node)
        {
            return node == null ? 0 : 1 + Math.Max(getHeight(node.Left),
                getHeight(node.Right));
        }
    }
}
