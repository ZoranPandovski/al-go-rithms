package main

// Rot13 apply rot13 algorithm given a plaintext and returns ciphertext
func Rot13(plaintext string) (ciphertext string) {
	rotation := 13

	for _, char := range plaintext {

		if char >= rune('A') && char <= rune('Z') {
			decrementRotation := int(char)+rotation > int(rune('Z'))
			if decrementRotation {
				ciphertext += string(int(char) - rotation)
			} else {
				ciphertext += string(int(char) + rotation)
			}
		} else if char >= rune('a') && char <= rune('z') {
			decrementRotation := int(char)+rotation > int(rune('z'))
			if decrementRotation {
				ciphertext += string(int(char) - rotation)
			} else {
				ciphertext += string(int(char) + rotation)
			}
		} else {
			ciphertext += " "
		}

	}

	return
}

func main() {}
