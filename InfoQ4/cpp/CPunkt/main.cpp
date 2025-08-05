#include <iostream>
#include <sstream>
using namespace std;

class CPunkt{
	private:
		int x;
		int y;
	public:
		CPunkt(){
        x   = 0;
        y = 0;
    };;
		CPunkt(int px, int py){x = px;y=py;};
		~CPunkt(){};
		
		int getX(){return x;}
		int getY(){return y;}
		
		void setX(int px){x = px;}
		void setY(int py){y = py;}
		
		string show(){ stringstream xs,ys;
        xs<<x;
        ys<<y;
        return "(" + xs.str()+"|"+ys.str()+")"; }
};
		




int main(int argc, char** argv) {
	CPunkt P(12,4);
	cout<<P.show();
	P.setX(3);
	cout<<P.show();
	return 0;
}
