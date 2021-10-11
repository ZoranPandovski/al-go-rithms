def is_palindrome (word)
  reversed_word = word.reverse

  if (word == reversed_word)
    return true   
  end
  return false

end

# Take a word from the user as input and your output is true if is palindrome word or false if not
print("Enter a word:")
word = gets.chomp

if ( is_palindrome(word) )
  print("The word " + word + " is a palidrome\n")
else
  print("The word " + word + " is not a palidrome\n")
end
