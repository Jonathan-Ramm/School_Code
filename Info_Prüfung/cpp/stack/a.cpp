#include <iostream>
using namespace std;

struct Bier {
	float preis = 0;
	string name = "";
	Bier *next = NULL;
	Bier *last = NULL;
} *head, *tail;

void init() {
	head = new Bier;
	tail = new Bier;
	head->next = tail;
	tail->last = head;
}

void push(float preis, string name) {
	Bier* dummy = new Bier;
	dummy->name = name;
	dummy->preis = preis;
	dummy->next = head->next;
	dummy->last = head;
	head->next->last = dummy;
	head->next = dummy;
}

void top() {
	if (head->next != tail) {
		Bier* dummy = head->next;
		cout << dummy->name << endl << dummy->preis << endl;
		dummy->next->last = dummy->last;
		dummy->last->next = dummy->next;
		delete dummy;
	} else {
		cout << "Keine Elemente aufm Stack" << endl;
	}
}

int main() {
	init();
	push(5.99, "Karls");
	push(4.33, "sdsd");
	push(343.2, "sdsasf");

	top(); // sdsasf
	top(); // sdsd
	top(); // Karls
	top(); // Keine Elemente aufm Stack

	return 0;
}

