#include <iostream>
using namespace std;

const int oben=20;
int anArray[oben];

void show(int fA[oben]);

int main(int argc, char** argv) {
	
	show(anArray);
	
	return 0;
}

void show(int fA[oben]){
	for(int i = 0; i <oben; i++){
		cout<<i<<"-"<<fA[i]<<endl;
	}
}
