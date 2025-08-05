#include <iostream>
using namespace std;

//Globale Variablen
short eingabe;
int zahl1=360859847673936;
int zahl2=86988684;
int ergebnis;

//Unterprogramme, Prozedur, Deklaration
void malesterne(int anzahl);
void kuerzen(int *zeahler,int *nenner);
//Unterprogramme, Funktionen, Deklaration
int ganzzahligeDivision(int divident, int divisor);
int restDivision(int divident, int divisor);
int ggT(int gross, int klein);


int main(int argc, char** argv) {
	cout<<"Geben Sie die Anzahl der Sterne an"<<endl;
	cin>>eingabe;
	//Aufruf
	malesterne(eingabe);
	ergebnis = ganzzahligeDivision(zahl1,zahl2);
	cout<<"Division: "<<ergebnis<<endl;
	ergebnis = restDivision(zahl1,zahl2);
	cout<<"rest: "<<ergebnis<<endl;
	ergebnis=ggT(zahl1, zahl2);
	cout<<"ggT: "<<ergebnis<<endl;
	
	cout<<zahl1<<" / "<<zahl2<<"  gekürzt = ";
	kuerzen(&zahl1, &zahl2);
	cout<<zahl1<<"/"<<zahl2<<endl;
	return 0;
}


//Implementation - das wie geht das
void kuerzen(int *zaehler,int *nenner){
	int teiler=ggT(*zaehler, *nenner);
	*zaehler = *zaehler/teiler;
	*nenner = *nenner /teiler;
	
}

int ggT(int gross, int klein){
	int rest = 1;
	while(rest>0){
		rest	= gross%klein;
		gross 	= klein;
		klein 	= rest;
	}
	return gross;
}

int restDivision(int divident, int divisor){
	while(divident>=divisor){
		divident = divident - divisor;
	}
	return divident;
}

int ganzzahligeDivision(int divident, int divisor){
	int merke = 0;
	while(divident>=divisor){
		divident = divident - divisor;
		merke++;
	}
	return merke;
}

void malesterne(int anzahl){
	for (int i = 0; i<anzahl; i++){
		cout<<"*";
	}
	cout<<endl;
}
