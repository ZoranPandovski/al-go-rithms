
import Swift

func cipher(messageToCipher: String, shift: UInt32) {
    var ciphredMessage = ""
    
    for char in messageToCipher.unicodeScalars {
        var unicode : UInt32 = char.value
        
        if char.value > 64 && char.value < 123 {
            var modifiedShift = shift
            if char.value >= 65 && char.value <= 90 {
                while char.value + modifiedShift > 90 {
                    //return to A
                    modifiedShift -= 26
                }
            } else if char.value >= 97 && char.value <= 122 {
                while char.value + modifiedShift > 122 {
                    //return to a
                    modifiedShift -= 26
                }
            }
            
            unicode = char.value + modifiedShift
        }
        
        ciphredMessage += String(UnicodeScalar(unicode)!)
    }
    
    print(ciphredMessage)
}

 print((cipher(messageToCipher: "abcddd", shift: 2)))

