decision = input('Encryption or decryption?\n\n1 = Encryption\n2 = Decryption\n\nChoice: ');
text = input('\nPlease input text: ', 's');
key = input('Key: ', 's');
loop = length(text);

if decision == 1
    encrypt(loop, key, text);
elseif decision == 2
    decrypt(loop, key, text);
else 
    disp('Please input the correct choices')
end  

function encrypt(loop, key, text)
    keyStr = '';
    for no = 1:loop
        current = text(no);

        if(current >= 'a' && current <= 'z')
            cipher = mod((double(current) + double(key) - 194), 26);
            text(no) = char(cipher + 97);
        elseif(current >= 'A' && current <= 'Z')
            cipher = mod((double(current) + double(key) - 130), 26);
            text(no) = char(cipher + 65);
        end
        keyStr = strcat(keyStr, key);
        key = current;
    end
    fprintf('Ciphered text: %s \n', text)
    fprintf('Cipher key: %s \n', keyStr)
end

function decrypt(loop, key, text)
    for no = 1:loop
        currentText = text(no);
        currentKey = key(no);

        if(currentText >= 'a' && currentText <= 'z')
            cipher = mod((double(currentText) - double(currentKey)), 26);
            text(no) = char(cipher + 97);
        elseif(currentText >= 'A' && currentText <= 'Z')
            cipher = mod((double(currentText) - double(currentKey)), 26);
            text(no) = char(cipher + 65);
        end
    end
    
    fprintf('Plain text: %s \n', text)
end