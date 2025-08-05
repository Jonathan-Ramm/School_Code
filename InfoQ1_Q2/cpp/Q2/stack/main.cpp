#include <iostream>
using namespace std;

struct Element{
	int Geburtsjahr;
	string Name;
	Element *next;
} *head, *tail;
int anzahl;

void initStack();
void push(int geboren, string nn);
string top();

int main(int argc, char** argv) {
	
	initStack();
	cout<<tail<<endl;
	cout<<head->next<<endl;
	
	push(2000,"1");
	push(2000,"2");
	push(2000,"3");
	push(2000,"4");
	push(2000,"5");
	push(2000,"6");
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;
	cout<<top()<<endl;

	
	return 0;
}

string top(){
	if(anzahl>=1){
		anzahl = anzahl-1;
		string merke;
		Element *holder;
		holder= head->next;
		merke = holder->Name;
		head->next = holder->next;
		delete holder;
		return merke;
		
	}else{cout<<"nein!"<<endl;}
}

void push(int geboren, string nn){
	Element *dummy;
	dummy = new Element;
	dummy->Geburtsjahr = geboren;
	dummy->Name = nn;
	dummy->next = head->next;
	head->next = dummy;
	anzahl++;
}

void initStack(){
	head = new Element;
	tail = new Element;
	
	head->Geburtsjahr = 0;
	head->Name = "k.A.";
	head->next = tail;       
	
	tail->Geburtsjahr = 2500;
	tail->Name = "k.A.";
	tail->next = 0;                                                                                                                                                                                                                                                                   
}
