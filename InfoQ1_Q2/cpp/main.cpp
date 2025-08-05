#include <iostream>
using namespace std;

int fibonachi(int zahl1,int a, int b);

int main(int argc, char** argv) {
	cout<<fibonachi(10, 1, 1);
	return 0;
}

int fibonachi(int zahl1, int a, int b){
	a=1;
	b=1;
	if(a=0, b=0){
		return zahl1;
	}else{
		return fibonachi(zahl1, a+b, a);
	}
}
