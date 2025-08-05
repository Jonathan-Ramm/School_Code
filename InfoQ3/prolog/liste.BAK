vor(Element,Liste,[Element|Liste]).
rumpf([_|Rumpf],Rumpf).

teilen(0,Liste,[],Liste).
teilen(Wo, [K|R], Vorne, Hinten):- Wo>0, Wo1 is Wo-1,teilen(Wo1,R,Zw,Hinten),vor(K,Zw,Vorne).

loeschen(X,[X|R],R).
loeschen(Was,[K|R],NeueListe):-loeschen(Was,R,Zw), vor(K,Zw,NeueListe).


loeschenWo(1,[K|R],R).
loeschenWo(Wo,[K|R],Erg):-Wo>0, Wo1 is Wo-1, loeschenWo(Wo1,R,Zw), vor(K,Zw,Erg).

laenge([],0).
laenge(Liste,Laenge):-rumpf(Liste,Rumpf),laenge(Rumpf,Zw),Laenge is Zw+1.

drehen([A],[A]).
drehen([K|R],NL):-drehen(R,Zw),vor(K,Zw,ZwE),flatten(ZwE,NL).

verschmelzen([],Liste,Liste)
verschmelzen([K|R],Liste,Erg):-verschmelzen(R,Liste,Zw),vor(K,Zw,Erg).

