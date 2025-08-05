liste1([-1,1,1,6,7]).
liste2([-3,-1,0,3,18]).

erzeuge(A,B):-liste1(L1), liste2(L2), member(A,L1), member(B,L2).
teste(A,B):-C is 2*A, D is 2*B+5, C>D.
finde(A,B):-erzeuge(A,B), teste(A,B).

