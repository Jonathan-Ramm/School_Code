#include <iostream>
#include <sstream>

using namespace std;
// Klassendefinition()- {Implementation}
class TDatum{

private:
    int Tag;
    int Monat;
    int Jahr;
public:
    // Konstruktor
    TDatum(){
        Tag   = 1;
        Monat = 1;
        Jahr  = 1970;
        
        cout<<"Konstruktor von TDatum aufgerufen"<<endl;
    };
    TDatum(int pTag, int pMonat, int pJahr){
        Tag   = pTag;
        Monat = pMonat;
        Jahr  = pJahr;
        cout<<"überladener Konstruktor von TDatum aufgerufen"<<endl;
    };
    ~TDatum(){cout<<"Destruktor von TDatum aufgerufen"<<endl;};
    // getter - Lesezugriff
    int getTag(){ return Tag; };
    int getMonat(){return Monat;};
    int getJahr(){return Jahr;};
    // setter -Schreibzugriff
    void setTag(int pTag){Tag = pTag;};
    void setMonat(int pMonat){Monat = pMonat;};
    void setJahr(int pJahr){Jahr = pJahr;};
    string show(){
        stringstream t,m,j;
        t<<Tag;
        m<<Monat;
        j<<getJahr();
        return t.str()+"."+m.str()+"."+j.str();
    }
};

class TOrt{
	private:
		string Ort;
		string PLZ;
		string Strasse;
		string HNr;
	public:
		TOrt();
		TOrt(string pOrt,string pStrasse, string pPLZ, string pHNr){Ort=pOrt;Strasse=pStrasse;PLZ=pPLZ;HNr=pHNr;}
		~TOrt();
		
		string getPLZ(){return PLZ; };
    	string getOrt(){return Ort;};
    	
    	void setPLZ(string Postcode){ PLZ= Postcode;};
    	void setOrt(string Stadt){Ort = Stadt;};
		
		string show(){return Ort+" "+PLZ;};
		
	
};

class TPerson{
private:
    string VN;
    string NN;
    TOrt Heimat;
    TDatum Geburtstag;
public:
    TPerson(){
        VN ="Birte";
        NN="Sonnenburg";
        cout<<"Konstruktor von TPerson aufgerufen"<<endl;
    };
    TPerson(string pVorname, string pNachname,TOrt Heimat,int pTag, int pMonat, int pJahr){
        VN = pVorname;
        NN = pNachname;
        Geburtstag.setTag(pTag);
        Geburtstag.setMonat(pMonat);
        Geburtstag.setJahr(pJahr);
    
        cout<<"überladener Konstruktor von TPerson aufgerufen"<<endl;
    };
    ~TPerson(){ cout<<"Destruktor von TPerson aufgerufen"<<endl;};
    
    string getVorname(){return VN;};
    string getNachname(){return NN;};

    TDatum getGeburtstag(){return Geburtstag;};
    TOrt getOrt(){return Heimat;};
    
    void setVorname(string Vorname){VN= Vorname;};
    void setNachname(string Nachname) {NN=Nachname;};
    
    void setGeburtstag(TDatum Birthday){Geburtstag = Birthday;};
    void setOrt(TOrt Wohn){Heimat = Wohn;};
    
    string show(){return VN +" "+ NN +" wohnt in "+Heimat.show()+"\n"+ Geburtstag.show(); }
};
 
 

int main(int argc, const char * argv[]) {
	TOrt Heimat;
	Heimat.setOrt("R�dnitz");
	Heimat.setPLZ("16321");
	
	Heimat.show();
    return 0;
}
