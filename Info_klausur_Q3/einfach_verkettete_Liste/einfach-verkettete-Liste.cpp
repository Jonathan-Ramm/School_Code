#include <iostream>
using namespace std;

struct Informatiker {
    string NN;
    string VN;
    int GbJ;
    string was;
    Informatiker* next;
}*head, * tail, * runner1, * current;

void initSorted();
bool einfugen(string VN, string NN, int GbJ, string was);
bool suchen(string suche);
bool loeschen();
string zeige();
bool isEmpty() { return head->next == tail; }

void left();
void right();
void first();
void last();

int main() {
    initSorted();
           einfugen("Ada", "Lovelace", 1815, "Erste Programmiererin, schrieb den ersten Algorithmus für die Analytical Engine von Charles Babbage.");
           einfugen("John", "von Neumann", 1903, "Entwickelte die Von-Neumann-Architektur, Grundlage für moderne Computer.");
           einfugen("Grace", "Hopper", 1906, "Entwicklerin des ersten Compilers und Pionierin für Programmiersprachen.");
           einfugen("Alan", "Turing", 1912, "Begründer der theoretischen Informatik und der Künstlichen Intelligenz. Entwickelte die Turing-Maschine.");
           einfugen("Edsger W.", "Dijkstra", 1930, "Entwickelte den kürzesten Pfad-Algorithmus (Dijkstra-Algorithmus) und trug zur strukturierten Programmierung bei.");
           einfugen("Donald", "Knuth", 1938, "Autor von The Art of Computer Programming und Schöpfer der TeX-Satzsysteme.");
           einfugen("Barbara", "Liskov", 1939, "Entwicklerin des Liskov-Substitutionsprinzips, Pionierin der Objektorientierung und verteilten Systeme.");
           einfugen("Vint", "Cerf", 1943, "Einer der 'Väter des Internets', Co-Entwickler des TCP/IP-Protokolls.");          
           einfugen("Linus", "Torvalds", 1969, "Schöpfer des Linux-Kernels.");
           einfugen("Tim", "Berners-Lee", 1955, "Erfinder des World Wide Web.");
    isEmpty();
    current = head->next->next->next->next;
  	cout<<zeige()<<endl;
    right(); cout << zeige()<<endl;
    first(); cout << zeige() << endl;
    last(); cout << zeige() << endl;
    left(); cout << zeige() << endl;
    cout << suchen("Cerf");
    return 0;
};
bool loeschen() {
    Informatiker* runner2;
    runner2 = current;
    left();
    current->next = runner2->next;
    delete runner2;
}

void right() { current = current->next; }
void first() { current = head->next; }

void last() { 
    while (current->next != tail) {
        current = current->next;
    }        
}

void left() {
    Informatiker* runner;
    runner = current;
    current = head->next;
    while (current->next != runner) {
        current = current->next;
    }
}
string zeige() {
    if (!isEmpty()) {
        return current->NN;
    }
    else { return "Liste ist leer."; }
}
bool suchen(string suche) {
    Informatiker* suchV = head->next;
    while (suchV->NN != suche && suchV != tail) {
        suchV = suchV->next;
    }
    if (suchV->next == tail) {
        cout << "Liste leer." << endl;
        return 0;
    }
    return 1;
}

bool einfugen(string VN, string NN, int GbJ, string was) {
    Informatiker* dummy = new Informatiker;
    dummy->NN = NN;
    dummy->VN = VN;
    dummy->GbJ = GbJ;
    dummy->was = was;

    while (runner1->next != tail && runner1->next->GbJ < GbJ)
    {
        runner1 = runner1->next;
    }

    dummy->next = runner1->next;
    runner1->next = dummy;
    current = dummy;
    return 1;
}

void initSorted() {	
    head = new Informatiker;
    tail = new Informatiker;

    head->next = tail;
    runner1 = head;
}
