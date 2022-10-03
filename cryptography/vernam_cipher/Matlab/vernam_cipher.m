decision = input('Encryption or decryption?\n\n1 = Encryption\n2 = Decryption\n\nChoice: ');
text = input('\nPlease input text: ', 's');
key = input('Please input key: ', 's');
loop = length(text);

if decision == 1
    encrypt(loop, key, text);
elseif decision == 2
    decrypt(loop, key, text);
else 
    disp('Please input the correct choices')
end  

function encrypt(loop, key, text)
    for no = 1:loop

        if(text(no) >= 'a' && text(no) <= 'z')
            cipher = (double(text(no)) - 97) + (double(key(no)) - 97);

            if (cipher > 26)
                cipher = cipher - 26;
            end

            text(no) = char(cipher + 97);

        elseif(text(no) >= 'A' && text(no) <= 'Z')
            cipher = (double(text(no)) - 65) + (double(key(no)) - 65);

            if (cipher > 26)
                cipher = cipher - 26;
            end

            text(no) = char(cipher + 65);
        end
    end

    fprintf('Ciphered text: %s \n', text)
end

function decrypt(loop, key, text)
     for no = 1:loop

        if(text(no) >= 'a' && text(no) <= 'z')
            cipher = (double(text(no)) - 97) - (double(key(no)) - 97);
            disp(cipher)
            if (cipher < 0)
                cipher = cipher + 26;
            end

            text(no) = char(cipher + 97);

        elseif(text(no) >= 'A' && text(no) <= 'Z')
            cipher = (double(text(no)) - 65) - (double(key(no)) - 65);

            if (cipher < 0)
                cipher = cipher + 26;
            end

            text(no) = char(cipher + 65);
        end
    end
    
    fprintf('Plain text: %s \n', text)
end