/* USAGE
plaintext = 'This is unencrypted sample text';
ciphertext = rot13(plaintext);

or

ciphertext = 'Guvf vf harapelcgrq fnzcyr grkg';
plaintext = rot13(ciphertext);
*/

function rot13(text){
  return text.replace(/[a-z]/gi, function(char){
    return String.fromCharCode((char<="Z"?90:122)>=(char=char.charCodeAt(0)+13)?char:char-26);
  });
} 
