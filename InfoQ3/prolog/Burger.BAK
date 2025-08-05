%drauf(unten,oben).
drauf(boden, patty).
drauf(patty, fett).
drauf(fett, gurken).
drauf(gurken, zwiebeln).
drauf(zwiebeln, roestzwiebeln).
drauf(roestzwiebeln, ei).
drauf(ei,ketchup).
drauf(ketchup, oben).


zweidrueber(A,ZD):-drauf(A,Zw), drauf(Zw,ZD).

alledrueber(A,B):-drauf(A,B).
alledrueber(A,B):-drauf(A,Zw), alledrueber(Zw,B).
