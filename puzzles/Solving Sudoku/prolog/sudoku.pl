/* 
 * A Simple Nine by Nine Sudoku Puzzle Solver written in Prolog
 * 
 * Adapted By: ngweihow https://github.com/ngweihow
 * Adapted from Sudoku by Peter Schachte (School of CIS, The University of Melbourne)
 */

%--------------------------------------------------------------
% Code

:- use_module(library(clpfd)).

% Sudoku Predicate
sudoku(Rows) :-
    length(Rows, 9), maplist(same_length(Rows), Rows),
    append(Rows, Vs), Vs ins 1..9,
    maplist(all_distinct, Rows),
    transpose(Rows, Columns),
    maplist(all_distinct, Columns),
    Rows = [A,B,C,D,E,F,G,H,I],
    blocks(A, B, C), blocks(D, E, F), blocks(G, H, I).

% Format Recognising Predicate
blocks([], [], []).
blocks([A,B,C|Bs1], [D,E,F|Bs2], [G,H,I|Bs3]) :-
    all_distinct([A,B,C,D,E,F,G,H,I]),
    blocks(Bs1, Bs2, Bs3).


%--------------------------------------------------------------
% Test Inputs

% To load the predicates into swipl:
% 	[sudoku].


% To run test 1:
/*
Puzzle=[[5,3,_, _,7,_, _,_,_],[6,_,_, 1,9,5,_,_,_],[_,9,8, _,_,_, _,6,_],[8,_,_, _,6,_,_,_,3],[4,_,_, 8,_,3, _,_,1],[7,_,_, _,2,_, _,_,6],[_,6,_, _,_,_,2,8,_],[_,_,_, 4,1,9,_,_,5],[_,_,_, _,8,_, _,7,9]],    

sudoku(Puzzle),
write(Puzzle).
*/

% To run test 2:
/*
Puzzle2=[[_,_,6, _,5,4, 9,_,_],[1,_,_, _,6,_,_,4,2],[7,_,_, _,8,9, _,_,_],[_,7,_, _,_,5,_,8,1],[_,5,_, 3,4,_, 6,_,_],[4,_,2, _,_,_, _,_,_],[_,3,4, _,_,_,1,_,_],[9,_,_, 8,_,_,_,5,_],[_,_,_, 4,_,_, 3,_,7]],

sudoku(Puzzle2),
write(Puzzle2).
*/


