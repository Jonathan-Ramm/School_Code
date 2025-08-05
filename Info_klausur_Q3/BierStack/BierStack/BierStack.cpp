
#include <iostream>
using namespace std;

struct Bier {
    string Sorte;
    int Anzahl;
    float Preis;
    Bier* next;
}*head, *tail, *runner;

void initStack();
void push(string brand, int number, float price);
bool pop();
string top();
bool deleteStack();
bool isEmpty();


int main()
{
    initStack();
    string was;
    cout << "Was möchten 'se machn?"<<endl<<"(es geht: e(isEmpty); pop; t(top); push; d(deleteStack))" << endl;
    cin >> was;
    while (was != "stop") {
        if (was != "push" && was != "t" && was != "pop" && was != "stop" && was != "d" && was != "e") {
           cout << "Was? "; cin >> was;
        }
        if (was == "e") {
            isEmpty();
            cout << "Was? ";  cin >> was;
        }
        if (was == "pop") {
            cout << pop() << endl;
            cout << "Was? ";  cin >> was;
        }
        if (was == "t") {
            cout<<top()<<endl;
            cout << "Was? ";  cin >> was;
        }
        if (was == "push") {
            string brand; int number; float price;
            cout << "Art: "; cin >> brand;
            cout << "Anzahl: "; cin >> number;
            cout << "Preis: "; cin >> price;
            push(brand, number, price);
            cout << "Was? ";  cin >> was;
        }
        if (was == "d") {
            cout << deleteStack() << endl;
            cout << "Was? "; cin >> was;
        }
        
    }
    return 0;
    
}

bool deleteStack() {
    while (head->next != tail) {
        pop();
    }
    delete head->next;
    delete head;
    return 0; 
}

bool isEmpty() {
    return head->next == tail;
}

string top() {
    if (head->next != tail) {
        runner = head->next;
        string merke = runner->Sorte;
        head->next = runner->next;
        delete runner;
        return merke;
    }
    else { return "Stack war leer"; }
}

void push(string brand, int number, float price) {
    Bier* dummy = new Bier;
    dummy->Sorte = brand;
    dummy->Anzahl = number;
    dummy->Preis = price;

    dummy->next = head->next;
    head->next = dummy;

};

bool pop() {
    if (head->next != tail) {
        runner = head->next;
        head->next = runner->next;
        delete runner;
        return 1;
    }else { return 0; }
}

void initStack() {
    head = new Bier;
    tail = new Bier;
    head->Sorte = "Anfang";
    head->Anzahl = 0;
    head->Preis = 0;
    head->next = tail;
   
    tail->Sorte = "Ende";
    tail->next = NULL;

};