insertionsort([],[]).
insertionsort([H|T], L):-
	insertionsort(T, L1),
	insert_in_place(H, L1, L).
insert_in_place(H, [], [H]):- !.
insert_in_place(Ele, [H|T], [H|L]):-
	H < Ele,
	!,
	insert_in_place(Ele, T, L).
insert_in_place(Ele, L, [Ele|L]).
