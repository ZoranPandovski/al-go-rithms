class LuhnECMA6 {

	constructor(cardNo) {

    /* Preparing Variables */
		this._reverseCardNo = cardNo.split('').reverse().join('');
		this._intCardNo = Array.from(this._reverseCardNo)
													 .map(a => parseInt(a));
		this._value = 0;
		this._filterSum = 0;
		this._checkDigit = [];
		this._filter1 = [];
		this._filter2 = [];
		this._preparedNumList = [];
		this._finalNumList = [];
	}

 /* Accept anything but set to array*/
	setCheckDigit(... digit){
		this._checkDigit = digit;
	}

  /*Merging two arrays and output as a string*/
	getCardNo(){
		Array.prototype.push.apply(this._intCardNo.reverse(), this._checkDigit);
		return this._intCardNo.join('');
	}

	/* Filtering ODD numbers*/
	getOddNumberList(){

		let pos = 1;
		this._filter1 = this._intCardNo.filter(a => {
		  this._value =  pos % 2 != 0
		  pos++;
		  return this._value;
		});
	}

 /* Filtering EVEN numbers*/
	getEvenNumberList(){

		let pos = 1;
		this._filter2 = this._intCardNo.filter(a => {
		  this._value =  pos % 2 == 0;
		  pos++;
		  return this._value;
		});
	}

 /* Manipulating ODD numbers according to the algo.*/
	prepareOddNumbers(){

		let x = 0;
		this._preparedNumList = this._filter1.map(a => {
		  x = a * 2;
		  if(x > 9){
			x = x - 9;
		  }
		  return x;
		});
	}

  /*Get total value of the sequence*/
	getTotal(){

		this._finalNumList = this._preparedNumList.concat(this._filter2);
		this._filterSum = this._finalNumList.reduce((a,b) => {
		  return a + b;
		});
	}

	getFilterSum(){
		return this._filterSum;
	}

}

/*=================== Execution ========================*/

let luhnECMA6 = new LuhnECMA6("239856745612864");

luhnECMA6.getOddNumberList();
luhnECMA6.getEvenNumberList();
luhnECMA6.prepareOddNumbers();
luhnECMA6.getTotal();

let val = luhnECMA6.getFilterSum() % 10;
let checkDigit = 10 - val;

luhnECMA6.setCheckDigit(checkDigit);

document.write(`Check Digit : ${checkDigit} <br/>`);
document.write(`Card Number : ${luhnECMA6.getCardNo()} <br/>`);











































