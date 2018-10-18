const isIsogram = (str) => {
    var result = true;

    if (str.length == 0) {
        result = true;
    } else {
        var words = str.split('');

        for (var i = 0; i <= words.length - 1; i++) {
            var count = 0;
            word = words[i].toLowerCase();
            for (var a = 0; a <= words.length - 1; a++) {
                if (word === words[a].toLowerCase()) {
                    count += 1;
                }
            }
            if (count == 2 || count > 2) {
                result = false;
                break;
            }
        }
    }

    return result;
}

// if (isIsogram("isogram")) {
//     console.log("is an isogram");
// } else {
//     console.log("is not an isogram");
// }