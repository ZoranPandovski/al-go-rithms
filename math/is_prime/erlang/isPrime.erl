-module(isPrime).
-export([is_prime/1]).

%% To test it on shell...
%% 1> isPrime:is_prime(1).
%% false
%% 2> isPrime:is_prime(2).
%% true
%% 3> isPrime:is_prime(-1).
%% ** exception error: no function clause matching isPrime:is_prime(-1) (isPrime.erl, line 13)

-spec is_prime(pos_integer()) -> boolean().
is_prime(1) -> false;
is_prime(N) when N >= 2 ->
    is_prime(2,N).


-spec is_prime(pos_integer(),pos_integer()) -> boolean().
is_prime(I,N) when (I * I) =< N ->
    case N rem I of
        0 -> false;
        _ -> is_prime(I+1,N)
    end;
is_prime(_,_) -> true.
