import Foundation

func checkArmstrongNumber(_ num: Int) -> Bool {
	var sum = 0
	var tempNum = num
	var reminder = 0
	let digits = String(num).count
	while tempNum != 0  {
		reminder = tempNum % 10
		sum = sum + Int(pow(Double(reminder), Double(digits)))
		tempNum /= 10
		if sum > num {
			break
		}
	}
	if sum == num {
		return true
	}
	return false
}

print("Pick a number to check: ", terminator: "")
let input = readLine()
print()

if let input = input {
	if let num = Int(input) {
		let result = checkArmstrongNumber(num)
		let text = result ? "is" : "is not"
		print("\(input) \(text) an Armstrong Number")
	} else {
		print("Please enter a number")
	}
} else {
	print("Please enter a value")
}
