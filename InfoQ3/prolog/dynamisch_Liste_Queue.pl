% :- dynamic (init/0)
% :- assert (hinzufügen)
% :- retract (wegwerfen)

kopf([K|_],K).
rumpf([_|R],R).

:-dynamic init/0.
initStack:-assert(stack([])).
push(A):-stack(S),append([A],S,SN),retract(stack(S)),assert(stack(SN)).

top:-stack(S),rumpf(S,SN),kopf(S,K),write(K),retract(stack(S)),assert(stack(SN)).

pop:-stack(S),rumpf(S,SN),retract(stack(S)),assert(stack(SN)).

initQueue:-assert(queue([])).

enQ(A):-queue(Q),append(Q,[A],QN),retract(queue(Q)),assert(queue(QN)).

first:-queue(Q),rumpf(Q,QN),write(Q),retract(queue(Q)),assert(queue(QN)).

deQ:-queue(Q),rumpf(Q,QN),retract(queue(Q)),assert(queue(QN)).


