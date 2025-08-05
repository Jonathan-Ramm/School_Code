%Wiederholung:

rumpf([_|R],R).
kopf(K,[K|_]).

laenge([],0).
laenge([K|R],L):-laenge(R,Zw), L is Zw+1.

vorsetzen(E,L,[E|L]).

teilenStelle(1,[K|R],[K],R).
teilenStelle(X,[K|R],Vorne, Hinten):- X>1, S1 is X-1, teilenStelle(S1,R,Zw,Hinten),vorsetzen(K,Zw,Vorne).


teilenElement(E,[E|R],[E],R).
teilenElement(E,[K|R],V,H):-teilenElement(E,R,Zw,H),vorsetzen(K,Zw,V).

drin(E,[E|_]).
drin(E,[K|R]):-drin(E,R).

woIstWas(1,[E|_],E).
woIstWas(Wo,[K|R],Was):- woIstWas(Wo,R,Zw), Was is Zw+1.

drehen([X],[X]).
drehen([K|R],Erg):-drehen(R,Zw),vorsetzen(Zw,[K],E),flatten(E,Erg).

letztesWeg([E],[]).
letztesWeg([K|R],Erg):-letztesWeg(R,Zw),vorsetzen([K],Zw,E),flatten(E,Erg).


letzte4([A,B,C,D],[]).
letzte4([K|R],Erg):-letzte4(R,Zw),vorsetzen([K],Zw,E),flatten(E,Erg).



