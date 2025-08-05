#include <iostream>
using namespace std;

int a	= 20;
int b	= 1000;
int 	*az;

void tausche(int *z1, int *z2){
	int merke ;
	merke = *z1;
	*z1 = *z2;
	*z2 = merke;
	
};

int main(int argc, char** argv) {
/*	cout<<"Der Wert ist: "<<a<<endl;
	cout<<"Der Speicherplatz von a hat die Adresse: "<<&a<<endl;
	cout<<"Der Speicherplatz von b hat die Adresse: "<<&b<<endl;
	
	cout<<"Der Inhalt vom Pointer az vor der Initialisierung: "<<az<<endl;
	
	az = &a;
	cout<<"Der Inhalt vom Pointer az nach der Initialisierung: "<<az<<endl;	
	
	cout<<"Der Speicherplatz von az hat die Adresse: "<<&az<<endl;		
	
	*az = 10000;
	cout<<"Der Wert ist: "<<a<<endl;
*/	
	cout<<"Der Wert von a ist: "<<a<<endl;
	cout<<"Der Wert von b ist: "<<b<<endl;	
	
	tausche(&a, &b);
	
	cout<<"Der Wert von a ist: "<<a<<endl;	
	cout<<"Der Wert von b ist: "<<b<<endl;	
	
	
	return 0;
}


