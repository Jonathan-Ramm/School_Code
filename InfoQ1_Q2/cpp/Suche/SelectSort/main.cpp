#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int oben=31;
int realArray[oben];

void zufall(int formalArray[oben]);
void ausgabe(int formalArray[oben]);
void baum(int formalArray[oben]);
int sucheMin(int formalArray[oben], int links, int rechts);
void selectSort(int formalArray[oben]);
void tausche(int *x, int *y){int zw=*x; *x = *y; *y = zw;}
void insertSort(int formalArray[oben]);
void shell(int formalArray[oben]);
void quick(int formalArray[oben], int links, int rechts);
void buildheap(int formalArray[oben]);
void downheap(int formalArray[oben]);


int main(int argc, char** argv) {
	srand(8);
	zufall(realArray);
//	shell(realArray);
//	insertSort(realArray);
//	selectSort(realArray);
//	quick(realArray, 0, oben);
	baum(realArray);
	buildheap(realArray);
	baum(realArray);
	downheap(realArray);
	baum(realArray);
	
	ausgabe(realArray);
	return 0;

}


void downheap(int formalArray[oben]){
	int grenze = oben-1;
	int i = 0;
	while(grenze>0){
		tausche(&formalArray[0], &formalArray[grenze]);
		cout<<" "<<formalArray[0]<<" getauscht mit "<<" "<<formalArray[grenze]<<";"<<endl;
		grenze--;
		i=0;
		while(i<grenze){
			if(formalArray[i]<=formalArray[i*2+1]||formalArray[i]<=formalArray[i*2+2p ]){
				if(formalArray[i*2+1]>formalArray[i*2+2]){
					if(i*2+1<grenze){
						tausche(&formalArray[i], &formalArray[i*2+1]);
						cout<<" "<<formalArray[i]<<" getauscht mit "<<" "<<formalArray[i*2+1]<<"; "<<endl;
						i=i*2+1;	
					}else{					
						i=grenze+1;
					}
				}else{
					if(i*2+2<grenze){
						tausche(&formalArray[i], &formalArray[i*2+2]);
						cout<<" "<<formalArray[i]<<" getauscht mit "<<" "<<formalArray[i*2+2]<<"; "<<endl;
						i=i*2+2;	
					}else{
						i=grenze+1;
					}	
			 	}
			}else{
				i=grenze+1;
			}
		}
		baum(formalArray);
	}
}

void quick(int formalArray[oben], int links, int rechts){
	int r = rechts;
	int l = links;
	int p = formalArray[(r+l)/2];

	while(r>=l){
		if(formalArray[l]>=p && formalArray[r]<=p){
			tausche(&formalArray[l],&formalArray[r]);
			l++; r--;
		}
		if(formalArray[l]<p) l++;
		if(formalArray[r]>p) r--;
	}
	if(links<r) {quick(formalArray, links, r);}
	if(rechts>l) {quick(formalArray, l, rechts);}
}
void buildheap(int formalArray[oben]){
	bool getauscht=true;
	while(getauscht){
		getauscht=false;
		for(int i=oben-1; i>0; i--){
			if(formalArray[i]>formalArray[(i-1)/2]){
				tausche(&formalArray[i], &formalArray[(i-1)/2]);
				getauscht=true;
			}
		}
	}
}

void baum(int formalArray[oben]){
	cout<<setw(64)<<formalArray[0]<<endl<<endl;
	cout<<setw(32)<<formalArray[1]<<setw(64)<<formalArray[2]<<endl<<endl;
	cout<<setw(16)<<formalArray[3]<<setw(32)<<formalArray[4]<<setw(32)<<formalArray[5]<<setw(32)<<formalArray[6]<<endl;
	cout<<setw(8)<<formalArray[7]<<setw(16)<<formalArray[8]<<setw(16)<<formalArray[9]<<setw(16)<<formalArray[10]<<setw(16)<<formalArray[11]<<setw(16)<<formalArray[12]<<setw(16)<<formalArray[13]<<setw(16)<<formalArray[14]<<endl;
	cout<<setw(4)<<formalArray[15]<<setw(8)<<formalArray[16]<<setw(8)<<formalArray[17]<<setw(8)<<formalArray[18]<<setw(8)<<formalArray[19]<<setw(8)<<formalArray[20]<<setw(8)<<formalArray[21]<<setw(8)<<formalArray[22]<<setw(8)<<formalArray[23]<<setw(8)<<formalArray[24]<<setw(8)<<formalArray[25]<<setw(8)<<formalArray[26]<<setw(8)<<formalArray[27]<<setw(8)<<formalArray[28]<<setw(8)<<formalArray[29]<<setw(8)<<formalArray[30]<<endl;
}

void shell(int formalArray[oben]){
	// 31, 15, 7, 4, 1

	for(int i = 0; i<oben-32; i++){
		if(formalArray[i]>formalArray[i+31]){
			tausche(&formalArray[i], &formalArray[i+31]);
		}
	}
	for(int i = 0; i<oben-16; i++){
		if(formalArray[i]>formalArray[i+15]){
			tausche(&formalArray[i], &formalArray[i+15]);
		}
	}
	for(int i = 0; i<oben-8; i++){
		if(formalArray[i]>formalArray[i+7]){
			tausche(&formalArray[i], &formalArray[i+7]);
		}
	}
	for(int i = 0; i<oben-4; i++){
		if(formalArray[i]>formalArray[i+3]){
			tausche(&formalArray[i], &formalArray[i+3]);
		}
	}
	insertSort(formalArray);
}

void insertSort(int formalArray[oben]){
	int x;
	for(int i=1; i<oben; i++){
		x=i;
		while(formalArray[x-1]>formalArray[x]&&x>0){
			tausche(&formalArray[x], &formalArray[x-1]);
			x--;
		}
	}
}

void selectSort(int formalArray[oben]){
	int mini;
	for(int i=0; i<oben-1; i++){
		mini = sucheMin(formalArray, i+1, oben-1);
		if(formalArray[mini]<formalArray[i]){
			tausche(&formalArray[mini], &formalArray[i]);
		}
	}
	
}

int sucheMin(int formalArray[oben], int links, int rechts){
	int merke = formalArray[links];
	int wo = links;
	for(int i = links+1; i<=rechts; i++){
		if(formalArray[i]<merke){
			merke=formalArray[i];
			wo=i;
		}
	}
	return wo;
}

void ausgabe(int formalArray[oben]){
	for( int i=0; i<oben; i++){
		cout<<formalArray[i]<<" | ";
	}
	cout<<endl;
}

void zufall(int formalArray[oben]){
	for( int i=0; i<oben; i++){
		formalArray[i]= rand() % 200;
	}
}

//WENN PARAMETER = VARIABLENPARAMETER DANN IST DIESER PARAMETER AUCH EIN EINGABE-&AUSGABEPARAMETER

