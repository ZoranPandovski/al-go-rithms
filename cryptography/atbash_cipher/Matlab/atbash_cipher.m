text = input('\nPlease input text: ', 's');
loop = length(text);
cipher(loop, text);

function cipher(loop, text)
    for no = 1:loop

        if(text(no) >= 'a' && text(no) <= 'z')
            cipher = 122 - (double(text(no)) - 97);
            text(no) = char(cipher);

        elseif(text(no) >= 'A' && text(no) <= 'Z')
            cipher = 90 - (double(text(no)) - 65);
            text(no) = char(cipher);
        end
    end

    fprintf('Ciphered text: %s \n', text)
end