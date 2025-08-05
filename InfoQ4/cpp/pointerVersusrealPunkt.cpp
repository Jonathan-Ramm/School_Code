#include <iostream>
#include <sstream>
using namespace std;

class CPunkt{
private:
    int x;
    int y;
public:
    CPunkt():x(0),y(0){cout<<"Standardkonstruktor CPunkt aufgerufen\n";}
    CPunkt(int px, int py ): x(px), y(py) {cout<<"überl. Konstruktor CPunkt aufgerufen\n";}
    ~CPunkt(){cout<<"Destruktor CPunkt aufgerufen\n";}
    int get_x(){return x; };
    int get_y(){return y; };
    
    void set_x(int px){x = px;};
    void set_y(int py){y = py;};
    
    string show(){ stringstream xs,ys;
        xs<<x;
        ys<<y;
        return "(" + xs.str()+",|"+ys.str()+")"; }
};

class CGerade{
private:
    CPunkt A;
    CPunkt *B;
public:
    CGerade() {
        B = new CPunkt();
        cout<<"Standardkonstruktor CPunkt aufgerufen\n";
    }
    CGerade(int ax, int ay, int bx, int by) {
        A.set_x(ax);
        A.set_y(ay);
        B = new CPunkt(bx, by);
        cout<<"überl. Konstruktor CGerade aufgerufen\n";
    }
    ~CGerade() {
        delete B;
        cout<<"Destruktor CGerade aufgerufen\n";
    }
    CPunkt getA()  { return A; }
    CPunkt* getB()  { return B; }

    // Setter für die Punkte
    void setA(int ax, int ay) {
        A.set_x(ax);
        A.set_y(ay);
    }
    void setA(CPunkt pP) {
        A.set_x(pP.get_x());
        A.set_y(pP.get_y());
    }
    void setB(int bx, int by) {
        B->set_x(bx);
        B->set_y(by);
    }
    string show(){
        return "Gerade von "+A.show()+" nach "+ B->show()+"\n";
    }
};

class FarbPunkt:public CPunkt{
	private:
		string color;
	public:
		FarbPunkt(){};
		FarbPunkt(int px,int py,string farbe){CPunkt(px,py);color=farbe;};		
		
		~FarbPunkt(){};
		string getColor(){return color;}
		void setColor(string farbe){color = farbe;}
		string show(){
			CPunkt::show()+getColor()+"\n";
		}
	
};


class C3DPunkt:public CPunkt{
	private:
		int z;
	public:
		C3DPunkt(){}
		C3DPunkt(int px,int py,int pz){CPunkt(px,py);z=pz;}
		int get_z(){return z; };
		void set_z(int pz){z = pz;};
};



int main(int argc, const char * argv[]) {

    
    return 0;
}
