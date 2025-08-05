#include <iostream>
using namespace std;

struct ticket{
	string name;
	int anzahl;
	double preis;
	ticket *next;
}*head, *tail;

void initQ();
void enQ(string n, int a, float p);
void deQ();
string first();

int main(int argc, char** argv) {
	initQ();
	enQ("1", 10, 10);
	enQ("2", 11, 11);
	enQ("3", 11, 11);
	enQ("4", 11, 11);
	enQ("5", 11, 11);
	enQ("6", 11, 11);
	cout<<first()<<endl;
	cout<<first()<<endl;
	cout<<first()<<endl;
	cout<<first()<<endl;
	cout<<first()<<endl;
	cout<<first()<<endl;
	
	return 0;
}

string first(){
	string merke;
	ticket *holder;
	holder= head->next;
	merke = holder->name;
	head->next = holder->next;
	delete holder;
	return merke;
}


void deQ(){
	ticket *holder;
	holder= head->next;
	head->next = holder->next;
	delete holder;
}

void enQ(string n, int a, float p){
	ticket *dummy = new ticket;
	ticket *runner;
	dummy->name=n;
	dummy->anzahl=a;
	dummy->preis=p;
	
	runner=head;
	while(runner->next != tail){
		runner=runner->next;
	}
	dummy->next=runner->next;
	runner->next=dummy;
}


void initQ(){
	head = new ticket;
	tail = new ticket;
	
	head->name = "Anfang";
	head->anzahl = 0;
	head->preis = 0;
	head->next = tail;
	
	tail->name = "Ende";
	tail->anzahl = 0;
	tail->preis = 0;
};
