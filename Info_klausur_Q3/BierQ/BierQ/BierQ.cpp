
#include <iostream>
using namespace std;

struct Bier {
    string Sorte;
    int Anzahl;
    float Preis;
    Bier* next;
}*head, * tail, * runner, *runner3;

void initQ();
void enq(string brand, int number, float price);
bool deq();
string first();
bool deleteQ();
bool isEmpty();


int main()
{
    initQ();
    string was;
    cout << "Was möchten 'se machn?" << endl << "(es geht: e(isEmpty); deq; first(top); enq; d(deleteStack))" << endl;
    cin >> was;
    while (was != "stop") {
        if (was != "enq" && was != "first" && was != "deq" && was != "stop" && was != "d" && was != "e") {
            cout << "Was? "; cin >> was;
        }
        if (was == "e") {
            isEmpty();
            cout << "Was? ";  cin >> was;
        }
        if (was == "deq") {
            cout << deq() << endl;
            cout << "Was? ";  cin >> was;
        }
        if (was == "first") {
            cout << first() << endl;
            cout << "Was? ";  cin >> was;
        }
        if (was == "enq") {
            string brand; int number; float price;
            cout << "Art: "; cin >> brand;
            cout << "Anzahl: "; cin >> number;
            cout << "Preis: "; cin >> price;
            enq(brand, number, price);
            cout << "Was? ";  cin >> was;
        }
        if (was == "d") {
            cout << deleteQ() << endl;
            cout << "Was? "; cin >> was;
        }

    }
    return 0;

}

bool deleteQ() {
    while (head->next != tail) {
        deq();
    }
    delete head->next;
    delete head;
    return 0;
}

bool isEmpty() {
    return head->next == tail;
}

string first() {
    if (head->next != tail) {
        runner = head->next;
        string merke = runner->Sorte;
        head->next = runner->next;
        delete runner;
        return merke;
    }
    else { return "Stack war leer"; }
}

void enq(string brand, int number, float price) {
    Bier* runner2 = new Bier;
    runner2->Sorte = brand;
    runner2->Anzahl = number;
    runner2->Preis = price;

    runner2->next = tail;
    runner3->next = runner2;
    runner3 = runner2;
};

bool deq() {
    if (head->next != tail) {
        runner = head->next;
        head->next = runner->next;
        delete runner;
        return 1;
    }
    else { return 0; }
}

void initQ() {
    head = new Bier;
    tail = new Bier;
    runner3 = new Bier;
    head->Sorte = "Anfang";
    head->Anzahl = 0;
    head->Preis = 0;
    head->next = tail;

    tail->Sorte = "Ende";
    tail->next = NULL;

    runner3 = head;

};