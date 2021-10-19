iteration = input('Enter a value: ');

sum = 0;

while (iteration > 0)
    sum = sum + mod(iteration, 10);
    iteration = fix(iteration/10);
end

fprintf('\nSum of digts: %d', sum);