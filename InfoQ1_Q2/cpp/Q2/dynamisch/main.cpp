#include <iostream>
using namespace std;

struct BK{
	string Sorte;
	double Preis;
	BK *next;
}*head, *tail;

void initStack();
void enq(string art, double kosten);
string top();

int weiter;
double kosten;
string art;

int main(int argc, char** argv) {
	initStack();
	cin>>weiter;
	while(weiter > 0){
		while(weiter == 1){
			cout<<"Sorte: "<<endl;
			cin>>art;
			cout<<"Kosten: "<<endl;
			cin>>kosten;
			enq(art, kosten);
			
			cout<<"Sorte: "<<head->next->Sorte<<endl;
			cout<<"Preis: "<<head->next->Preis<<endl;
			cout<<"Addresse: "<<head->next->next<<endl;
			cout<<"Weiter? "<<endl;
			cin>>weiter;
		}
		cout<<top()<<endl;
		cin>>weiter;
		
	}


	return 0;
}
void queue(){
	
}


string deq(){
	string merke;
	if(head->next != tail){
		BK *weg;
		if(h)
		weg = head->next;
		head->next=weg->next;
		merke=weg->Sorte;
		delete weg;		
	}else{
		merke="Leer";
	}
	return merke;
}

void enq(string art, double kosten){
	BK *dummy;
	dummy = new BK;
	dummy->Sorte = art;
	dummy->Preis = kosten;
	dummy->next = head->next;
	head->next = dummy;
}


void initStack(){
	tail = new BK;
	head = new BK;
	head->next = tail;
	head->Sorte = "head";
	head->Preis = 0.0;
	tail->Sorte = "tail";
	tail->Preis = 0.0;
	tail->next = NULL;
}


