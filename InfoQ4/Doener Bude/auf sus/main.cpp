#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>  // F�r stringstream

using namespace std;

// Hilfsfunktion f�r die Umwandlung von double in String
string to_string_custom(double value) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;  // f�r 2 Nachkommastellen
    return ss.str();
}
// Hilfsfunktion f�r die Umwandlung von int in String
string to_string_custom(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}
// Hilfsfunktion f�r die Umwandlung von size_t in String
string to_string_custom(size_t value) {
    stringstream ss;
    ss << value;
    return ss.str();
}



class Produkt{
private:
    string name;
    string kategorie;
    double preis;
    vector<string> zutaten;
    int bestand;
    float rabatt;
public:
    Produkt() {};

    Produkt(string n, string k, double p, vector<string> z, int b, float r)
		: name(n), kategorie(k), preis(p), zutaten(z), bestand(b), rabatt(r) {};

    ~Produkt() {};
	
	virtual string show(){
		string result = "";
		for (size_t i = 0; i < zutaten.size(); i++) {
             string p = zutaten[i];
            result += p + ", ";
        }
        
		return "Das Produkt "+ name + " hat folgende Zutaten: " + result + " ist in der Kategorie: " + kategorie + ", kostet " + to_string_custom(preis) + "EUR, ohne Rabatt und mit " + to_string_custom(preis*(1-rabatt)) + " und ist noch " + to_string_custom(bestand) + " mal verf�gbar";
	}
	

    double getPreis()  { return preis*(1-rabatt); }
    void setPreis(double p) { preis = p; }
    
    float getRabatt()  {return rabatt;}
    void setRabatt( float r)  {rabatt = r;}    

    string getName()  { return name; }
    void setName( string n) { name = n; }

    string getKategorie()  { return kategorie; }
    void setKategorie( string k) { kategorie = k; }

    vector<string> getZutaten()  { return zutaten; }
    void setZutaten( vector<string> z) { zutaten = z; }

    int getBestand()  { return bestand; }
    void setBestand(int b) { bestand = b; }
    
    void reduziereBestand() {bestand--; }

};

class Menu{
	private:
		vector<Produkt*> produkte;
		double mpreis = 0;
		double mrabatt;
		string name = "Menu";
	public:
		Menu(){};
        Menu(vector<Produkt*> p, double r) : produkte(p), mrabatt(r) {};
        ~Menu() { };
		
		void produktHinzufuegen( Produkt* p) {
        	produkte.push_back(p);
        	mpreis += p->getPreis()*(1-mrabatt);
    }

    void produktBearbeiten(int index,  Produkt* p) {
        if (index >= 0  && index < (int)produkte.size()) {
            produkte[index] = p;
        }
    }
	
	string getName()  { return name; }
    void setName( string n)  { name = n; }
    
    void setmPreis( double p)  { mpreis = p; }
    double getmPreis(){double np = berechnePreis();return np;}
    
    vector<Produkt*> getProdukte() {return produkte;};
 
    
    void produktLoeschen(int index) {
        if (index >= 0  && index < (int)produkte.size()) {
            produkte.erase(produkte.begin() + index);
        }
    }
    
    double berechnePreis() {
    	double neuerPreis = 0.0;
    	for (int i = 0; i < produkte.size(); ++i) {
    	    neuerPreis += produkte[i]->getPreis();
    	}
    	return neuerPreis * (1 - mrabatt);
	}


	string show()  {
        string result = "";
        for (size_t i = 0; i < produkte.size(); i++) {
             Produkt* p = produkte[i];
            result += " 	- " + p->getName() + " (" + to_string_custom(p->getPreis()) + " EUR)\n";
        }
        return result;
    }
};


class Doener:public Produkt {
	private:
		string Art;
	public:
		Doener() {};
		Doener(string n, string k, double p, vector<string> z, int b,  float r,string a): Produkt( n,  k,  p, z, b,r), Art(a){};
		Doener(Produkt p, string a): Produkt(p), Art(a){};
		~Doener(){};
		
		string show() {
			return Produkt::show() + " und ist ein D�ner der Art: " + Art;
		}
		
		
};

