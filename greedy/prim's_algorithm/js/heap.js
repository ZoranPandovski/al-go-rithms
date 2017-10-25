
module.exports = class Heap {

    constructor(arr) {
        this._heap = [];
        arr.forEach(v => {
            this._heap.push(v);
        });
        this.build();
    }

    build() {

        let leaves = this.length()/2;
        for(let i=leaves; i>0; i--) {
            this.heapifyMin(i);
        }
        
    }

    length() {
        return this._heap.length;
    }

    getLeftIndex(index) {
        return 2*index;
    }

    getRightIndex(index) {
        return 2*index + 1;
    }

    getParentIndex(index) {
        return index/2
    }

    getValue(index) {
        return this._heap[index];
    }

    setValue(index, value) {
        this._heap[index] = value;
    }

    heapifyMin(index) {

        index = Math.floor(index);

        while(this.getLeftIndex(index) < this._heap.length)
        {

            let left = this.getLeftIndex(index);
            let right = this.getRightIndex(index);

            let min = left;
            if(right < this._heap.length && this.getValue(right).w < this.getValue(left).w)
                min = right;

            // Se o valor do pai é menor do que o valor do menor filho, terminamos
            if (this.getValue(index).w <= this.getValue(min).w) {
                break;
            }

            // Caso contrário, trocamos o pai com o filho no heap e corrigimos agora para o filho
            let aux = this.getValue(index);
            this.setValue(index, this.getValue(min));
            this.setValue(min, aux);
            index = min;
        }

    }

    pop() {
        if(this._heap.length > 0) {
            let item = this._heap.shift();
            this.heapifyMin(0);
            return item;
        }
    }

    addValue(value) {
        this._heap.splice(1, 0, value);
        this.heapifyMin(0);
    }

    find(predicate) {
        return this._heap.find(predicate);
    }

    findIndex(predicate) {
        return this._heap.findIndex(predicate);
    }

    remove(predicate) {
        this._heap = this._heap.filter((obj, index, arr) => {
            return !predicate(obj, index, arr);
        });
        this.heapifyMin(0);
    }
    
}