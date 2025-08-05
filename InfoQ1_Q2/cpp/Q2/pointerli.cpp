#include <iostream>
using namespace std;

int i = 64;
string s="Hallo Welt!";
bool b = false;

int *pointAufi = &i;
string *pointAufs = &s;
bool *pointAufb = &b;

int main(){
	cout<<"Die variable i ist ein integer und hat den Wert: "<<i<<endl;
	cout<<"Die variable s ist ein string und hat den Wert: "<<s<<endl;
	cout<<"Die variable b ist ein bool und hat den Wert: "<<b<<endl;
	cout<<endl;
	cout<<"Die variable i ist ein integer und die Adresse ist: "<<&i<<endl;
	cout<<"Die variable s ist ein string und die Adresse ist: "<<&s<<endl;
	cout<<"Die variable b ist ein bool und die Adresse ist: "<<&b<<endl;
	cout<<endl;
	cout<<"Die variable pointAufi ist ein integer und hat den Wert: "<<pointAufi<<endl;
	cout<<"Die variable pointAufs ist ein string und hat den Wert: "<<pointAufs<<endl;
	cout<<"Die variable pointAufb ist ein bool und hat den Wert: "<<pointAufb<<endl;
	cout<<endl;
	cout<<"Die variable pointAufi ist ein integer und die Adresse ist: "<<&pointAufi<<endl;
	cout<<"Die variable pointAufs ist ein string und die Adresse ist: "<<&pointAufs<<endl;
	cout<<"Die variable pointAufb ist ein bool und die Adresse ist: "<<&pointAufb<<endl;
	cout<<endl;
	*pointAufs="Hallo Du";
	cout<<"Die variable s ist ein string und hat den Wert: "<<s<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
