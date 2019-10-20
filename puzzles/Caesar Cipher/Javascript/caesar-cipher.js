/*"A Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code
or Caesar shift, is one of the simplest and most widely known encryption techniques.
It is a type of substitution cipher in which each letter in the plaintext is
replaced by a letter some fixed number of positions down the alphabet. For
example, with a left shift of 3, D would be replaced by A, E would become B, and
so on. The method is named after Julius Caesar, who used it in his private correspondence"
-Wikipedia */

function caesarCipher(str) {
  return str.split('')
	.map.call(str, (character) => {
		let char = character.charCodeAt(0);
		//using ASCII code for letters A - Z (ASCII code 65-90)
		if(char < 65 || char > 90) {
			return String.fromCharCode(char);
		} else if (char < 78) {
			return String.fromCharCode(char + 13);
		} else {
			return String.fromCharCode(char -13);
		}
	}).join('');
}
//returns 'Cipher Me'
caesarCipher("PVCURE ZR");
