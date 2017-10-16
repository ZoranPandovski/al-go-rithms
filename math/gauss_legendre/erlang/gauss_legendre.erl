%% @author Mark Hillman <mark@markhillman.info>
%% @doc
%% This short module is used to calculate PI using the Gauss-Legendre
%% algorithm. The algorithm is fairly short and consists of just 4 steps.
%% The algorithm can be found on wikipedia [https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm].

-module(gauss_legendre).
-export([calculate_pi/1]).

%% @doc
%% Initial values for the algorithm.
a_init() -> 1.
b_init() -> 1 / math:sqrt(2).
t_init() -> 1 / 4.
p_init() -> 1.

%% @doc
%% Calculate the next values of the iteration.
a_next(A, B) -> (A + B) / 2.
b_next(A, B) -> math:sqrt(A * B).
t_next(T, P, A, ANext) -> T - P * math:pow(A - ANext, 2).
p_next(P) -> 2 * P.

%% @doc
%% Determines current iteration of pi from the variables
pi_approx(A, B, T) ->
    math:pow(A + B, 2) / (4 * T).

%% @doc
%% Calculates PI using the Gauss-Legendre algorithm. The only argument is the
%% number of iterations that the algorithm should go through.
-spec calculate_pi(N :: pos_integer()) -> number().
calculate_pi(N) when N =< 0 -> 0;
calculate_pi(N) -> calculate_pi(N, a_init(), b_init(), t_init(), p_init(), 0).
calculate_pi(N, ANext, BNext, TNext, _P, N) -> pi_approx(ANext, BNext, TNext);
calculate_pi(N, A, B, T, P, Iter) ->
    ANext = a_next(A, B),
    BNext = b_next(A, B),
    TNext = t_next(T, P, A, ANext),
    PNext = p_next(P),
    calculate_pi(N, ANext, BNext, TNext, PNext, Iter+1).