var BinarySearchTree = function(value) {
  var someInstance = Object.create(bstMethods);
  someInstance.value = value;
  someInstance.left = null;
  someInstance.right = null;
  return someInstance;
};

var bstMethods = {};

bstMethods.insert = function(value) {
  var newNode = BinarySearchTree(value);
  if (value < this.value) {
    if (this.left === null) {
      this.left = newNode;
    } else {
      this.left.insert(value);
    }
  }
  if (value > this.value) {
    if (this.right === null) {
      this.right = newNode;
    } else {
      this.right.insert(value);
    }
  }
};

bstMethods.contains = function(value) {
  var result = false;
  if (value === this.value) {
    result = true;
  }
  if (value < this.value) {
    if (this.left !== null) {
      if (this.left.contains(value)) {
        result = true;
      }
    }
  }
  if (value > this.value) {
    if (this.right !== null) {
      if (this.right.contains(value)) {
        result = true;
      }
    }
  }
  return result;
};

bstMethods.depthFirstLog = function(cb) {
  cb(this.value);
  if (this.left !== null) {
    this.left.depthFirstLog(cb);
  }
  if (this.right !== null) {
    this.right.depthFirstLog(cb);
  }
};
