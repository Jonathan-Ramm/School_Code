addi(A,0,A).
addi(A,B,Erg):- B>0,!,B1 is B-1, addi(A,B1,Zw),Erg is Zw+1.
addi(A,B,Erg):- B<0,!,B1 is B+1, addi(A,B1,Zw),Erg is Zw-1.
