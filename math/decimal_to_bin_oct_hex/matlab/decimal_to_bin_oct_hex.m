x = input('Enter the amount to be converted: ');
fprintf('%d in binary is: %s\n', x, dec2bin(x));
fprintf('%d in octal is: %s\n', x, dec2base(x, 8));
fprintf('%d in hexadecimal is: %s\n', x, dec2hex(x));

% author: Higor Santos de Brito Dantas