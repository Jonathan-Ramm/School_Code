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
    TDatum();
    TDatum(int pTag, int pMonat, int pJahr); //Signatur
    ~TDatum();
    // getter - Lesezugriff
    int getTag();
    int getMonat();
    int getJahr();
    // setter -Schreibzugriff
    void setTag(int pTag);
    void setMonat(int pMonat);
    void setJahr(int pJahr);
    string show();
};
class TPerson{
private:
    string VN;
    string NN;
    string PLZ;
    string Ort;
    TDatum *Geburtstag;
public:
    TPerson();
    TPerson(string pVorname, string pNachname,string pPLZ, string pOrt,int pTag, int pMonat, int pJahr);
	TPerson(string pVorname, string pNachname,string pPLZ, string pOrt,TDatum pGeburtstag);
    ~TPerson();
    
    string getVorname();
    string getNachname();
    string getPLZ();
    string getOrt();
    TDatum *getGeburtstag();
    
    void setVorname(string Vorname);
    void setNachname(string Nachname) ;
    void setPLZ(string Postcode);
    void setOrt(string Stadt);
    void setGeburtstag(TDatum *Birthday);
    
    string show();
};
class TTermin :public TDatum{
    
};

TDatum heute;


int main(int argc, const char * argv[]) {
    //TPerson du;
   TPerson du("Axel","Schweiß","12345","Philadelphia",10,2,1900);
    //heute.setTag(26); heute.setMonat(2); heute.setJahr(2025);
    //cout<<"heute ist der : "<<heute.show()<<endl;
    cout<<du.show()<<endl;
    return 0;
}

TPerson::TPerson(){
        VN ="Birte";
        NN="Sonnenburg";
        Ort="Sonneberg";
        PLZ="12345";
		Geburtstag = new TDatum();
        cout<<"Konstruktor von TPerson aufgerufen"<<endl;
    };
    TPerson::TPerson(string pVorname, string pNachname,string pPLZ, string pOrt,int pTag, int pMonat, int pJahr){
        VN = pVorname;
        NN = pNachname;
        Ort= pOrt;
        PLZ=pPLZ;
        Geburtstag = new TDatum(pTag,pMonat,pJahr);
    
        cout<<"überladener Konstruktor von TPerson aufgerufen"<<endl;
    };
    TPerson::~TPerson(){ 
		Geburtstag->~TDatum();
		cout<<"Destruktor von TPerson aufgerufen"<<endl;
	};
    
    string TPerson::getVorname(){return VN;};
    string TPerson::getNachname(){return NN;};
    string TPerson::getPLZ(){return PLZ; };
    string TPerson::getOrt(){return Ort;};
    TDatum TPerson::*getGeburtstag(){return Geburtstag;};
    
    void TPerson::setVorname(string Vorname){VN= Vorname;};
    void TPerson::setNachname(string Nachname) {NN=Nachname;};
    void TPerson::setPLZ(string Postcode){ PLZ= Postcode;};
    void TPerson::setOrt(string Stadt){Ort = Stadt;};
    void TPerson::setGeburtstag(TDatum *Birthday){Geburtstag = Birthday;};
    
    string TPerson::show(){return VN +" "+ NN +" wohnt in "+ PLZ+" "+Ort+"\n"+ Geburtstag->show(); }
    
    
    

TDatum::TDatum(){
        Tag   = 1;
        Monat = 1;
        Jahr  = 1970;
        cout<<"Konstruktor von TDatum aufgerufen"<<endl;
    };
    TDatum::TDatum(int pTag, int pMonat, int pJahr){
        Tag   = pTag;
        Monat = pMonat;
        Jahr  = pJahr;
        cout<<"überladener Konstruktor von TDatum aufgerufen"<<endl;
    };
    TDatum::~TDatum(){cout<<"Destruktor von TDatum aufgerufen"<<endl;};
    // getter - Lesezugriff
    int TDatum::getTag(){ return Tag; };
    int TDatum::getMonat(){return Monat;};
    int TDatum::getJahr(){return Jahr;};
    // setter -Schreibzugriff
    void TDatum::setTag(int pTag){Tag = pTag;};
    void TDatum::setMonat(int pMonat){Monat = pMonat;};
    void TDatum::setJahr(int pJahr){Jahr = pJahr;};
    string TDatum::show(){
        stringstream t,m,j;
        t<<Tag;
        m<<Monat;
        j<<getJahr();
        return t.str()+"."+m.str()+"."+j.str();
    }
