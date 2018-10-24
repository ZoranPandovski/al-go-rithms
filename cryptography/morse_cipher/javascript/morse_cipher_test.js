const { encrypt, decrypt } = require('./morse_code_translator.js')

describe('morse cipher', () => {
   [
      ['I keep dark secrets', '.. / -.- . . .--. / -.. .- .-. -.- / ... . -.-. .-. . - ...'],
      ['The house on the hill', '- .... . / .... --- ..- ... . / --- -. / - .... . / .... .. .-.. .-..'],
      ['Big broken bunnies', '-... .. --. / -... .-. --- -.- . -. / -... ..- -. -. .. . ...'],
      ['Die another day', '-.. .. . / .- -. --- - .... . .-. / -.. .- -.--'],
      ['California rolls', '-.-. .- .-.. .. ..-. --- .-. -. .. .- / .-. --- .-.. .-.. ...']
   ].forEach(test => {
      it(`encrypt '${test[0]}' `, () => {
        expect(encrypt(test[0])).toEqual(test[1]);
      });
   });

  [
     ['.-. .. -. --. / .-. .. -. --. / .-. .. -. --.', 'ring ring ring'],
     ['.... .. / .. -- / -.-- ..- .-. / ..- -... . .-. / -.. .-. .. ...- . .-.', 'Hi im yur uber driver'],
     ['.--. .. -. --. / .--. .. -. --. / .--. .. -. --.', 'ping ping ping'],
     ['-.. ..-. -. ... -.. .-.. ..-. .-.. -.. -.- -.- ..-. .-.. -.- .-.. -..', 'dfnsdlfldkkflkld'],
     ['--. .-. .- -.-. . / .... --- .--. .--. . .-.', 'grace hopper']
  ].forEach(test => {
     it(`decrypt '${test[0]}' `, () => {
      expect(decrypt(test[0])).toEqual(test[1]);
   });
  });
});
