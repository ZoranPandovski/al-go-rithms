%Plotting a discrete signal with stem funtion and easily shifting it
figure(1)
n= -3: 7;
y=[0 0 0 2 3 1 -1 3 0 0 0];
stem (n,y,'filled')
title('Signal x(n)')
xlabel('n') 
ylabel('x[n]') 

figure(2)
n = -1:9 ;
stem (n,y,'filled')
title('Delayed Signal x(n-n1)')
xlabel('n') 
ylabel('x[n-n1]') 

figure (3)
n = -4: 6 ;
stem (n,y,'filled')
title('Advanced Signal x(n+n2)')
xlabel('n') 
ylabel('x[n-n1]')

