adam([biggi,corina]).
bert([biggi,doris]).
claus([anna,doris,eva]).
dirk([anna,corina]).

finde(A,B,C,D):-adam(L1),bert(L2),claus(L3),dirk(L4),member(A,L1),member(B,L2),member(C,L3),member(D,L4).
teste(A,B,C,D):-A\==B,A\==C,A\==D,B\==C,B\==D,C\==D.
erzeuge(A,B,C,D):-finde(A,B,C,D),teste(A,B,C,D).
