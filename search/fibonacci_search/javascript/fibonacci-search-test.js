// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>


const fibonacciSearch = require('./fibonacci-search')

describe('Fibonacci Search', () => {

    it ('Search Success', () => {
        let arr = [72, 192, 35, 20, 45, 50, 379, 82,62, 90, 290, 490];
        let n = arr.length;
        let x = [290, 82, 50];
        x.forEach(test => {
            let ind = fibonacciSearch(arr, test, n);
            expect(ind).toBe(arr.indexOf(test))
            if(ind>=0){
            console.log(test + " Found at index: " + ind);
            }else{
            console.log(test + " isn't present in the array");
            }
        })
        
    })

    it('Search failed', () => {
        let arr = [2, 192, 35, 20, 45, 50, 379, 82,62, 90, 290, 490];
        let n = arr.length;
        let x = [10, 100, 238];
        x.forEach(test => {
            let ind = expect(fibonacciSearch(arr, test, n)).toBe(-1)
            expect(ind).not.toBe(Math.sign(ind) == -1)
            if(ind>=0){
            console.log("Found at index: " + ind);
            }else{
            console.log(test + " isn't present in the array");
            }
        })
    })
   
})