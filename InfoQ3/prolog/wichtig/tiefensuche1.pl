al(s,[t,x,z]).
al(t,[s,x,y]).
al(u,[v,x,z]).
al(v,[u,w,x]).
al(w,[v,x,z]).
al(x,[s,t,u,v,w,y,z]).
al(y,[t,x]).
al(z,[s,u,w,x]).

tiefensuche(A,B):-ts(A,B,[],[]).


ts(A,A,_,Besucht):-append(Besucht,[A],NeuBesucht),write(NeuBesucht).
ts(A,B,Stack,Besucht):-append(Besucht,[A],NeuBesucht),
             al(A,NachfolgerListe),
             append(NachfolgerListe,Stack, NeuStack),
             subtract(NeuStack,NeuBesucht,[K|RestStack]),
             ts(K,B,RestStack,NeuBesucht).
             
breitensuche(A,B):-bs(A,B,[],[]).


bs(A,A,_,Besucht):-append(Besucht,[A],NeuBesucht),write(NeuBesucht).
bs(A,B,Q,Besucht):-append(Besucht,[A],NeuBesucht),
             al(A,NachfolgerListe),
             append(Q,NachfolgerListe, NeuQ),
             subtract(NeuQ,NeuBesucht,[K|RestQ]),
             bs(K,B,RestQ,NeuBesucht).
