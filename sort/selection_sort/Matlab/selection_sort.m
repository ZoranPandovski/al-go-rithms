decision = input('Sort order:\n\n1 = Ascending\n2 = Descending\n\nChoice: ');

array = input('\nNumber of array:');

initializeArray = zeros(array);

for loop = 1:array
    initializeArray(loop) = input(sprintf('\nInput number [%d]:', loop));
end

for loop = 1:array
    currentIndex = initializeArray(loop);
    
    for loop2 = 1 + loop : array
        
        if (decision == 1)
            if(currentIndex > initializeArray(loop2))
                temp = currentIndex;
                currentIndex = initializeArray(loop2);
                initializeArray(loop2) = temp;
            end
        else
            if(currentIndex < initializeArray(loop2))
                temp = currentIndex;
                currentIndex = initializeArray(loop2);
                initializeArray(loop2) = temp;
            end
        end
    end
    initializeArray(loop) = currentIndex;
end

fprintf('\nSorted list:')
for loop = 1:array
    fprintf('\n%d', initializeArray(loop))
end