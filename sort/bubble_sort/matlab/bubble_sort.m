% Language : Matlab 2007a
% Author : AKS1996

clc
clear all

A=[18  7  6  15  4  13];
disp(A)

n=length(A);

for j=1:1:n-1
    % comparing each number with the next and swapping
    for i=1:1:n-1
    if A(i)>A(i+1);
        % temp is a variable where the numbers are kept
        % temporarily for the switch
        temp=A(i);
        A(i)=A(i+1);
        A(i+1)=temp;
    end
    end
end

disp(‘  ‘)
disp (‘OUTPUT’)
disp(A)
