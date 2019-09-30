%Tower of Hanoi

%the first element of move is the amount of disk
%the other is the "name" of the rods

%you use te swipl and then use, for exemple, move(3, 1, 2, 3).
%the program will print the solution 
move(1,X,Y,_) :-
    write('Move the disk from the top o the rod '),
    write(X),
    write(' to the rod '),
    write(Y),
    nl.

move(N,X,Y,Z) :-
    N>1,
    M is N-1,
    move(M,X,Z,Y),
    move(1,X,Y,_),
    move(M,Z,Y,X).

