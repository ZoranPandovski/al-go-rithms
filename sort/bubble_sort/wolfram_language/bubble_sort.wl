#!/usr/bin/env -S wolfram -script

(*
	bubblesort takes a list as argument and repeatedly applies a substitution 
	until the pattern can't be matched anymore.
	
	The pattern '{left___, x_, y_, right___} /; y < x' matches any list where
	two elements x and y with y < x exist. 
	'left___' and 'right___' are BlanckNullSequences, i.e. sequences with
	variable length (zero length sequences allowed).
	The above pattern then gets replaced with the similar pattern
	'{left, y, x, right}', where y and x are switched.

	Note: ReplaceRepeated[pattern][list] can be written as list .// pattern in
	      short form.
*)

bubblesort[list_] := ReplaceRepeated[
		{left___, x_, y_, right___} /; y < x -> {left, y, x, right}
	][list];

(*Example list*) 
list = {1, 52, 55, 100, 100, 26}
Print[bubblesort[list]]
