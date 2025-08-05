#include <iostream>
using namespace std;

int zahl1;
int zahl2;


int addition(int zahl1,int zahl2);
int multiplikation(int zahl1, int zahl2);
int fakultaet(int zahl1,int zahl2);

int main(int argc, char** argv) {
	
	cout<<multiplikation(7, 4)<<endl;
	cout<<addition(7, 4)<<endl;	
	cout<<fakultaet(7, 4)<<endl;
	return 0;
}

string umdrehen(string eingabe, int anzahl, string m){
	anzahl = eingabe.length();
	if(anzahl = 0 ){
		return "";
	}else{
		eingabe.erase(0,1)=m;
		return umdrehen(m)+eingabe.substr(anzahl, 1);
		anzahl = anzahl-1;
	}
}

/*int multiplikation(int zahl1,int zahl2){
	if(zahl2 == 1){
		return zahl1;
	}else{
		return multiplikation(zahl1, zahl2-1)+zahl1;
	}
}


int addition(int zahl1 , int zahl2){
	if(zahl2 == 0){
		return zahl1;
	}else{
		return addition(zahl1, zahl2-1)+1;
	}
}


int fakultaet (int n){
	/*Abbruchbedingung*/
/*	if(n == 0){
		return 1;
	} else{
		/*rekursiver Aufruf*/
/*		return n * fakultaet(n-1);
	}
}*/
