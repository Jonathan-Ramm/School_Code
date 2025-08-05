al(s,[t,x,z]).
al(t,[x,y,s]).
al(x,[y,w,v,u,z,s,t]).
al(z,[u,w,x,s]).
al(v,[u,x,w]).
al(w,[v,x,z]).
al(u,[v,x,z]).
al(y,[x,t]).



tiefensuche(A,B):-ts(A,B,[],[]).

%ts(A,B,[],[])
ts(B,B,Stack,Besucht):-append(Besucht,[B],NeuBesucht),write(NeuBesucht).
ts(A,B,Stack,Besucht):-append(Besucht,[A],NeuBesucht), al(A,NFL), append(NFL,Stack,NeuStack), subtract(NeuStack,NeuBesucht,[K|Reststack]), ts(K,B,Reststack,NeuBesucht).

breitensuche(A,B):-bs(A,B,[],[]).

bs(A,A,Queue,Besucht):-append(Besucht,[A],NeuBesucht),write(NeuBesucht).
bs(A,B,Queue,Besucht):-append(Beuscht,[A], NeuBesucht), al(A,NFL), append(Queue,NFL,NeuQueue), subtract(NeuQueue,NeuBesucht,(K|RestQueue)), bs(K,B,RestQueue,NeuBesucht.)

