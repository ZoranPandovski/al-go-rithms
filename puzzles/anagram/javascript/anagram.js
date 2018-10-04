const noOfChars = 256;

function anagram_check(str1, str2){
	var count1 = [];
	var count2 = [];

	for(var i=0; str1[i] && str2[i]; i++){
		count1[str1[i]]++;
		count2[str2[i]]++;
	}

	if(str1[i] || str2[i]){
		return false;
	}

	for(i=0; i<noOfChars; i++){
		if(count1[i] != count2[i]){
			return false;
		}
	}

	return true;
}

anagram_check("aaca","aca") ? console.log("True") : console.log("False"); // Test case