% :- dynamic (init/0)
% :- assert (hinzufügen)
% :- retract (wegwerfen)

:-dynamic init/0.
kopf([K|_],K).
rumpf([_|R],R).

init:-assert(stack([])).

isEmpty:-stack([]).

push(El):-stack(Stack),append([El],Stack,NewStack),retract(stack(Stack)),assert(stack(NewStack)).

pop:-stack(Stack),rumpf(Stack,NewStack),write(Stack),retract(stack(Stack)),assert(stack(NewStack)).

top:-stack(Stack),rumpf(Stack,NewStack),retract(stack(Stack)),assert(stack(NewStack)).
