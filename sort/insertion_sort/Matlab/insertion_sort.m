decision = input('Sort order:\n\n1 = Ascending\n2 = Descending\n\nChoice: ');

array = input('\nNumber of array:');

initializeArray = zeros(array);

for loop = 1:array
    initializeArray(loop) = input(sprintf('\nInput number [%d]:', loop));
end

if decision == 1
    a = ascending(array, initializeArray);
elseif decision == 2
    a = descending(array, initializeArray);
else 
    disp('Please input the correct choices either 1 or 2')
end 

fprintf('\nSorted list:')
for loop = 1:array
    fprintf('\n%d', a(loop))
end

function a = ascending(array, initializeArray)
    for loop = 1:array
        currentIndex = initializeArray(loop);
        loop2 = loop - 1;
        
        while (loop2 >= 1 && initializeArray(loop2) > currentIndex)
            initializeArray(loop2 + 1) = initializeArray(loop2);
            loop2 = loop2 - 1;
        end
        initializeArray(loop2 + 1) = currentIndex;
    end
    a = initializeArray;
end

function a = descending(array, initializeArray)
    for loop = 1:array
        currentIndex = initializeArray(loop);
        loop2 = loop - 1;
        
        while (loop2 >= 1 && initializeArray(loop2) < currentIndex)
            initializeArray(loop2 + 1) = initializeArray(loop2);
            loop2 = loop2 - 1;
        end
        initializeArray(loop2 + 1) = currentIndex;
    end
    a = initializeArray;
end