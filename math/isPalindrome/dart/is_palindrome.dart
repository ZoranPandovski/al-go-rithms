void main() {
  print(isPalindrome('arara') ? 'Is Palindrome' : 'Nah');
  print(isPalindrome('queijo') ? 'Is Palindrome' : 'Nah');
  print(isPalindrome('ama') ? 'Is Palindrome' : 'Nah');
  print(isPalindrome('palindrome') ? 'Is Palindrome' : 'Nah');
}

bool isPalindrome(String word) {
  List<String> chars = new List<String>();
  for (int i = 0; i < word.length; i++) {
    chars.add(word[i]);
  }

  for (int i = 0; i < chars.length / 2; i++) {
    if (chars[i] != chars[chars.length - 1 - i]) {
      return false;
    }
  }
  return true;
}