class Bestellung {
private:
    vector<Produkt*> produkte;
    vector<Menu> menu;
    double gesamtPreis;
    time_t zeitpunkt;
public:
    Bestellung() : gesamtPreis(0), zeitpunkt(time(NULL)) {}
    ~Bestellung(){};
    
    
    vector<Produkt*> getProdukte(){return produkte;}
    
    void produktHinzufuegen(Produkt* p) {
        if (p != NULL  && p->getBestand() > 0) {
            p->reduziereBestand();
			produkte.push_back(p);
			gesamtPreis += p->getPreis();
        }
    }
    
    void produktHinzufuegen( Menu m)  {
        
        
        bool zulassig = true;
        
        vector<Produkt*> p = m.getProdukte();
        
    	for (size_t i = 0; i < p.size(); ++i) {
    		
        	Produkt* pr = p[i];
        	int b = pr->getBestand();
        	if(b>0){
        		pr->reduziereBestand();
			}else{zulassig=false; pr->setBestand(b);}
    	} 
    	if(zulassig = true){
    		menu.push_back(m);
    		gesamtPreis += m.getmPreis();	
		}
    	
    }
    
    void produktLoeschen(int index) {
        if (index >= 0  && index < (int)produkte.size()) {
            produkte.erase(produkte.begin() + index);
            Produkt* pr = produkte[index];
            int b = pr->getBestand();
            pr->setBestand(b+1);
        }
    }

    double getGesamtPreis()  {
        return gesamtPreis;
    }

    time_t getZeitpunkt()  {
        return zeitpunkt;
    }

    string show()  {
        char zeit[20];
       // strftime(zeit, sizeof(zeit), "%d.%m.%Y %H:%M:%S", localtime(zeitpunkt));
        string result = "Die Bestellung:\nBestellung am heute und jetzt"/* + string(zeit) + */"\nProdukte:\n";
        for (size_t i = 0; i < menu.size(); i++) {
             Menu m = menu[i];
            result += " - " + m.getName() + " (" + to_string_custom(m.getmPreis()) + " EUR)\n" + m.show();
        }
        for (size_t i = 0; i < produkte.size(); i++) {
             Produkt* p = produkte[i];
            result += " - " + p->getName() + " (" + to_string_custom(p->getPreis()) + " EUR)\n";
        }
        result += "Gesamtpreis: " + to_string_custom(gesamtPreis) + " EUR";
        return result;
    }
};

class Speisekarte {
private:
    vector<Produkt*> produkte;
    vector<Menu> menues;

public:
	Speisekarte(){};
	~Speisekarte(){};
	
    void produktHinzufuegen( Produkt* p) {
        produkte.push_back(p);
    }
    void produktHinzufuegen( Menu m) {
        menues.push_back(m);
    }

    void produktBearbeiten(int index,  Produkt* p) {
        if (index >= 0  && index < (int)produkte.size()) {
            produkte[index] = p;
        }
    }

    void produktLoeschen(int index) {
        if (index >= 0  && index < (int)produkte.size()) {
            produkte.erase(produkte.begin() + index);
        }
    }

    string show()  {
        string result = "";
        for (size_t i = 0; i < produkte.size(); i++) {
            result += to_string_custom(i + 1) + ". " + produkte[i]->getName() + " (" + produkte[i]->getKategorie() + ") - "
                     + to_string_custom(produkte[i]->getPreis()) + " EUR\n";
        }
        return result;
    }

    string produktPreisAnzeigen( string produktName)  {
        for (size_t i = 0; i < produkte.size(); i++) {
             Produkt* p = produkte[i];
            if (p->getName() == produktName) {
                return "Der Preis von " + produktName + " betr�gt " + to_string_custom(p->getPreis()) + " EUR";
            }
        }
        return "Produkt nicht gefunden.";
    }
};

class Kasse {
private:
    vector<Bestellung> bestellungen;
    double tageseinnahmen;
    Speisekarte speisekarte;

public:
    Kasse(Speisekarte s) : tageseinnahmen(0), speisekarte(s) {}
    ~Kasse(){};

