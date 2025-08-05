#include <iostream>
#include <sstream>
using namespace std;

const int oben=20;

struct dog{
	string hundename;
	string rasse;
	int gbJahr;
	string besitzer;
	string nummer;
	string strasse;
	string plz;
};

dog deinhund;
dog meinhund;
dog dogArray[oben];

void insertSort(dog formalArray[oben]);
int sucheMin(dog formalArray[oben], int links, int rechts);
void selectSort(dog formalArray[oben]);
void tauschedog(dog *a, dog *b);
void eingabe();

string Ausgabe2(dog d);

int main(int argc, char** argv) {
	deinhund.besitzer="Funke";
	deinhund.hundename="Frieda";
	deinhund.nummer="193489";
	deinhund.plz="18480";
	deinhund.rasse="schaefer";
	deinhund.strasse="Veilchenweg";
	
	meinhund.besitzer="Ramm";
	meinhund.hundename="Balu";
	meinhund.gbJahr=2010;
	meinhund.strasse="Birkenweg";
	meinhund.plz="16321";
	meinhund.rasse="Beagle";
	meinhund.nummer="504103805";
		eingabe();
/*	for(int i=0;i<oben;i++){
		cout<<endl<<i<<endl<<Ausgabe2(dogArray[i]);
	}

	cout<<Ausgabe2(deinhund);
*/
/*	selectSort(dogArray);
		for(int i=0;i<oben;i++){
		cout<<endl<<i<<endl<<Ausgabe2(dogArray[i]);
	}
*/
	insertSort(dogArray);
	for(int i=0;i<oben;i++){
		cout<<endl<<i<<endl<<Ausgabe2(dogArray[i]);
	}
	return 0;
}
void insertSort(dog formalArray[oben]){
	int x;
	for(int i=1; i<oben-1; i++){
		cout<<"i"<<i<<endl;
		x=i;
		while(formalArray[x-1].plz>formalArray[x].plz&&x>0){
			tauschedog(&formalArray[x], &formalArray[x-1]);
			x--;
			cout<<x<<endl;
		}
	}
}

