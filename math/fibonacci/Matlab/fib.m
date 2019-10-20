function y = fib (n)
% calculates the first n numbers of the Fibonacci sequence
  y = ones(1,n);
  y(1) = 1;
  y(2) = 1;
  k = 3;
  while k <=n
    y(k) = y(k-1) + y(k-2);
    k = k+1
    end
end
