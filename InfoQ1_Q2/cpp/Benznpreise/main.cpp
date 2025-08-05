#include <iostream>
using namespace std;


//Eingaben	

float gefahrenekm , verbrauchteliter, superplus, supere10, diesel, verbrauch,Kraftstoffp;
short kraftstoff=-1;

//Ausgaben

float verbrauchje100, kostenje100;


int main(int argc, char** argv) {
	
	superplus	 = 1.659;
	supere10	 = 1.609;
	diesel		 = 1.519;
	
		cout<<"Das ist ein Benzinrechner, der den Verbrauch und die Kosten je 100km berechnet\n";
	
		cout<<"Geben sie die gefahrenen km ein:"<<endl;
		cin>>gefahrenekm;
		
		cout<<"Geben sie den benutzten Kraftstoff ein: (1:SuperPlus; 2:SuperE10; 3:Diesel)"<<endl;
		cin>>kraftstoff;
		if(kraftstoff >3 ||kraftstoff <1){
		do{
			cout<<"Wir fahren doch nicht mit Atomenergie!!";
			cout<<"Geben sie den benutzten Kraftstoff ein: (1:SuperPlus; 2:SuperE10; 3:Diesel)"<<endl;
			cin>>kraftstoff;
		}while(kraftstoff >3 ||kraftstoff <1);
		}
		float x, y;
		
		if(kraftstoff==1){	
			Kraftstoffp=superplus;
		}
		
		if(kraftstoff==2){
			Kraftstoffp=supere10;
		}
		
		if(kraftstoff==3){
			Kraftstoffp=diesel;		
		}
		
		int option = -1;
		cout<<"Verbauch(2) oder Verbrauchte(1)"<<endl;
		cin>>option;
		switch(option){
			case 1:
				cout<<"Geben sie die verbrauchten liter ein:"<<endl;
				cin>>verbrauchteliter;

				
				x=verbrauchteliter*100/gefahrenekm;	
				cout<<"Sie verbrauchen "<<x<<" Liter pro 100km"<<endl;
				break;
				
			case 2:
				cout<<"Geben Sie den durschnittlichen Verbrauch ein"<<endl;
				cin>>verbrauch;
				x = verbrauch;
				float verbrauchte=verbrauch/100*gefahrenekm;
				cout<<"Sie sollten für "<<gefahrenekm<<"km ungefähr "<<verbrauchte<<" Liter verbraucht haben."<<endl;
				float preis = verbrauchte * Kraftstoffp; 
				cout<<"Diese Strecke kostet Sie: "<<preis<<"€"<<endl;
				break;
							
		}
		
		y=x*Kraftstoffp;
		
		cout<<"Ihr Sprit kostet "<<y<<" Euro pro 100km"<<endl;	
	
		
	
	return 0;
}
