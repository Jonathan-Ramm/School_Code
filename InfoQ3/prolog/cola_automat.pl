%delta(Zustand, Eingabe, Folgezustand)
delta(s0, 50, s1).
delta(s0,100, s2).
delta(s1,50, s2).
delta(s1,100, s3).

delta(s2,50, s3).
delta(s2,100,s0).
delta(s3,50,s0).
delta(s3,100,s0).

%lambda(Zustand, Eingabe, Ausgabe)
lambda(s0, 50, "fehlen 1.5").
lambda(s0,100, "fehlen 1").
lambda(s1,50, "fehlen 1").
lambda(s1,100, "fehlen 0.5").

lambda(s2,50, "fehlen 0.5").
lambda(s2,100,"Cola").
lambda(s3,50,"Cola").
lambda(s3,100,"Cola").


start():-write("Geben Sie 50 oder 100 ein!"),nl, read(Ein),endlos(s0,Ein).
endlos(Z,Ein):- lambda(Z,Ein,Aus), write(Aus), delta(Z,Ein,FZ),nl, write("geben Sie ein"), read(Ein2),endlos(FZ,Ein2) .

