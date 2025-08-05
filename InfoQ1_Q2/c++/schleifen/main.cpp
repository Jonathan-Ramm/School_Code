#include <iostream>
#include <iomanip>

using namespace std;

	int a;
	char c;
	

int main(int argc, char** argv) {
	
	for(int i = 0; i<10; i++ ){
		cout<<setw(i+5)<<"l_"<<endl;
		
	}
	
	for(int i = 10; i>0; i-- ){
		cout<<setw(i+5)<<"l_"<<endl;
	}
	
	
	int z = 0;
	int y;
	
	while(z<10){
		y= 0;
		while(y<z){
			cout<<"*";
			y++;
		}
		cout<<endl;
		z++;
	}
			cout<<endl;

	
	int b=20;

	for(int i = 0; i<15; i++){
		cout<<setw(b)<<"* "<<setw(a)<<"*"<<endl;
		a++;
		a++;
		b--;
		
	}	
		
	int d=5;

	
	
	for(int i = 15; i>0; i--){
		cout<<setw(d)<<"* "<<setw(a)<<" *"<<endl;
		a--;
		a--;
		d++;
		
	}
	
	cout<<"                  *"<<endl;
	
	
	
	
	
	
	
	
	
	return 0;
}
