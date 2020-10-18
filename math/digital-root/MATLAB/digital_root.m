%% Digital root

% Data

num=input('Enter the number:');

num_str = num2str(num);
result = sum(num_str-'0');

while result > 9
    result = num2str(result);
    result = sum(result-'0');
end


result
