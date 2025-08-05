#include <iostream>
using namespace std;
#include <sstream>

//Klassendefinition - Implementation
class Person{
	private:
		string VN;
		string NN;
		string PLZ;
		string Ort;
	public:
		Person(){cout<<"konstruktor von Person aufgerrufen"<<endl;};
		Person(string pVN, string pNN, string pPLZ, string pOrt){
			VN=pVN;NN=pNN;PLZ=pPLZ;Ort=pOrt;
		}
		~Person(){cout<<"destruktor von Person aufgerrufen"<<endl;};
		string getVN(){return VN;};
		string getNN(){return NN;};
		string getPLZ(){return PLZ;};
		string getOrt(){return Ort;};
		
		void setVN(string pVN){VN=pVN;};
		void setNN(string pNN){VN=pNN;};
		void setPLZ(string pPLZ){PLZ=pPLZ;};
		void setOrt(string pOrt){Ort=pOrt;};
		
		string show(){
			return VN+" "+NN+" "+"wohnt in "+PLZ+" "+Ort;
		}
};
class CDatum{
	private:
		int Tag;
		int Monat;
		int Jahr;
		
	public:
	//Konstruktor
	CDatum(){cout<<"konstruktor von Datum aufgerrufen"<<endl;};
	CDatum(int pTag, int pMonat, int pJahr){
		Tag = pTag; Monat = pMonat; Jahr = pJahr;
	}
	//Destructor?
	~CDatum(){cout<<"destruktor von Datum aufgrufen"<<endl;};
	//getter - Lesezugriff
	int getTag(){return Tag;}; //heißt Signatur
	int getMonat(){return Monat;};
	int getJahr(){return Jahr;};
	//setter - Schreibzugriff
	void setTag(int pTag){Tag = pTag;};
	void setMonat(int pMonat){Monat = pMonat;};
	void setJahr(int pJahr){Jahr = pJahr;};	
	string show(){
		stringstream t,m,j;
		t<<Tag;
		m<<Monat;
		j<<Jahr;
		return t.str()+"."+m.str()+"."+j.str();
	
	}
};

CDatum heute;
Person Peter("Peter","Müller","04242","Berlin");

int main(int argc, char** argv) {
	
	cout<<Peter.show();
	cout<<heute.show()<<endl;
	heute.setTag(19);
	heute.setMonat(02);
	heute.setJahr(2025);
	cout<<heute.show()<<endl;
	return 0;
}
