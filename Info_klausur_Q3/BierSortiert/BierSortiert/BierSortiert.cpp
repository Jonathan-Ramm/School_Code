
#include <iostream>
using namespace std;

struct Bier {
    string Sorte;
    int Anzahl;
    float Preis;
    Bier* next;
    Bier* last;
}*head, * tail, * runner, *runner2, *now;

void init();
void enq(string brand, int number, float price);
bool isEmpty();

bool deleteElement();
float searchElement(string eingabe);
string backward();
string forward();
string first();
string last();
string current();
string ausgabe();



int main()
{
    init();
    string was;
    cout << "Was möchten 'se machn?" << endl << "(es geht: e(isEmpty); deq; first(top); enq; d(deleteStack))" << endl;
    cin >> was;
    while (was != "stop") {
        if (was != "current" && was != "suche" && was != "deq" && was != "stop" && was != "d" && was != "e") {
            cout << "Was? "; cin >> was;
        }
        if (was == "current") {
            cout << current()<<endl;
            cin >> was;
        }
        if (was == "suche") {
            string eingabe;
            cin >> eingabe;
            searchElement(eingabe);
        }

    }
    return 0;

}
float searchElement(string eingabe) {
    now = head->next;
    while (now->Sorte > eingabe && now != tail) {
        now = now->next;
        return now->Preis;
    }
    if (now == tail) {
        return 0;
    }
    return now->Preis;
}

bool deleteElement() {
    return 0;
}


string forward() {
    if (now->next != tail) {
        now = now->next;
        return ausgabe();
    }
    else {
        return "ist letztes element";
    }
}

string backward() {
    if (now->last != head) {
        now = now->last;
        return ausgabe();
    }
    else {
        return "ist erstes element";
    }
}

string ausgabe() {
    return now->Sorte + " ; ";
}

string current() {
    if (now != head && now != tail) {
        return ausgabe();
    }
    else {
        return "Liste leer";
    }
}

bool isEmpty() {
    return head->next == tail;
}

string first() {
    now = head->next;
    if (now != tail) {
        return ausgabe() + " ist am Anfang";
    }
    else {
        return "Liste leer";
    }
}

string last() {
    now = tail->last;
    if (now != head) {
        return ausgabe() + " ist am Ende";
    }
    else {
        return "Liste leer";
    }
}

void enq(string brand, int number, float price) {
    Bier* dummy = new Bier;
    Bier* runner2 = new Bier;
    dummy->Sorte = brand;
    dummy->Anzahl = number;
    dummy->Preis = price;

    if (isEmpty()) {
        dummy->next = tail;
        dummy->last = head;
        head->next = dummy;
        tail->last = dummy;
    }
    else {
        while (brand > runner2->Sorte && runner2 != tail) {
            runner2 = runner2->next;
            dummy->next = runner;
            dummy->last = runner2->last;
            dummy->last->next = dummy;
            runner->last = dummy;

        }
    }now = dummy;
    
    
    

};

void init() {
    head = new Bier;
    tail = new Bier;

    now = head;

    head->Sorte = "_AAAnfang";
    head->Anzahl = 0;
    head->Preis = 0;

    head->next = tail;

    tail->Sorte = "ZZZuende";
    tail->last = head;

};