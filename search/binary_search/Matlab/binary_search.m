array = input('\nNumber of array:');

initializeArray = zeros(array);

for loop = 1:array
    initializeArray(loop) = input(sprintf('\nInput number [%d]:', loop));
end

item = input('\nEnter the number to be search:');

first = 1;
last = array;

while first <= last
    middle = round((first + last) / 2);
    if(initializeArray(middle) == item)
        fprintf('\nThe number is found in index: %d', middle)
        break
    elseif(initializeArray(middle) < item)
        first = middle + 1;
    elseif(initializeArray(middle) > item)
        last = middle - 1;
    end
end

if(first > last)
    fprintf('\nItem not found')
end