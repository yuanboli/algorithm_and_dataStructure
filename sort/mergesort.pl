/*this implements a merge sort in prolog*/

mergesort([],[]):- !.
mergesort([H], [H]):- !.
mergesort(L, R):- 
	split(L, L1, L2),
	mergesort(L1, R1),
	mergesort(L2, R2),
	sort2lists(R1, R2, R).

split([], [], []).
split([H], [H], []).
split([H1, H2|T], [H1|L1], [H2|L2]):-
	split(T, L1, L2).

sort2lists([], L, L).
sort2lists(L, [], L).
sort2lists([H1|T1], [H2|T2], [H1|L]):-
	H1 < H2,
	sort2lists(T1, [H2|T2], L).
sort2lists([H1|T1], [H2|T2], [H2|L]):-
	H1 >= H2,
	sort2lists([H1|T1], T2, L).
