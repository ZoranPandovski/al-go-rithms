:- lib(ic).

queens(N, Board) :-
    dim(Board, [N]),
    Board #:: 1..N,

    ( for(I, 1, N), param(Board, N) do
        ( for(J, I + 1, N), param(Board, I) do
            Board[I] #\= Board[J],
            Board[I] #\= Board[J] + J - I,
            Board[I] #\= Board[J] + I - J
        )
    ),
    
    labeling(Board).