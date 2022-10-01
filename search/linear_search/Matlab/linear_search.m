array = input('\nNumber of array:');

initializeArray = zeros(array, 1);

for loop = 1:array
    initializeArray(loop, 1) = input(sprintf('\nInput number [%d]:', loop));
end

item = input('\nEnter the number to be search:');

for loop = 1:array
    if(initializeArray(loop, 1) == item)
        fprintf('\nThe number is found in index: %d', loop)
        break
    end
end