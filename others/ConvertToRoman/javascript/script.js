const inputBox = document.querySelector('input[name="anyNumber"]')
const romanNunber = document.querySelector('.romanNumber')

document.querySelector("button[name='submitNumber']").addEventListener('click', function(){
    console.log(inputBox.value);
    if(inputBox.value != "") {
        var convertedNumber =  convertToRoman(inputBox.value);
        romanNunber.innerHTML = convertedNumber != undefined ? "Roman Number : " + convertedNumber : "Please enter valid number";
    } else {
        romanNunber.innerHTML = "Input field is empty, Please enter";
    }
    
});

var romanMatrix = [
    [1000, 'M'],
    [900, 'CM'],
    [500, 'D'],
    [400, 'CD'],
    [100, 'C'],
    [90, 'XC'],
    [50, 'L'],
    [40, 'XL'],
    [10, 'X'],
    [9, 'IX'],
    [5, 'V'],
    [4, 'IV'],
    [1, 'I']
  ];
  
  function convertToRoman(num) {
    if (num === 0) {
      return '';
    }
    for (var i = 0; i < romanMatrix.length; i++) {
      if (num >= romanMatrix[i][0]) {
        return romanMatrix[i][1] + convertToRoman(num - romanMatrix[i][0]);
      }
    }
  }