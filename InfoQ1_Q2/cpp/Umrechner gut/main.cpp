#include <iostream>
using namespace std;
//Eingabe
int dezimalzahl;
string binaerzahl;
string oktalzahl;
string hexadezimalzahl;

//Ausgabe
int zudezimal;
string zubinaer;
string zuoktal;
string zuhexadezimal;

//Hilfsvariablen
int rest;
string b;
int merke, merke2;

string dezToBin(int Dezimalzahl);
string dezToOct(int Dezimalzahl);
string dezToHex(int Dezimalzahl);

int main(int argc, char** argv) {
	
	cout<<"Geben sie eine Dezimahlzahl ein:"<<endl;
	 cin>>dezimalzahl;
	 
	cout<<"In Binär es ist:"<<dezToBin(dezimalzahl)<<endl;
	cout<<"In Oktal es ist: "<<dezToOct(dezimalzahl)<<endl;
	cout<<"In Hexadezimal es ist: "<<dezToHex(dezimalzahl)<<endl;
	

	
//Oktal zu Dezi
/*
cout<<"geben sie eine hexadezimalzahl ein:"<<endl;
cin>>oktalzahl;
	int faktor=1;
	zudezimal=0;
	int merke;
	char ziffer;
	while(oktalzahl.length()>0){
		ziffer = oktalzahl.at(oktalzahl.length()-1)
		
	}
*/	

	
	return 0;
}


string dezToBin(int Dezimalzahl){

	 string zubinaer;
	 while(Dezimalzahl>0){
	 	rest=Dezimalzahl%2;
	 	rest = rest + 48;
	 	cout<<rest<<endl;
		 zubinaer = char(rest)+zubinaer;
	 	Dezimalzahl=Dezimalzahl/2;
	 }
	return zubinaer;
}

string dezToOct(int Dezimalzahl){
	string zuoktal;
	 while(Dezimalzahl>0){
	 	rest=Dezimalzahl%8;
	 	rest = rest + 48;
	 	zuoktal = char(rest)+zuoktal;
	 	Dezimalzahl=Dezimalzahl/8;
	 }
	return zuoktal;
	
}
string dezToHex(int Dezimalzahl){

	string zuhexa;
	 while(Dezimalzahl>0){
	 	rest=Dezimalzahl%16;
	 	if(rest<10){
	 	rest = rest + 48;
		}else{
	 	rest = rest + 55;}
	 	zuhexadezimal = char(rest)+zuhexadezimal;
	 	Dezimalzahl=Dezimalzahl/16;
	 }
	return zuhexa;
}