void selectSort(dog formalArray[oben]){
	int mini;
	for(int i=0; i<oben-1; i++){
		mini = sucheMin(formalArray, i+1, oben-1);
		if(formalArray[mini].besitzer<formalArray[i].besitzer){
			tauschedog(&formalArray[mini], &formalArray[i]);
		}
	}
	
}
int sucheMin(dog formalArray[oben], int links, int rechts){
	string merke = formalArray[links].besitzer;
	int wo = links;
	for(int i = links+1; i<=rechts; i++){
		if(formalArray[i].besitzer<merke){
			merke=formalArray[i].besitzer;
			wo=i;
		}
	}
	return wo;
}
void tauschedog(dog *a, dog *b){
	dog zw=*a;*a=*b;*b=zw;
}
void eingabe(){
dogArray[0].besitzer = "Max Mustermann";
    dogArray[0].hundename = "Bello";
    dogArray[0].plz = "12345";
    dogArray[0].rasse = "Labrador";
    dogArray[0].strasse = "Hauptstra�e 1";
    dogArray[0].gbJahr = 2010;
    dogArray[0].nummer = "163264";

    dogArray[1].besitzer = "Maria Musterfrau";
    dogArray[1].hundename = "Luna";
    dogArray[1].plz = "54321";
    dogArray[1].rasse = "Golden Retriever";
    dogArray[1].strasse = "Nebenstra�e 2";
    dogArray[1].gbJahr = 2015;
    dogArray[1].nummer = "85726";

    dogArray[2].besitzer = "Hans Hundeliebhaber";
    dogArray[2].hundename = "Rex";
    dogArray[2].plz = "98765";
    dogArray[2].rasse = "Deutscher Sch�ferhund";
    dogArray[2].strasse = "Gasse 3";
    dogArray[2].gbJahr = 2012;
    dogArray[2].nummer = "034689345";
        dogArray[0].besitzer = "Laura Liebhaberin";
    dogArray[5].hundename = "Buddy";
    dogArray[5].plz = "56789";
    dogArray[5].rasse = "Chihuahua";
    dogArray[5].strasse = "Parkweg 4";
    dogArray[5].gbJahr = 2018;
    dogArray[5].nummer = "946830974";

    dogArray[6].besitzer = "Felix Freund";
    dogArray[6].hundename = "Rocky";
    dogArray[6].plz = "43210";
    dogArray[6].rasse = "Bulldogge";
    dogArray[6].strasse = "Alleestra�e 5";
    dogArray[6].gbJahr = 2016;
    dogArray[6].nummer = "2357326080";

    dogArray[7].besitzer = "Sabine Tierfreund";
    dogArray[7].hundename = "Daisy";
    dogArray[7].plz = "34567";
    dogArray[7].rasse = "Dackel";
    dogArray[7].strasse = "Feldweg 8";
    dogArray[7].gbJahr = 2013;
    dogArray[7].nummer = "09487602745";

    dogArray[3].besitzer = "Markus Hundliebhaber";
    dogArray[3].hundename = "Charlie";
    dogArray[3].plz = "87654";
    dogArray[3].rasse = "Beagle";
    dogArray[3].strasse = "Bergstra�e 10";
    dogArray[3].gbJahr = 2017;
    dogArray[3].nummer = "987236897";

    dogArray[4].besitzer = "Julia Tiersch�tzerin";
    dogArray[4].hundename = "Lola";
    dogArray[4].plz = "10987";
    dogArray[4].rasse = "Mops";
    dogArray[4].strasse = "Wiesenweg 3";
    dogArray[4].gbJahr = 2014;
    dogArray[4].nummer = "0876028";
    
    dogArray[8].besitzer = "Sophie Tierfreundin";
    dogArray[8].hundename = "Maxi";
    dogArray[8].plz = "76543";
    dogArray[8].rasse = "Pudel";
    dogArray[8].strasse = "Querstra�e 12";
    dogArray[8].gbJahr = 2019;
    dogArray[8].nummer = "803275680237609";

    dogArray[9].besitzer = "Tom Hundefreund";
    dogArray[9].hundename = "Molly";
    dogArray[9].plz = "23456";
    dogArray[9].rasse = "Siberian Husky";
    dogArray[9].strasse = "Bachweg 7";
    dogArray[9].gbJahr = 2016;
    dogArray[9].nummer = "14750428";
    
    dogArray[10].besitzer = "Anna Hundeliebhaberin";
    dogArray[10].hundename = "Rusty";
    dogArray[10].plz = "54321";
    dogArray[10].rasse = "Boxer";
    dogArray[10].strasse = "Wiesenstra�e 15";
    dogArray[10].gbJahr = 2017;
    dogArray[10].nummer = "094798";

    dogArray[11].besitzer = "David Tierfreund";
    dogArray[11].hundename = "Rosie";
    dogArray[11].plz = "98765";
    dogArray[11].rasse = "Dalmatiner";
    dogArray[11].strasse = "Bergweg 20";
    dogArray[11].gbJahr = 2015;
    dogArray[11].nummer = "9876357629846";

    dogArray[12].besitzer = "Melanie Hundefreundin";
    dogArray[12].hundename = "Coco";
    dogArray[12].plz = "23456";
    dogArray[12].rasse = "Shih Tzu";
    dogArray[12].strasse = "Parkallee 3";
    dogArray[12].gbJahr = 2018;
    dogArray[12].nummer = "98726873986";

    dogArray[13].besitzer = "Kevin Hundeliebhaber";
    dogArray[13].hundename = "Baxter";
    dogArray[13].plz = "87654";
    dogArray[13].rasse = "Australian Shepherd";
    dogArray[13].strasse = "Querweg 8";
    dogArray[13].gbJahr = 2016;
    dogArray[13].nummer = "764983525";

    dogArray[14].besitzer = "Sophia Tierfreundin";
    dogArray[14].hundename = "Zeus";
    dogArray[14].plz = "76543";
    dogArray[14].rasse = "Rottweiler";
    dogArray[14].strasse = "Bachstra�e 7";
    dogArray[14].gbJahr = 2014;
    dogArray[14].nummer = "8726387";

    dogArray[15].besitzer = "Mark Hundefreund";
    dogArray[15].hundename = "Lucky";
    dogArray[15].plz = "10987";
    dogArray[15].rasse = "Schnauzer";
    dogArray[15].strasse = "Alleeweg 12";
    dogArray[15].gbJahr = 2019;
    dogArray[15].nummer = "7437603876407";

    dogArray[16].besitzer = "Isabella Hundeliebhaberin";
    dogArray[16].hundename = "Oscar";
    dogArray[16].plz = "12345";
    dogArray[16].rasse = "Cavalier King Charles Spaniel";
    dogArray[16].strasse = "Gassenweg 5";
    dogArray[16].gbJahr = 2015;
    dogArray[16].nummer = "876208720846";

    dogArray[17].besitzer = "Liam Tierfreund";
    dogArray[17].hundename = "Bentley";
    dogArray[17].plz = "43210";
    dogArray[17].rasse = "Basset Hound";
    dogArray[17].strasse = "Feldallee 10";
    dogArray[17].gbJahr = 2017;
    dogArray[17].nummer = "8972648724895";

    dogArray[18].besitzer = "Ava Hundefreundin";
    dogArray[18].hundename = "Mocha";
    dogArray[18].plz = "56789";
    dogArray[18].rasse = "Corgi";
    dogArray[18].strasse = "Waldweg 8";
    dogArray[18].gbJahr = 2016;
    dogArray[18].nummer = "2538235289735";

    dogArray[19].besitzer = "Noah Hundeliebhaber";
    dogArray[19].hundename = "Lexi";
    dogArray[19].plz = "87654";
    dogArray[19].rasse = "Pomeranian";
    dogArray[19].strasse = "Steigweg 3";
    dogArray[19].gbJahr = 2018;
    dogArray[19].nummer = "38739286749";
	
}

string Ausgabe2(dog d){
	
	stringstream g; string alles="";
	alles="\n Besitzer: "+d.besitzer+"\n nummer: "+d.nummer+"\n stra�e: "+d.strasse+"\n name: "+d.hundename+"\n plz: "+d.plz+"\n rasse: "+d.rasse;
	return alles;
}


