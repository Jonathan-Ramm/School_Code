farbe(rot).
farbe(blau).
farbe(gelb).

kombi(A,B,C,D):-farbe(A), farbe(B), farbe(C), farbe(D),
A \== B, A \== C, B \== C, D \== B, D\==C.

