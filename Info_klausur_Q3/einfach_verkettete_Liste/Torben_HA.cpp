// Implementierung einer einfach-verknüpften, sortierten, dynamischen Listenstruktur

#include <iostream>
using namespace std;

void initSorted();
void insertElement(string vorderername, string hinterername, string leistung, int geburt);
bool searchForElement(string hinterername);
bool deleteElement(string hinterername);
string showElement(string hinterername);
string right(string hintername);
string left(string hintername);
string first();
string last();


// Informatiker:
struct Menschli{
	string Vorname;
    string Nachname;
    string Errungenschaften;
    int Geburtsjahr;
	Menschli *next;
}*head, *tail, *runner;


int main(int argc, char** argv) {
    initSorted();

    insertElement("Alan", "Turing", "Begründer der theoretischen Informatik und der Künstlichen Intelligenz. Entwickelte die Turing-Maschine.", 1912);
    insertElement("Grace", "Hopper", "Entwicklerin des ersten Compilers und Pionierin für Programmiersprachen.", 1906);
    insertElement("John", "von Neumann", "Entwickelte die Von-Neumann-Architektur, Grundlage für moderne Computer.", 1903);
    insertElement("Tim", "Berners-Lee", "Erfinder des World Wide Web.", 1955);
    insertElement("Donald", "Knuth", "Autor von *The Art of Computer Programming* und Schöpfer der TeX-Satzsysteme.", 1938);
    insertElement("Ada", "Lovelace", "Erste Programmiererin, schrieb den ersten Algorithmus für die Analytical Engine von Charles Babbage.", 1815);
    insertElement("Vint", "Cerf", "Einer der \"Väter des Internets\", Co-Entwickler des TCP/IP-Protokolls.", 1943);
    insertElement("Linus", "Torvalds", "Schöpfer des Linux-Kernels.", 1969);
    insertElement("Edsger W.", "Dijkstra", "Entwickelte den kürzesten Pfad-Algorithmus (Dijkstra-Algorithmus) und trug zur strukturierten Programmierung bei. ", 1930);
    insertElement("Barbara", "Liskov", "Entwicklerin des Liskov-Substitutionsprinzips, Pionierin der Objektorientierung und verteilten Systeme.", 1939);

	return 0;
}

// Operationen
void initSorted(){
	head = new Menschli; //Speicher
	tail = new Menschli;
	
	head->Vorname = "k.A."; // Werte
    head->Nachname = "k.A.";
    head->Errungenschaften = "k.A.";
    head->Geburtsjahr = 0;
    *tail = *head;
    
	head->next = tail; // Verknüpfung
}

void insertElement(string vorderername, string hinterername, string leistung, int geburt){
	Menschli *dummy = new Menschli; //Speicher
	
	dummy->Vorname = vorderername; //Werte
    dummy->Nachname = hinterername;
    dummy->Errungenschaften = leistung;
    dummy->Geburtsjahr = geburt;
	
    runner = head; // Verknüpfung:
	while (runner->next != tail && runner->next->Nachname<dummy->Nachname)  // Sortierung alphabetisch nach Nachname
        {runner = runner->next;}
    dummy->next = runner->next;
    runner->next = dummy;
}

bool searchForElement(string hinterername){ //gibt an, ob ein Element in der Liste enthalten ist
    runner = head->next;
    while (runner != tail){
        if (runner->Nachname == hinterername) return 1;
        runner = runner->next;
    }
    return 0;
}

bool deleteElement(string hinterername){
    runner = head;
    while (runner->next != tail){
        if (runner->next->Nachname == hinterername){
            runner->next = runner->next->next;
            delete runner;  // Speicherplatz freigeben (ich spare mir hier den Dummy)
            return 1;
        }
        runner = runner-> next;
    }
    return 0;  // Element scheint nicht in der Liste zu sein
}

string showElement(string hinterername){
    runner = head;
    while (runner->next != tail){
        if (runner->Nachname == hinterername)
            return runner->Vorname + " " + runner->Nachname 
                   + "\nErrungenschaft: " + runner->Errungenschaften
                   + "\n Geburtsjahr: " + to_string(runner->Geburtsjahr) + "\n";
        runner = runner->next;
    }
    return "Nicht gefunden!";
}

string right(string hinterername){
    runner = head;
    while (runner != tail){
        if (runner->Nachname == hinterername){
            if (runner->next == tail) return "DAS IST DER SCHWANZ";
            else return runner->next->Nachname;
        }
        runner = runner->next;
    }
    return "Nicht gefunden!";
}

string left(string hintername){
    runner = head;
    while(runner->next != tail){
        if (runner->next->Nachname == hintername){
            if (runner == head) return "DAS IST DER KOPF";
            else return runner->Nachname;
        }
        runner = runner->next;
    }
    return "Nicht gefunden!";
}

string first(){
    return (head->next == tail)? "Nicht gefunden!": head->next->Nachname;
}

string last(){
    if (head->next == tail) return "Nicht gefunden!";  // wenn Liste leer soll es kein erstes oder letztes Element geben

    runner = head->next;
    while (runner->next != tail) runner = runner->next;
    return runner->Nachname;
}