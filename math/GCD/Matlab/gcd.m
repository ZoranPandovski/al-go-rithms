val1 = input('Enter first value: ');
val2 = input('Enter second value: ');

if val1 > val2
    temp = val1;
    val1 = val2;
    val2 = temp;
end

fprintf('\nGreatest common denominator of %d and %d: %d', val1, val2, gcd(val1, val2));

function a = gcd(val1, val2)
    if val2 == 0
        a = val1;
    else
        a = gcd(val2, mod(val2, val1));
    end
end