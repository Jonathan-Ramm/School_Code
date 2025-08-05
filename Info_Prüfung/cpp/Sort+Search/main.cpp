#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
 
// Variablen
const int oben=200;
const int maxZufall = 100;
int realArray[oben];
// UPs
void zufall(int anArray[oben]);
void show(int anArray[oben]);
int sequentialSearch(int anArray[oben],int number);
int whereIsMin(int anArray[oben]);
void bubble(int anArray[oben]);
int binaereSuche(int anArray[oben], int sz, int links, int rechts);
void tausche(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick(int formalArray[oben], int links, int rechts){
    int l, r, pivot;
    l = links;
    r = rechts;
    pivot = formalArray[(l + r) / 2];
    while (l <= r) {
        while (formalArray[l] < pivot) { l++; }
        while (formalArray[r] > pivot) { r--; }
        if (l <= r) {
            tausche(formalArray[l], formalArray[r]);
            l++;
            r--;
        }
    }
    if (links < r) { quick(formalArray, links, r); }
    if (l < rechts) { quick(formalArray, l, rechts); }
}
void Select(int anArray[oben]){
	for(int i = 0; i<oben-1; i++){
		int kl = i;
		for(int k = i+1; k<oben;k++){
			if(anArray[k] < anArray[kl]){
				kl = k;
			}
		}
		tausche(anArray[kl],anArray[i]);
	}
}

void shell(int anArray[oben]) {
    for (int gap = oben / 2; gap > 0; gap /= 2) {
        // Führt für jedes Gap einen modifizierten Insertion Sort durch
        for (int i = gap; i < oben; i++) {
            int temp = anArray[i];
            int j;
            // Sortieren innerhalb des "gap"-Abstands
            for (j = i; j >= gap && anArray[j - gap] > temp; j -= gap) {
                anArray[j] = anArray[j - gap];
            }
            anArray[j] = temp;
        }
    }
}


/*****************************************************************/
int main(int argc, const char * argv[]) {
    srand(7);

    zufall(realArray);
    show(realArray);
    bubble(realArray);
	show(realArray);
	cout<<endl;
	
	zufall(realArray);
    show(realArray);
    Select(realArray);
	show(realArray);
	cout<<endl;
	
	zufall(realArray);
    show(realArray);
    shell(realArray);
	show(realArray);
	cout<<endl;
    
    zufall(realArray);
    show(realArray);
    quick(realArray, 0,oben-1);
	show(realArray);
    cout<<endl;
    
    return 0;
}







void bubble(int anArray[oben]){
    for(int k = 0; k<oben-1; k++){
        for (int i = 0; i<oben-1; i++){
            if(anArray[i]>anArray[i+1]){
                int zw = anArray[i];    
                anArray[i] = anArray[i+1];
                anArray[i+1]=zw;
            }
            //show(anArray);
        }
        //show(anArray);
    }
}


int whereIsMin(int anArray[oben]){
    int merke = anArray[0];
    int stelle = 0;
    for (int i = 1; i<oben; i++){
        if(merke > anArray[i]){
            merke  = anArray[i];
            stelle = i;
        }
    }
    return stelle;
}
int sequentialSearch(int anArray[oben],int number){
    int merke =-1;
    for (int i = 0; i<oben; i++){
        if(number == anArray[i]){
            merke= i;
        }
    }
    return merke;
}

void show(int anArray[oben]){
    for (int i = 0; i<oben; i++){
        cout<<anArray[i]<<"->";
    }
    cout<<endl;
}

void zufall(int anArray[oben]){
    for (int i = 0; i<oben; i++){
        anArray[i]=rand()%maxZufall;
    }
}

