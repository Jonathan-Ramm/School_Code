#include <iostream>



int delta(int zustand, int eingabe){
	int merke=-1 ;
	switch(zustand){
		case 0:
			if(eingabe==0){merke=0;}else{merke=1;}
			break;
		case 1:
			if(eingabe==0){merke=2;}else{merke=1;}
			break;
		case 2:
			if(eingabe==0){merke=3;}else{merke=1;}
			break;
		case 3:
			if(eingabe==0){merke=3;}else{merke=1;}
			break;			
	};
	return merke;
}

int main(int argc, char** argv) {
	return 0;
}
