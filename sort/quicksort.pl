/*first parameter is original List, the other is the sorted list*/
/*do not support reverse way in gprolog*/
quicksort([],[]):-!.
quicksort([H|T], L):-
	split(T, H, L1, L2),
	quicksort(L1, Left),
	quicksort(L2, Right),
	append(Left, [H|Right], L), !.

/*first parameter is the list to be splited
  second parameter is the pivot
	third parameter is the left side sublist
	fourth parameter is the right side sublist
*/
split([], _, [], []).
split([H|L], P, [H|L1], L2):-
	H < P,
	split(L, P, L1, L2).
split([H|L], P, L1, [H|L2]):-
	H >= P,
	split(L, P, L1, L2).
	
