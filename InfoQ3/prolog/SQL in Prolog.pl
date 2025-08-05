% Autor: Verbessert 2014 K.Koch
% Datum: 29.09.2011

/********* kanzler.pl ********************
***** kanzler(Name, Partei, Anfang, Ende) **/
kanzler(adenauer, cdu, 1949, 1963).
kanzler(erhardt, , cdu, 1963, 1966).
kanzler(kiesinger, cdu, 1966, 1969).
kanzler(brandt, spd, 1969, 1974).
kanzler(schmidt, spd, 1974, 1982).
kanzler(kohl, cdu, 1982, 1998).
kanzler(schroeder, spd, 1998, 1999).

%1. Wann regierte Adenauer ?
kanzler(adenauer,_,S,_).
%2. Wann war die Regierungszeit von Erhard zu Ende ?
kanzler(erhardt,_,_,X).
%3. Wer regierte 1969?
kanzler(X,_,1969,_).
%4. Gib die Namen aller CDU Kanzler.
kanzler(X,cdu,_,_).
%5. Wer regierte mehr als 10 Jahre?
kanzler(X,_,A,B).10 < B-A
%6. Wer regierte weniger als 6 Jahre?
kanzler(X,_,A,B):-6>B-A
%7. Welche Kanzler regierten in den Achtzigern?
%8. Regierte Kiesinger 1968?
kanzler(kiesinger,_,X,Y),X<=1968<=Y.
%9. Regierte ein CDU-Kanzler 1982?
kanzler(_,cdu,1982,_).
%10. Suche die Regierungsdauer f¸r jeden SPD Kanzler.
%11. In welchen Jahren regierten sowohl ein CDU Kanzler als auch ein SPD Kanzler?
