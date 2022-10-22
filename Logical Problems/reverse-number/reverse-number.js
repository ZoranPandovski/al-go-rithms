<script>
	let num = 4562;
	// Function to reverse digits of num
	function reverseDigits(num) {
		let rev_num = 0;
		while(num > 0)
		{
			rev_num = rev_num * 10 + num % 10;
			num = Math.floor(num / 10);
		}
		return rev_num;
	}
// function call
	document.write(reverseDigits(num));
	
// This code is contributed by Surbhi tyagi

</script>
