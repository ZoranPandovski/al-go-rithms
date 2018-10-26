def caesarCipher(text, key, option)
  alphabet = [] of Char
  outputText = ""
  offset = 65

  # if deciphering text, invert key offset
  if option == 'd'
    key = -key
  end

  # create alphabet
  ('A'..'Z').each do |c|
    alphabet << c
  end

  # caesar cipher
  if text
    text.each_char do |c|
      if c.ascii_letter?
        upper_char = c.upcase
        old_char = upper_char.ord - offset
        new_char = ((old_char + key) % 26) + offset
        outputText += new_char.chr
      else
        outputText += c
      end
    end
  end 
  
  return outputText
end

def main
  input = "Hello World! ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  encrypted = caesarCipher(input, 1, 'e')
  decrypted = caesarCipher(encrypted, 1, 'd')
  
  puts "Input: " + input
  puts "Encrypted: " + encrypted
  puts "Decrypted: " + decrypted
end

main
