#include <iostream>

struct Person{
	string Vor;
	string Nach;
	string errungen;
	int Gbj;
	Person *next;
}*head, *tail, *runner, *current;

void initSorted();
void insertElement(string VN, string NN, string Err, int Gbj);


int main(int argc, char** argv) {
	return 0;
}
