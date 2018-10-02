using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree
{
    /// <summary>
    /// BSTree builds upon the limited functionality of the BinaryTree. This is because the BSTree
    /// uses an actual insertion algorithm in which smaller values than current node go to the 
    /// left and larger values go to the right. This algorithm cleans up the insertion of new nodes
    /// by using one function rather than directly accessing the Root. In addition to this it 
    /// improves searching as it can take advantage of the insertion of values placing smaller 
    /// values to the left and larger to the right.
    /// </summary>
    /// <typeparam name="TKey">Type of Key must implemented IComparable.</typeparam>
    /// <typeparam name="TValue">Type of Value must implemented IComparable.</typeparam>
    public class BSTree<TKey, TValue> : BinaryTree<TKey, TValue> 
        where TKey : IComparable<TKey> 
        where TValue : IComparable<TValue>
    {
        /// <summary>
        /// Construct a new BSTree with null Root.
        /// </summary>
        public BSTree() : base() { }

        /// <summary>
        /// Construct a new BSTree with Root containg the following Key/Value node pair.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public BSTree(TKey Key, TValue Value ) : base(Key, Value) { }

        /// <summary>
        /// Create a new node with the supplied key and value at the appropriate place within 
        /// the tree.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public override void Create(TKey Key, TValue Value)
        {
            create(Key, Value, ref Root);
        }

        /// <summary>
        /// Recursively traverse the tree going left is key is smaller than node's key or right if 
        /// larger. This traverse pattern shall allow for improved search throughout the tree. Once
        /// an appropriate place has been found initialise the node within the tree.
        /// </summary>
        /// <param name="key">Unique key used to identify the node.</param>
        /// <param name="value">Actual data being stored in the node.</param>
        /// <param name="node">Current position within the tree.</param>
        private void create(TKey key, TValue value, ref Node<TKey, TValue> node)
        {
            if(node != null)
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
        }

        /// <summary>
        /// Search the tree for a node with the specified key returning the corresponding value.
        /// </summary>
        /// <param name="key">Unique key used to identify the node being searched for.</param>
        /// <returns>Value contained within node marked with the supplied key.</returns>
        public override TValue Get(TKey Key)
        {
            return get(Key, Root);
        }

        /// <summary>
        /// Recursively traverse the tree going left is key is smaller than node's key or right if 
        /// larger. Once the node in question has been found return it's value.
        /// </summary>
        /// <param name="key">Unique key used to identify the node being searched for.</param>
        /// <param name="node">Current position within the tree.</param>
        private TValue get(TKey key, Node<TKey, TValue> node)
        {
            if(node != null)
            {
                if(key.CompareTo(node.Key) == 0)
                {
                    return node.Value;
                }
                else if(key.CompareTo(node.Key) < 0)
                {
                    return get(key, node.Left);
                }
                else if(key.CompareTo(node.Key) > 0)
                {
                    return get(key, node.Right);
                }
            }
            return default(TValue);
        }

        /// <summary>
        /// Update the node with the supplied key with the accompanying value.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node being updated.</param>
        /// <param name="Value">Node data will be placed with this data.</param>
        public override void Edit(TKey Key, TValue Value)
        {
            edit(Key, Value, ref Root);
        }

        /// <summary>
        /// Recursively traverse the tree until the node marked for updating has been located. Once
        /// located update it's value with the supplied value.
        /// </summary>
        /// <param name="key">Unique key used to identify the node being updated.</param>
        /// <param name="value">Node data will be placed with this data.</param>
        /// <param name="node">Current position within the tree.</param>
        private void edit(TKey key, TValue value, ref Node<TKey, TValue> node)
        {
            if (node != null)
            {
                if (key.CompareTo(node.Key) == 0)
                {
                    node.Value = value;
                }
                else if (key.CompareTo(node.Key) < 0)
                {
                    edit(key, value, ref node.Left);
                }
                else if (key.CompareTo(node.Key) > 0)
                {
                    edit(key, value, ref node.Right);
                }
            }
        }

        /// <summary>
        /// Delete the node with the supplied key.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node being deleted.</param>
        public override void Delete(TKey Key)
        {
            delete(Key, ref Root);
        }

        /// <summary>
        /// Delete the node with the supplied key. Traverse the tree finding the value marked for 
        /// removal, once found take the appropriate steps to ensure that other value are not 
        /// remove alongside the marked value.
        /// </summary>
        /// <param name="key">Unique key used to identify the node being deleted.</param>
        /// <param name="node">Current position within the tree.</param>
        protected void delete(TKey key, ref Node<TKey, TValue> node)
        {
            if(node != null)
            {
                if(key.CompareTo(node.Key) == 0)
                {
                    if(node.Left != null)
                    {
                        if(node.Right != null)
                        {
                            Node<TKey, TValue> minNode = leastItem(node.Right);
                            node.Key = minNode.Key;
                            node.Value = minNode.Value;
                            delete(node.Key, ref node.Right);
                        }
                        else
                        {
                            node = node.Left;
                        }
                    }
                    else if(node.Right != null)
                    {
                        node = node.Right;
                    }
                    else
                    {
                        node = null;
                    }
                }
                else if(node.Left != null && key.CompareTo(node.Key) < 0)
                {
                    delete(key, ref node.Left);
                }
                else if(node.Right != null && key.CompareTo(node.Key) > 0)
                {
                    delete(key, ref node.Right);
                }
            }
        }

        /// <summary>
        /// Identify the smallest item within the tree. This is possible as insertion algorithm
        /// used within a BSTree is one where the left most value is the smallest value.
        /// </summary>
        /// <param name="node">Current node within the traversal of the tree.</param>
        /// <returns>Node containing the smallest value within the tree.</returns>
        protected Node<TKey, TValue> leastItem(Node<TKey, TValue> node)
        {
            if (node.Left == null)
            {
                return node;
            }
            else
            {
                return leastItem(node.Left);
            }
        }
    }
}
