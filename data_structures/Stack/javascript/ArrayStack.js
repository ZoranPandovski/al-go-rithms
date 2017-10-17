function Stack() {
    let items = [];
    
    this.pop = function() {
        return items.pop();
    };

    this.push = function(element) {
        items.push(element);
    };

    this.peek = function() {
        return items[items.length-1];
    };

    this.isEmpty = function() {
        return items.length == 0;
    };

    this.clear = function() {
        items = [];
    };
}

module.exports = Stack;
