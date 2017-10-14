insertToSorted(E, [], [E]).
insertToSorted(E1, [E2|Rest], [E1, E2|Rest]) :- E1 =< E2, !.
insertToSorted(E1, [E2|Rest], [E2|R]) :- \+ (E1 =< E2), insertToSorted(E1, Rest, R), !.

insertSort([],[]).
insertSort([E|Rest], R) :- insertSort(Rest, RAux), insertToSorted(E, RAux, R), !.
