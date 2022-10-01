%The Newton Raphson Method
clc; clear;
syms x;

%Data
f = input('Enter the function:');
n=input('Enter the number of decimal places:');
x0 = input('Enter the intial approximation:');

%Method
g=diff(f);
epsilon = 5*10^-(n+1)
for i=1:100
  f0=vpa(subs(f,x,x0));
  g0=vpa(subs(g,x,x0));
  y=x0-f0/g0;
  err=abs(y-x0);

  if err<epsilon
    break
  end
  
  x0=y;
end

y = y - rem(y,10^-n);

%Print results
fprintf('The Root is : %f \n',y);
fprintf('Iterations : %d\n',i);
