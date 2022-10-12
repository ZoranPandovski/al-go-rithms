function encrypt(messageInput, keyword) {
    var alphabet = 'abcdefghijklmnopqrstuvwxyz';
    var messageOutput = "";

    var pos = 0;
    while (pos < messageInput.length) {
        var m1 = messageInput[pos];
        var m2 = '';

        if (pos + 1 < messageInput.length) {
            m2 = messageInput[pos + 1];
            pos += 2;
        } else {
            m2 = 'Q'  // some dummy letter
            pos += 1;
        }

        var idx1 = alphabet.indexOf(m1);  // upper-left table
        var idx2 = alphabet.indexOf(m2);  // lower-right table
        var c1 = keyword[0][(5 * Math.floor(idx1 / 5)) + idx2 % 5];
        var c2 = keyword[1][(5 * Math.floor(idx2 / 5)) + idx1 % 5];

        messageOutput = messageOutput.concat(c1);
        messageOutput = messageOutput.concat(c2);
    }

    return messageOutput;
}
