using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree
{
    /// <summary>
    /// Node represents a single point within a tree. Each point contains information about other 
    /// nodes known as the children nodes (Left, Right) allowing node to be connected and 
    /// traversed one to another. There are only two child nodes for each node as this is being 
    /// used exclusively by binary trees. The node also contains both a key and value pair, the 
    /// idea behind this is to improve search between nodes as it shall allow for fine tune 
    /// searching against a key rather than an entire value. 
    /// </summary>
    /// <typeparam name="TKey">Type of Key must implemented IComparable.</typeparam>
    /// <typeparam name="TValue">Type of Value must implemented IComparable.</typeparam>
    public class Node<TKey, TValue> 
        where TKey : IComparable<TKey> 
        where TValue : IComparable<TValue>
    {
        /// <summary>
        /// Node to the left of this node.
        /// </summary>
        public Node<TKey, TValue> Left;

        /// <summary>
        /// Node to the right of this node.
        /// </summary>
        public Node<TKey, TValue> Right;

        /// <summary>
        /// Construct a new node specifying the Key and Value to hold.
        /// </summary>
        /// <param name="Key">Unique key used to identify the node.</param>
        /// <param name="Value">Actual data being stored in the node.</param>
        public Node(TKey Key, TValue Value)
        {
            this.Key = Key;
            this.Value = Value;
            Left = null;
            Right = null;
        }

        /// <summary>
        /// Key used to uniquely identify the node. 
        /// </summary>
        public TKey Key { get; set; }

        /// <summary>
        /// Value being stored within the node.
        /// </summary>
        public TValue Value { get; set; }

        /// <summary>
        /// Balance of the node. Determined by height of left minus height of right.
        /// </summary>
        public int BalanceFactor { get; set; }
    }
}
