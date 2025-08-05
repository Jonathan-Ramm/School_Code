#include <iostream>
using namespace std;



struct Person {
    string Name; int Geburtsjahr; string Errungenschaften; Person *next;
}*head, *tail, *runner;
void initSorted();
void insertElement(string Name, int Geburtsjahr, string Errungenschaften);
string searchforElement();
bool deleteELement();
string showElement();
bool isEmpty();

void left();
void right();
void first();
void last();


int main()
{
    initSorted();
    insertElement("Ada Lovelace", 1815, "...");
    insertElement("John von Neumann", 1903, "...");
    insertElement("Grace Hopper", 1906, "Entwicklerin ...");
    insertElement("Alan Turing", 1912, "Begründer der theoretischen Informatik...");
    insertElement("Edsger W. Dijkstra", 1930, "...");
    insertElement("Donald Knuth", 1938, "...");
    insertElement("Barbara Liskov", 1939, "...");
    insertElement("Vint Cerf", 1943, "...");
    insertElement("Tim Berners-Lee", 1955, "...");
    insertElement("Linus Torvalds", 1969, "...");

}
bool isEmpty() {
    return head->next == tail;
}

void insertElement(string Name, int Geburtsjahr, string Errungenschaften) {
    Person *dummy = new Person;
    dummy->Name = Name;
    dummy->Geburtsjahr = Geburtsjahr;
    dummy->Errungenschaften = Errungenschaften;
    Person* now = new Person;
    if (isEmpty()) {
        dummy->next = tail;
        head->next = dummy;
    }
    else {
        while (runner->next->Geburtsjahr < dummy->Geburtsjahr && runner->next != tail) {
            runner = runner->next;
        }
        runner->next = dummy;
        dummy->next = runner->next->next;
    }
    
}

void initSorted() {
    head = new Person;
    tail = new Person;

    runner = head;

    head->next=tail;
}
