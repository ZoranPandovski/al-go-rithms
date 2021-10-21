
describe('Fibonacci Search', () => {

    it ('Search Success', () => {
        let arr = [72, 192, 35, 20, 45, 50, 379, 82,62, 90, 290, 490];
        let n = arr.length;
        let x = [90, 72, 290, 82];
        x.forEach(test => {
            let ind = expect(fibonnaciSearch(arr, test, n).toBe(arr.indexOf(test))) ;
            if(ind>=0){
            console.log("Found at index: " + ind);
            }else{
            console.log(test + " isn't present in the array");
            }
        })
        
    })

    it('Search failed', () => {
        let arr = [72, 192, 35, 20, 45, 50, 379, 82,62, 90, 290, 490];
        let n = arr.length;
        let x = [90, 10, 100, 82];
        x.forEach(test => {
            let ind = expect(fibonnaciSearch(arr, test, n).not.toBe(-1))
            expect(ind).not.toBe(Math.sign(ind) == -1)
            if(ind>=0){
            console.log("Found at index: " + ind);
            }else{
            console.log(test + " isn't present in the array");
            }
        })
    })
   
})