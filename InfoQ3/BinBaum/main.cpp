#include <iostream>
using namespace std;
int eingabe;

struct Element{
	int No;
	string Name;
	Element * left;
	Element *right;
	Element *parent;
}*root, *runner, *guard, *change;
void init(int nummer, string Name);
void insert(int nummer, string Name);
bool search(int nummer);
void inOrder(Element *eingabe);
void preOrder(Element *eingabe);
void postOrder(Element *eingabe);
bool deleteE(int nummer);
bool isBlatt(int nummer);
bool isOne(int nummer);
bool isInner(int nummer);
string deleteElement(int Nummer);

int main(int argc, char** argv) {
	init(42, "Peter");
	insert(18, "achtzehn");
	insert(23, "neunundsechzig");
	insert(12, "zwölf");
	insert(69, "berg");
	insert(129, "berg");
	insert(6, "berg");
	insert(77, "berg");
	insert(99, "berg");
	insert(71, "berg");
	insert(84, "berg");
	
	inOrder(root);
	cout<<endl;
	preOrder(root);	
	cout<<endl;	
	postOrder(root);
	
	
	deleteElement(77);deleteElement(42);
	inOrder(root);
	cin>>eingabe;
	cout<<endl<<search(eingabe)<<endl<<endl;
	return 0;
}
bool isBlatt(int nummer){
	bool blatt = false;
	if(search(nummer) != 0){
		if(runner->left == 0 && runner->right == 0){
			blatt=true;
		}
	}
	return blatt;
};
int whatKind(int Nummer){
	if(isBlatt(Nummer)==1){
		return 0;
	}
	if(isOne(Nummer)==1){
		return 1;
	}
	if(isInner(Nummer)==1){
		return 2;
	}
}

string deleteElement(int Nummer) {
	int art = whatKind(Nummer); 
	int Nr;
	string was;
	string inhalt = "nicht vorhanden\n";
	if (art > -1) {
		inhalt = runner->Name;
		if (art == 2) { // egal ob Wurzel oder nicht
			guard = runner->left;
			change = runner;
			while (guard->right != 0) {
				guard = guard->right;
			}// steht auf dem Austauschelement
			Nr = guard->No;
			was = guard->Name;
			deleteElement(Nr);
			change->Name = was;
			change->No = Nr;
		}
		else {
			if (runner != root) { // nicht die Wurzel
				guard = runner->parent;//Einarm oder Blatt
				if (art == 0) {
					if (guard->left == runner) { delete runner; guard->left = 0; } //  Blatt hängt links
					if (guard->right == runner) { delete runner; guard->right = 0; } // Blatt hängt rechts
				}
				if (art == 1) {
					if (guard->left == runner) { //hängt links
						if (runner->left != 0) {
							guard->left = runner->left; delete runner; // hat links  ein Kind
						}
						else { guard->left = runner->right; delete runner; } // hat rechts ein Kins
					}
					if (guard->right == runner) {//hängt rechts
						if (runner->left != 0) {
							guard->right = runner->left; delete runner;// hat links  ein Kind
						}
						else { guard->right = runner->right; delete runner; }// hat rechts  ein Kind
					}
				}
			}
			else {
				if (art == 0) { // die Wurzel
					delete root; // Baum hat nur die Wurzel
				}
				else {
					if (runner->left != 0) {
						guard = root; root = root->left; delete guard; //hat links ein Kind
					}
					if (runner->right != 0) {
						guard = root; root = root->right; delete guard;// hat rechts  ein Kind
					}
				}
			}
		}
	}
	return inhalt;
}
bool isOne(int nummer) {
	bool one = false;
	if (search(nummer) != 0) {
		if ((runner->left != 0 && runner->right == 0) || (runner->left == 0 && runner->right != 0)) {
			one = true;
		}
	}
	return one;
}

bool isInner(int nummer) {
	bool inner = false;
	if (search(nummer) != 0) {
		if (runner->left != 0 && runner->right != 0) {
			inner = true;
		}
	}
	return inner;
}

void postOrder(Element *eingabe){
	if(eingabe->left != 0){
		postOrder(eingabe->left);
	}
	if(eingabe->right != 0){
		postOrder(eingabe->right);
	}
	cout<<eingabe->No<<endl;
}

void preOrder(Element *eingabe){
	cout<<eingabe->No<<endl;
	if(eingabe->left != 0){
		preOrder(eingabe->left);
	}
	if(eingabe->right != 0){
		preOrder(eingabe->right);
	}
}

void inOrder(Element *eingabe){
	if(eingabe->left != 0){
		inOrder(eingabe->left);
	}
	cout<<eingabe->No<<endl;
	if(eingabe->right != 0){
		inOrder(eingabe->right);
	}
}

bool search(int nummer){
	runner=root;
	bool drin=true;
	while(true){
		if(nummer < runner->No){
			if(runner->left == 0){
				return 0;
			}
			runner=runner->left;
		}else{if(nummer>runner->No){
			if(runner->right == 0){
				return 0;
			}
			runner=runner->right;
		}		
		}
		if(nummer==runner->No){
			return 1;
		}
		
	}
}

void insert(int nummer,string Name){
	runner=root;
	bool fertig=false;
	Element * dummy=new Element;
	dummy->No=nummer;
	dummy->left=0;
	dummy->right=0;
	dummy->Name=Name;
	
	while(!fertig){
		if(nummer < runner->No){
			if(runner->left == 0){
				runner->left = dummy;
				dummy->parent = runner;
				fertig=true;
			}
			
			runner=runner->left;
		}else{
		
			if(runner->right == 0){
				runner->right = dummy;
				dummy->parent=runner;
				fertig=true;
			}
			runner=runner->right;
		}
		
	}
}

void init(int nummer, string Name){
	root = new Element;
	root->Name=Name;
	root->No=nummer;
	root->parent = NULL;
	root->left=0;
	root->right=0;
}
