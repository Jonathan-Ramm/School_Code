#include <iostream>


using namespace std;


class CProdukt {
private:
    string Name;
    string Kategorie;
    string Preis;
    string Zutaten[20]; // Liste?
    string Menu;

public:
	CProdukt(){
		Name="Döner Schrippe";
		Kategorie="Backwaren";
		Preis="0.7€";
		Zutaten=["Teig","Gewürze","Soße"];
		Menu="Kein";
	};
	
	
	
    string getName()  {
        return Name;
    }
    void setName(const string& name) {
        Name = name;
    }
    string getKategorie()  {
        return Kategorie;
    }
    void setKategorie(const string& kategorie) {
        Kategorie = kategorie;
    }
    string getPreis()  {
        return Preis;
    }
    void setPreis(const string& preis) {
        Preis = preis;
    }

string getZutaten() const {
	int index = 0;
	while(index<21){
		if (index >= 0) {
            return Zutaten[index];
        }else{
            return string(""); // Rückgabe eines leeren Strings, wenn der Index ungültig ist
		}
		index++;
	}
        
    };

    void setZutat(int index, const string& zutat) {
        if (index >= 0 && index < 21) {
            Zutaten[index] = zutat;
        }
    };

    string getMenu()  {
        return Menu;
    }
    void setMenu(const string& menu) {
        Menu = menu;
    }
};
int main(){
	return 0;
};
