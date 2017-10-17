// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const Stack = require('./ArrayStack');

describe('Stack [data-structure]', function(){
    let myStack = new Stack();
    const sampleData = [1,2,3,4,10,23,2];

    it("IsEmpty at the begining", function() {
        expect(myStack.isEmpty()).toBe(true);
    });

    it("Can add elements with Push", function() {
        for (let index = 0; index < sampleData.length; index++) {
            let element = sampleData[index];
            myStack.push(element);
            expect(myStack.isEmpty()).toBe(false);
        }
    });

    it("Can retrieve elements with Pop", function() {
        let index = 0;
        while(!myStack.isEmpty()) {
            index++;
            expect(myStack.pop()).toBe(sampleData[sampleData.length-index]);
        }
    });

    it("Can be cleaned up", function() {
        for (let index = 0; index < sampleData.length; index++) {
            let element = sampleData[index];
            myStack.push(element);
        }
        expect(myStack.isEmpty()).toBe(false);

        myStack.clear();
        expect(myStack.isEmpty()).toBe(true);
    });

})