    void bestellungErfassen(Bestellung b) {
        bestellungen.push_back(b);
        tageseinnahmen += b.getGesamtPreis();
    }
	void bestellungBearbeiten(int index,  Bestellung b) {
        if (index >= 0  && index < (int)bestellungen.size()) {
            bestellungen[index] = b;
        }
    }
	void bestellungStornieren(int index) {
        if (index >= 0  && index < (int)bestellungen.size()) {
            bestellungen.erase(bestellungen.begin() + index);
            Bestellung b = bestellungen[index];
            tageseinnahmen = tageseinnahmen - b.getGesamtPreis();
        }
    }
    string tagesEinnahmenAnzeigen()  {
        return "Tageseinnahmen: " + to_string_custom(tageseinnahmen) + " EUR\n";
    }
};

int main() {
    Speisekarte speisekarte;
	Kasse kasse(speisekarte);
    
    
    //Produkte erstellen
    vector<string> zutatenDoener;
	zutatenDoener.push_back("Fleisch");
	zutatenDoener.push_back("Salat");
	zutatenDoener.push_back("Brot");
	Produkt* Doener2 = new Produkt("D�ner", "Hauptgericht", 7.50, zutatenDoener, 10,0);
	speisekarte.produktHinzufuegen(Doener2);
	
	vector<string> zutatenDoener1;
	zutatenDoener1.push_back("Tofu");
	zutatenDoener1.push_back("Salat");
	zutatenDoener1.push_back("Brot");
	Doener* Doener1 = new Doener("D�ner Vegan", "Hauptgericht", 9.50, zutatenDoener, 1,0.20,"Vegan");
	speisekarte.produktHinzufuegen(Doener1);
	
	vector<string> zutatenCola;
	zutatenCola.push_back("Zucker");
	zutatenCola.push_back("Wasser");	
	Produkt* Cola = new Produkt("Cola", "Getr�nke", 2.50, zutatenCola, 20,0.10);
	speisekarte.produktHinzufuegen(Cola);
	
	vector<Produkt*> produkteMenu1;
	produkteMenu1.push_back(Doener2);
	produkteMenu1.push_back(Cola);
	Menu Menu1 = Menu(produkteMenu1, 0.087);
	speisekarte.produktHinzufuegen(Menu1);
	
	vector<Produkt*> produkteMenu2;
	produkteMenu2.push_back(Doener1);
	produkteMenu2.push_back(Doener1);
	Menu Menu2 = Menu(produkteMenu2, 0.093);
	speisekarte.produktHinzufuegen(Menu2);
	
	Bestellung b;
    b.produktHinzufuegen(Menu2);
    b.produktHinzufuegen(Doener2);
    b.produktHinzufuegen(Menu2);
    b.produktHinzufuegen(Menu2);
    b.produktHinzufuegen(Menu2);
    b.produktHinzufuegen(Menu2);
    kasse.bestellungErfassen(b);
    
    Bestellung b1;
    b1.produktHinzufuegen(Menu2);
    b1.produktHinzufuegen(Menu2);
    b1.produktHinzufuegen(Menu2);
    b1.produktHinzufuegen(Menu2);
    kasse.bestellungErfassen(b1);
    
    Bestellung b2;
    b2.produktHinzufuegen(Menu2);
    b2.produktHinzufuegen(Menu2);
    b2.produktHinzufuegen(Doener2);
    b2.produktHinzufuegen(Menu1);
	kasse.bestellungErfassen(b2);
	
	cout<<kasse.tagesEinnahmenAnzeigen()<<endl;
	
	cout<<b2.show();
	
//	string bestellungAnzeige2 = b2.show();
//	cout << endl << endl << bestellungAnzeige2 << endl;
//	cout << endl << Doener1->getBestand();
//	cout << endl << Doener2->getBestand();
//	cout << endl << Cola->getBestand();
	
	
	//abrufen und veranschaulichung
/* 	ALLE SHOWS RAUSGENOMMEN AUFGRUND VON �BERARBEITUNGS BEDARF
	cout<<Doener2.show()<<endl;
	
	cout<<Doener1.show()<<endl;
	
	

    string speisekarteAnzeige = speisekarte.show();
    
    
    
    
    cout << tagesEinnahmen;
    
    
    string bestellungAnzeige = b.show();
	cout << bestellungAnzeige;
	
	string bestellungAnzeige2 = b2.show();
	cout << endl << endl << bestellungAnzeige2;
	*/
    
    delete Cola;
    delete Doener2;
    delete Doener1;
    cin<<a;
    return 0;
}

