#include <iostream>
#include <sstream>
using namespace std;

class CPunkt{
private:
    int x;
    int y;
public:
    CPunkt():x(0),y(0){cout<<"Standardkonstruktor CPunkt aufgerufen\n";}
    CPunkt(int px, int py ){x=px;y=py;cout<<"FACHSCEN";}
    ~CPunkt(){cout<<"Destruktor CPunkt aufgerufen\n";}
    int get_x(){return x; };
    int get_y(){return y; };
    
    void set_x(int px){x = px;};
    void set_y(int py){y = py;};
    
    virtual string show(){ stringstream xs,ys;
        xs<<x;
        ys<<y;
        return "Der Punkt: (" + xs.str()+"|"+ys.str()+")"; }
};

class CStrecke{
private:
    CPunkt *A;
    CPunkt *B;
public:
    CStrecke() {
    	A = new CPunkt();
        B = new CPunkt();
        cout<<"Standardkonstruktor CStrecke aufgerufen\n";
    }
    CStrecke(int ax, int ay, int bx, int by) {
       A = new CPunkt(ax, ay);
        B = new CPunkt(bx, by);
        cout<<"Überl. Konstruktor CStrecke aufgerufen\n";
    }
    ~CStrecke() {
        delete B;
        delete A;
        cout<<"Destruktor CStrecke aufgerufen\n";
    }
    CPunkt* getA()  { return A; }
    CPunkt* getB()  { return B; }

    // Setter fÃ¼r die Punkte
    void setA(int ax, int ay) {
        A->set_x(ax);
        A->set_y(ay);
    }
    void setA(CPunkt pP) {
        A->set_x(pP.get_x());
        A->set_y(pP.get_y());
    }
    void setB(int bx, int by) {
        B->set_x(bx);
        B->set_y(by);
    }
    string show(){
        return "Gerade von "+A->show()+" nach "+ B->show()+"\n";
    }
};

class FarbPunkt:public CPunkt{
	private:
		string color;
	public:
		FarbPunkt(){};
		FarbPunkt(int px,int py,string farbe):CPunkt(px,py){color=farbe;};		
		
		~FarbPunkt(){};
		string getColor(){return color;}
		void setColor(string farbe){color = farbe;}
		string show(){
			return CPunkt::show()+" hat die Farbe: "+getColor()+"\n";
		}
	
};

class CDreieck{
	private:
		CPunkt A;
		CPunkt *B;
		CPunkt *C;
	public:
		CDreieck(){
			B= new CPunkt(0,0);
			C= new CPunkt(0,0);
		}
		CDreieck(int xA,int yA, CPunkt *pB, CPunkt *pC){
			a.set_x(xA);
			a.set_y(yA);
			
			B->set_x(pB->get_x());
			B->set_y(pB->get_y());
			C=pC;
		}
		
};

class C3DPunkt:public CPunkt{
	private:
		int z;
	public:
		C3DPunkt(){}
		C3DPunkt(int px,int py,int pz){set_x(px);set_y(py);z=pz;}
		int get_z(){return z; };
		void set_z(int pz){z = pz;};
		string show(){ stringstream xs,ys,zs;
        xs<<CPunkt::get_x();
        ys<<get_y();
        zs<<z;
        return "Der 3D Punkt: (" + xs.str()+"|"+ys.str()+"|"+zs.str()+")"; 
		}
};

C3DPunkt B(22,27,3);
FarbPunkt F(11,4,"rot");
CPunkt *p;

int main(int argc,  char * argv[]) {
	cout<<B.show();
	cout<<F.show();
	p = new CPunkt;
	cout<<p->show()<<endl;

    

    
    return 0;
}
