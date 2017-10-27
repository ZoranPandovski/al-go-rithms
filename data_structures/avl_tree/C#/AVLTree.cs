using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree
{
    /// <summary>
    /// This class has the role of implementing an AVL tree. This is a binary search tree that
    /// auto-balances itself in order to improve search operations. 
    /// </summary>
    /// <typeparam name="TKey">Type of Key must implemented IComparable.</typeparam>
    /// <typeparam name="TValue">Type of Value must implemented IComparable.</typeparam>
    public class AVLTree<TKey, TValue> : BSTree<TKey, TValue>
        where TKey : IComparable<TKey> 
        where TValue : IComparable<TValue>
    {
        /// <summary>
        /// Create an AVLTree with a null Root.
        /// </summary>
        public AVLTree() : base() { }

        /// <summary>
        /// Construct a new AVLTree with Root containg the following Key/Value node pair.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public AVLTree(TKey Key, TValue Value) : base(Key, Value) { }

        /// <summary>
        /// Create a new node with the provided key and value in the next avaliable place.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public override void Create(TKey Key, TValue Value)
        {
            create(Key, Value, ref Root);
        }

        /// <summary>
        /// Recursively traverse the tree looking for an appropriate place within the tree for the
        /// new node. The place within the tree is defined by the result of a series of comparisons
        /// against each visited node. Once the node has been inserted the balance factor of each
        /// node must be recalculated. Once the new balance factor has been determined for each
        /// node any balance factor that exceeds limits will have to be rotated in order
        /// rebalance the tree.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        /// <param name="node">Current node being visited.</param>
        private void create(TKey key, TValue value, ref Node<TKey, TValue> node)
        {
            if (node != null)
            {
                if (key.CompareTo(node.Key) < 0)
                {
                    create(key, value, ref node.Left);
                }
                else if (key.CompareTo(node.Key) > 0)
                {
                    create(key, value, ref node.Right);
                }
            }
            else
            {
                node = new Node<TKey, TValue>(key, value);
            }
            
            node.BalanceFactor = getHeight(node.Left)
                - getHeight(node.Right);

            if (node.BalanceFactor <= -2)
            {
                rotateLeft(ref node);
            }
            if (node.BalanceFactor >= 2)
            {
                rotateRight(ref node);
            }
        }

        /// <summary>
        /// Delete the node identified by the supplied key.
        /// </summary>
        /// <param name="Key">Key of node to be deleted.</param>
        public override void Delete(TKey Key)
        {
            delete(Key, ref Root);
        }

        /// <summary>
        /// Recursively search the tree looking for the node requested to be deleted. Once the
        /// node has been deleted the balance of each node must be recalculated and if the 
        /// limit for any one node has been exceeded the tree must rotate. 
        /// </summary>
        /// <param name="key">Unique key used to identify the node being deleted.</param>
        /// <param name="node">Current node being visited.</param>
        protected new void delete(TKey key, ref Node<TKey, TValue> node)
        {
            base.delete(key, ref node);

            if(node != null)
            {
                node.BalanceFactor = getHeight(node.Left)
                - getHeight(node.Right);

                if (node.BalanceFactor <= -2)
                {
                    rotateLeft(ref node);
                }
                if (node.BalanceFactor >= 2)
                {
                    rotateRight(ref node);
                }
            }            
        }

        /// <summary>
        /// Rotate the tree at the supplied node.
        /// </summary>
        /// <param name="node">Node for tree to be rotated around.</param>
        private void rotateLeft(ref Node<TKey, TValue> node)
        {
            if (node.Right.BalanceFactor > 0)
            {
                rotateRight(ref node.Right);
            }
            Node<TKey, TValue> oldNode = node;
            node = node.Right;
            oldNode.Right = node.Left;
            node.Left = oldNode;
            node.BalanceFactor = getHeight(node.Left)
                - getHeight(node.Right);
        }

        /// <summary>
        /// Rotate the tree at the supplied node.
        /// </summary>
        /// <param name="node">Node for tree to be rotated around.</param>
        private void rotateRight(ref Node<TKey, TValue> node)
        {
            if (node.Left != null && node.Left.BalanceFactor < 0)
            {
                rotateLeft(ref node.Left);
            }
            Node<TKey, TValue> oldNode = node;
            node = node.Left;
            oldNode.Left = node.Right;
            node.Right = oldNode;
            node.BalanceFactor = getHeight(node.Left)
                - getHeight(node.Right);
        }
    }
}
