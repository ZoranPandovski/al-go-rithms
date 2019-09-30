var Node = function (key, value) {
  this.left = null;
  this.right = null;
  this.height = null;
  this.key = key;
  this.value = value;
};

Node.prototype.rotateRight = function () {
  var other = this.left;
  this.left = other.right;
  other.right = this;
  this.height = Math.max(this.leftHeight(), this.rightHeight()) + 1;
  other.height = Math.max(other.leftHeight(), this.height) + 1;
  return other;
};

Node.prototype.rotateLeft = function () {
  var other = this.right;
  this.right = other.left;
  other.left = this;
  this.height = Math.max(this.leftHeight(), this.rightHeight()) + 1;
  other.height = Math.max(other.rightHeight(), this.height) + 1;
  return other;
};

Node.prototype.leftHeight = function () {
  if (!this.left) {
    return -1;
  }
  return this.left.height;
};

Node.prototype.rightHeight = function () {
  if (!this.right) {
    return -1;
  }
  return this.right.height;
};


var AvlTree = function (customCompare) {
  this._root = null;
  this._size = 0;

  if (customCompare) {
    this._compare = customCompare;
  }
};

AvlTree.prototype._compare = function (a, b) {
  if (a > b) {
    return 1;
  }
  if (a < b) {
    return -1;
  }
  return 0;
};

AvlTree.prototype.insert = function (key, value) {
  this._root = this._insert(key, value, this._root);
  this._size++;
};


AvlTree.prototype._insert = function (key, value, root) {
  // Perform regular BST insertion
  if (root === null) {
    return new Node(key, value);
  }

  if (this._compare(key, root.key) < 0) {
    root.left = this._insert(key, value, root.left);
  } else if (this._compare(key, root.key) > 0) {
    root.right = this._insert(key, value, root.right);
  } else {
    // It's a duplicate so insertion failed, decrement size to make up for it
    this._size--;
    return root;
  }

  // Update height and rebalance tree
  root.height = Math.max(root.leftHeight(), root.rightHeight()) + 1;
  var balanceState = getBalanceState(root);

  if (balanceState === BalanceState.UNBALANCED_LEFT) {
    if (this._compare(key, root.left.key) < 0) {
      // Left left case
      root = root.rotateRight();
    } else {
      // Left right case
      root.left = root.left.rotateLeft();
      return root.rotateRight();
    }
  }

  if (balanceState === BalanceState.UNBALANCED_RIGHT) {
    if (this._compare(key, root.right.key) > 0) {
      // Right right case
      root = root.rotateLeft();
    } else {
      // Right left case
      root.right = root.right.rotateRight();
      return root.rotateLeft();
    }
  }

  return root;
};

AvlTree.prototype.devare = function (key) {
  this._root = this._devare(key, this._root);
  this._size--;
};

AvlTree.prototype._devare = function (key, root) {
  // Perform regular BST devarion
  if (root === null) {
    this._size++;
    return root;
  }

  if (this._compare(key, root.key) < 0) {
    // The key to be devared is in the left sub-tree
    root.left = this._devare(key, root.left);
  } else if (this._compare(key, root.key) > 0) {
    // The key to be devared is in the right sub-tree
    root.right = this._devare(key, root.right);
  } else {
    // root is the node to be devared
    if (!root.left && !root.right) {
      root = null;
    } else if (!root.left && root.right) {
      root = root.right;
    } else if (root.left && !root.right) {
      root = root.left;
    } else {
      // Node has 2 children, get the in-order successor
      var inOrderSuccessor = minValueNode(root.right);
      root.key = inOrderSuccessor.key;
      root.value = inOrderSuccessor.value;
      root.right = this._devare(inOrderSuccessor.key, root.right);
    }
  }

  if (root === null) {
    return root;
  }

  // Update height and rebalance tree
  root.height = Math.max(root.leftHeight(), root.rightHeight()) + 1;
  var balanceState = getBalanceState(root);

  if (balanceState === BalanceState.UNBALANCED_LEFT) {
    // Left left case
    if (getBalanceState(root.left) === BalanceState.BALANCED ||
        getBalanceState(root.left) === BalanceState.SLIGHTLY_UNBALANCED_LEFT) {
      return root.rotateRight();
    }
    // Left right case
    if (getBalanceState(root.left) === BalanceState.SLIGHTLY_UNBALANCED_RIGHT) {
      root.left = root.left.rotateLeft();
      return root.rotateRight();
    }
  }

  if (balanceState === BalanceState.UNBALANCED_RIGHT) {
    // Right right case
    if (getBalanceState(root.right) === BalanceState.BALANCED ||
        getBalanceState(root.right) === BalanceState.SLIGHTLY_UNBALANCED_RIGHT) {
      return root.rotateLeft();
    }
    // Right left case
    if (getBalanceState(root.right) === BalanceState.SLIGHTLY_UNBALANCED_LEFT) {
      root.right = root.right.rotateRight();
      return root.rotateLeft();
    }
  }

  return root;
};

AvlTree.prototype.get = function (key) {
  if (this._root === null) {
    return null;
  }

  return this._get(key, this._root).value;
};

AvlTree.prototype._get = function (key, root) {
  var result = this._compare(key, root.key);

  if (result === 0) {
    return root;
  }

  if (result < 0) {
    if (!root.left) {
      return null;
    }
    return this._get(key, root.left);
  }

  if (!root.right) {
    return null;
  }
  return this._get(key, root.right);
};

AvlTree.prototype.contains = function (key) {
  if (this._root === null) {
    return false;
  }

  return !!this._get(key, this._root);
};

AvlTree.prototype.findMinimum = function () {
  return minValueNode(this._root).key;
};

function minValueNode(root) {
  var current = root;
  while (current.left) {
    current = current.left;
  }
  return current;
}

AvlTree.prototype.findMaximum = function () {
  return maxValueNode(this._root).key;
};

function maxValueNode(root) {
  var current = root;
  while (current.right) {
    current = current.right;
  }
  return current;
}

AvlTree.prototype.size = function () {
  return this._size;
};

AvlTree.prototype.isEmpty = function () {
  return this._size === 0;
};

var BalanceState = {
  UNBALANCED_RIGHT: 1,
  SLIGHTLY_UNBALANCED_RIGHT: 2,
  BALANCED: 3,
  SLIGHTLY_UNBALANCED_LEFT: 4,
  UNBALANCED_LEFT: 5
};

function getBalanceState(node) {
  var heightDifference = node.leftHeight() - node.rightHeight();
  switch (heightDifference) {
    case -2: return BalanceState.UNBALANCED_RIGHT;
    case -1: return BalanceState.SLIGHTLY_UNBALANCED_RIGHT;
    case 1: return BalanceState.SLIGHTLY_UNBALANCED_LEFT;
    case 2: return BalanceState.UNBALANCED_LEFT;
    default: return BalanceState.BALANCED;
  }
}

module.exports = AvlTree;
