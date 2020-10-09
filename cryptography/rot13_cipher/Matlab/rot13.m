%You can change it to rot1 to 25 by changing the value of key variable

decision = input('Encryption or decryption?\n\n1 = Encryption\n2 = Decryption\n\nChoice: ');
text = input('\nPlease input plain text: ', 's');
key = 13;
loop = length(text);

if decision == 1
    a = encrypt(loop, key, text);
elseif decision == 2
    a = decrypt(loop, key, text);
else 
    disp('Please input the correct choices')
end  

function  a = encrypt(loop, key, text)                 
    for no = 1:loop                                    
        current = text(no);
        
        if(current >= 'a' && current <= 'z')           
            current = current + key;                   
            
            if(current > 'z')                           
                current = current - 'z' + 'a' -1;
            end
                                                    
        elseif(current >= 'A' && current <= 'Z')
            current = current + key;
            
            if(current > 'Z')
                current = current - 'Z' + 'A' -1;      
            end
        end
        
        text(no) = current;
    end
    a = text;
    fprintf('Ciphered text: %s \n', a)
end

function  a = decrypt(loop, key, text)
    for no = 1:loop
        current = text(no);
        
        if(current >= 'a' && current <= 'z')       
            current = current - key;                  
            
            if(current < 'a')
                current = current + 'z' - 'a' +1;     
            end                                     
                                                  
        elseif(current >= 'A' && current <= 'Z')      
            current = current - key;
            
            if(current < 'A')
                current = current + 'Z' - 'A' +1;
            end
        end
        
        text(no) = current;
    end
    a = text;
    fprintf('Plain text: %s \n', a)
end