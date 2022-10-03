decision = input('Encryption or decryption?\n\n1 = Encryption\n2 = Decryption\n\nChoice: ');
text = input('\nPlease input text: ', 's');
key1 = input('First Key: ');
key2 = input('Second Key: ');
loop = length(text);

if decision == 1
    encrypt(loop, key1, key2, text);
elseif decision == 2
    decrypt(loop, key1, key2, text);
else 
    disp('Please input the correct choices')
end  

function encrypt(loop, key1, key2, text)
    for no = 1:loop
        current = text(no);

        if(current >= 'a' && current <= 'z')
            cipher = mod(key1.*(double(current) - 97) + key2, 26);
            text(no) = char(cipher + 97);
        elseif(current >= 'A' && current <= 'Z')
            cipher = mod(key1.*(double(current) - 65) + key2, 26);
            text(no) = char(cipher + 65);
        end
    end

    fprintf('Ciphered text: %s \n', text)
end

function decrypt(loop, key1, key2, text)
    for no = 1:26
        flag = mod(key1.*no, 26);

        if(flag == 1)
            inv = no;
        end
    end
    
    for no = 1:loop
        current = text(no);

        if(current >= 'a' && current <= 'z')
            cipher = mod(inv.*(double(current) - 97 - key2), 26);
            text(no) = char(cipher + 97);
        elseif(current >= 'A' && current <= 'Z')
            cipher = mod(inv.*(double(current) - 65 - key2), 26);
            text(no) = char(cipher + 65);
        end
    end
    
    fprintf('Plain text: %s \n', text)
end