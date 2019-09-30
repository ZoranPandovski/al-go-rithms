% The "left of" predicate
left([fleft |_], [left  |_]).
left([left  |_], [center|_]).
left([center|_], [right |_]).
left([right |_], [fright|_]).

left(A, B, L) :-
  member(A, L),
  member(B, L),
  left(A, B).

% The "next to" predicate
next(A, B, L) :- left(A, B, L).
next(A, B, L) :- left(B, A, L).

% "G" is a list of attribute lists for each person, each in form:
% [Position, Nationality, Color, Pet, Drink, Smoke]
puzzle(G) :-
  % 0. Structural constraint:
  % The number of guests should be 5
  length(G, 5),

  % 1. Constraints, as corresponding to the text
  %  (following verbatim in comments):
  % The Englishman lives in the red house
  member([_, englishman, red, _, _, _], G),
  % The Swede keeps dogs
  member([_, swede, _, dogs, _, _], G),
  % The Dane drinks tea
  member([_, dane, _, _, tea, _], G),
  % The green house is just to the left of the white one
  left([_, _, green, _, _, _], [_, _, white, _, _, _], G),
  % The owner of the green house drinks coffee
  member([_, _, green, _, coffee, _], G),
  % The Pall Mall smoker keeps birds
  member([_, _, _, birds, _, pallmall], G),
  % The owner of the yellow house smokes Dunhills
  member([_, _, yellow, _, _, dunhill], G),
  % The man in the center house drinks milk
  member([center, _, _, _, milk, _], G),
  % The Norwegian lives in the first house
  member([fleft, norwegian, _, _, _, _], G),
  % The Blend smoker has a neighbor who keeps cats
  next([_, _, _, _, _, blend], [_, _, _, cats, _, _], G),
  % The man who smokes Blue Masters drinks bier
  member([_, _, _, _, bier, bluemasters], G),
  % The man who keeps horses lives next to the Dunhill smoker
  next([_, _, _, _, _, dunhill], [_, _, _, horses, _, _], G),
  % The German smokes Prince
  member([_, german, _, _, _, prince], G),
  % The Norwegian lives next to the blue house
  next([_, norwegian, _, _, _, _], [_, _, blue, _, _, _], G),
  % The Blend smoker has a neighbor who drinks water
  next([_, _, _, _, _, blend], [_, _, _, _, water, _], G),

  % 3. Implicit constraints:
  % Pad with information about unmentioned atoms
  member([left, _, _, _, _, _], G),
  member([right, _, _, _, _, _], G),
  member([fright, _, _, _, _, _], G),
  member([_, _, _, fish, _, _], G).


:- initialization main.
main :-
  puzzle(G),
  format('Solution: ~w\n', [G]),
  halt(0).
