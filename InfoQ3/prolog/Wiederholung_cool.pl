potenz(A,0,1).
potenz(A,B,Erg):-B>0,B1 is B-1, potenz(A,B1,Zw),Erg is Zw*A.

rest(A,B,A):-A<B.
rest(A,B,Erg):-A>=B,A1 is A-B, rest(A1,B,Erg).

ggT(A,B,B):-Erg is A mod B, Erg ==0.
ggT(A,B,Erg):-C is A mod B, ggT(B,C,Erg).

fibo(1,1).
fibo(0,1).
fibo(A,Erg):- A1 is A-1, A2 is A-2, fibo(A1,Zw1),fibo(A2,Zw2), Erg is Zw1+Zw2.

gD(A,B,0):-A<B.
gD(A,B,Erg):-A>=B,A1 is A-B, gD(A1,B,Zw), Erg is Zw+1.
