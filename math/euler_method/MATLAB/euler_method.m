% Data
h=input('Step size:');
N=input('Number of steps:');
f = input('DE function, y=');
y(1)=input('y(1)=');

%Algorithms
for n=1:N
  y(n+1)= y(n)+h*(f);
  x(n+1)=n*h;
end

y(n+1)
x(n+1)
