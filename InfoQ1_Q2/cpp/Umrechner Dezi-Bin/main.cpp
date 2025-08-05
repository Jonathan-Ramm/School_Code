#include <iostream>
using namespace std;

//Eingabe Dezimal
int eingabe=73;

//Ausgbe Binär
string binaer;

//Hilfsvariablen
int rest, quotient;


int main(int argc, char** argv) {
	
	cout<<"Geben sie die gewünschte Zahl ein"<<endl;
	cin>>eingabe;
	
	cout<<"die ganzzahlige Division von "<<eingabe<<" ist:"<<endl;
	while(eingabe>0){
		rest=eingabe % 2;
		//cout<<"Rest "<<rest<<endl;
		if(rest==1){
			binaer="1"+binaer;
		}else{
			binaer="0"+binaer;
		}
		quotient=eingabe/2;
		//cout<<"Ergebnis ganzzahlige Division "<<quotient<<endl;
		
		eingabe=quotient;
	}
	
//	cout<<"das Ergebnis ist: ";
	
	cout<<binaer<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
