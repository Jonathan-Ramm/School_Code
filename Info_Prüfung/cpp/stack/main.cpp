#include <iostream>
using namespace std;

struct Bier{
	float preis = 0;
	string name = "";
	Bier *next = NULL;
	Bier *last = NULL;
}*head, *tail;

void init(){
	head = new Bier;
	tail = new Bier;
	head->next = tail;
	tail->last = head;
}

void push(float preis, string name){
	Bier *dummy = new Bier;
	dummy->name = name;
	dummy->preis = preis;
	dummy->next=head->next;
	dummy->next->last = dummy;
	dummy->last=head;
	head->next = dummy;

	
}
void pop() {
	if (head->next != tail) {
		Bier* dummy = head->next;
		dummy->next->last = dummy->last;
		dummy->last->next = dummy->next;
		delete dummy;
	}
}
string top(){
	if (head->next != tail) {
		Bier* dummy = head->next;
		string x = dummy->name;
		dummy->next->last = dummy->last;
		dummy->last->next = dummy->next;
		delete dummy;
		return x;
	}else{return "Keine Elemente aufm Stack";
	}
}
int main(int argc, char** argv) {
	init();
	push(5.99,"Karls");
	push(4.33,"sdsd");
	push(343.2,"sdsasf");
	top();

	return 0;
}


