class String
  def palindrome?
    characters = self.downcase.scan(/\w/)
    characters == characters.reverse
  end
end
