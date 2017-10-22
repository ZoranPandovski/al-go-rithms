
const fs = require('fs');

const Heap = require('./heap');

function predicateTargetOrigin(node) {
    return function(obj) {
        return node.t == obj.o;
    };
}

function predicateReverse(node) {
    return function(obj) {
        return node.o == obj.t && node.t == obj.o;
    };
}

function mst_prim(listaAdj, pesos, r) {

    let chave = [];
    let pai = [];

    listaAdj.forEach((adj, i) => {
        chave[i] = Number.MAX_SAFE_INTEGER;
        pai[i] = false;
    });

    let heap = new Heap([{ p: 0, w: r }]);

    let sub = [];
    let pesoTotal = 0;

    chave[r] = 0;

    while(heap.length() > 0) {
        let v = heap.pop();
        sub.push(v.p);
        // console.log('Tratando: ' + v.p);
        pesoTotal += v.w;

        listaAdj[v.p].forEach( (u, index) => {

            // is it a safe edge?
            if(sub.indexOf(u.p) > -1) {
                // console.log('\t'+u.p+' not a safe edge');
                return;
            }

            if(chave[u.p] > u.w) {
                heap.remove(obj => {
                    return obj.p == u.p && obj.w == chave[u.p];
                });
                heap.addValue(u);
                pai[u.p] = v.p;
                chave[u.p] = u.w;
                // console.log(v.p+'->'+u.p);
            }

        });
    }

    return [pesoTotal, sub, pai];

}


let input = fs.readFileSync('/dev/stdin').toString().split("\n");

let n = parseInt(input.shift());
let listaAdj = [];
let pesos = [];

for(var i=0;i<n;i++) {
    listaAdj[i] = [];
    pesos[i] = new Array(n);
}

for(var i=0;i<n-1;i++) {
    let numbers = input[i].trim().split(" ").map(n => { return parseInt(n); });

    // console.log(numbers);

    for(j=0;j<n-1-i;j++) {
        // console.log(i+'x'+(j+i+1));
        let value = numbers[j];
        if(value <= 0) continue;

        pesos[i][j+i+1] = value;
        pesos[j+i+1][i] = value;

        listaAdj[i].push({
            p: j+i+1,
            w: value
        });
        listaAdj[j+i+1].push({
            p: i,
            w: value
        });
    }
    
}

// console.log('n: '+n);
// console.log(listaAdj);

let result = mst_prim(listaAdj, pesos, 0);

console.log('Custo: '+result[0]);
// console.log('sub');
// console.log(result[1]);

let pai = result[2];
pai.forEach((p, i) => {
    // console.log(String.fromCharCode(97 + p)+'->'+String.fromCharCode(97 + i));
    console.log(p+'->'+i);
});