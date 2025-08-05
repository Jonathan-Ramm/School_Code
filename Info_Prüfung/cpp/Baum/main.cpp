#include <iostream>
using namespace std;

struct Element{
	int No;
	Element *left;
	Element *right;
	Element *vater;
}*root,*runner,*guard, *change;

void init(int nummer);
void insert(int nummer);
bool search(int nummer);
void inOrder(Element* eingabe);
void preOrder(Element* eingabe);
void postOrder(Element* eingabe);
bool deleteElement(int nummer);
bool isBlatt(int nummer);
bool isOne(int nummer);
bool isInner(int nummer);
int whatKind(int nummer);

void printAsciiTree(Element* node, string prefix, bool isLeft);


int main(int argc, char** argv) {
	init(67);
	insert(32);
	insert(31);
	insert(34);
	insert(29);
	insert(324);
	insert(18);
	insert(23);
	insert(12);
	insert(69);
	insert(129);
	insert(6);
	insert(77);
	insert(99);
	insert(71);
	insert(84);
	cout<<search(71);
	cout<<isOne(84);
	deleteElement(67);
	printAsciiTree(root, "", true);
	return 0;
}
bool deleteElement(int nummer){
	int typ = whatKind(nummer);+
	search(nummer);
	if(typ == 2){
		guard = runner->left;
		change = runner;
		while (guard->right != 0) {
			guard = guard->right;
		}// steht auf dem Austauschelement
		int Nr = guard->No;
		deleteElement(Nr);
		change->No = Nr;
		
	}
	if (runner != root){
		if(typ == 0){
			guard = runner->vater;//Einarm oder Blatt
			if (guard->left == runner) { delete runner; guard->left = 0; } //  Blatt hängt links
			if (guard->right == runner) { delete runner; guard->right = 0; } // Blatt hängt rechts
			return 1;
		}
		if(typ == 1){
			guard = runner->vater;//Einarm oder Blatt
			if (guard->left == runner) { delete runner; guard->left = 0; } //  Blatt hängt links
			if (guard->right == runner) { delete runner; guard->right = 0; } // Blatt hängt rechts
			return 1;
		}
	}else{
		if(typ == 0){
			delete root;
			return 1;
		}
		if(typ == 1){
			runner = root;
			if (root->left != 0) {  root = runner->left;delete runner; } //  Blatt hängt links
			if (root->right != 0) { root = runner->right;delete runner;  } // Blatt hängt rechts
			return 1;
		}
	}
	
}
void printAsciiTree(Element* node, string prefix = "", bool isLeft = true) {
    if (node == NULL)
        return;

    cout << prefix;
    cout << (isLeft ? "+--" : "+--" );
    cout << node->No << endl;

    // Rechte Seite zuerst (damit die Anzeige schöner ist)
    if (node->right || node->left) {
        printAsciiTree(node->right, prefix + (isLeft ? "¦   " : "    "), true);
        printAsciiTree(node->left,  prefix + (isLeft ? "¦   " : "    "), false);
    }
}


int whatKind(int nummer){
	if(isBlatt(nummer)==1){
		return 0;
	}
	if(isOne(nummer)==1){
		return 1;
	}
	if(isInner(nummer)==1){
		return 2;
	}
}

bool isOne(int nummer){
	if(search(nummer) && runner->left == 0 && runner->right != 0 || search(nummer) && runner->left != 0 && runner->right == 0){
		return 1;
	}
	return 0;
}
bool isInner(int nummer){
	if(search(nummer) && runner->left != 0 && runner->right != 0){
		return 1;
	}
	return 0;
}
bool isBlatt(int nummer){
	if(search(nummer) && runner->left == 0 && runner->right == 0){
		return 1;
	}
	return 0;
}

void postOrder(Element* eingabe){
	if(eingabe->left != 0){
		postOrder(eingabe->left);
	}
	if(eingabe->right != 0){
		postOrder(eingabe->right);
	}
	cout<<eingabe;
}
void preOrder(Element* eingabe){
	cout<<eingabe;
	if(eingabe->left != 0){
		preOrder(eingabe->left);
	}
	if(eingabe->right != 0){
		preOrder(eingabe->right);
	}
}
void inOrder(Element* eingabe){
	if(eingabe->left != 0){
		inOrder(eingabe->left);
	}
	cout<<eingabe;
	if(eingabe->right != 0){
		inOrder(eingabe->right);
	}
}

bool search(int nummer){
	runner = root;
	
	while(true){
		if(runner->No == nummer){
			return 1;
		}
		if(runner->No > nummer){
			if(runner->left == 0){
				return 0;
			}
			runner=runner->left;
		}
		if(runner->No < nummer){
			if(runner->right == 0){
				return 0;
			}
			runner=runner->right;
		}
	}
}

void insert(int nummer){
	runner = root;
	bool fertig = false;
	Element *dummy = new Element;
	dummy->No = nummer;
	dummy->left = 0;
	dummy->right = 0;
	
	while(!fertig){
		if(runner->No > nummer){
			if(runner->left == 0){
				runner->left = dummy;
				dummy->vater = runner;
				fertig = true;
			}
			runner=runner->left;
		}
		if(runner->No < nummer){
			if(runner->right == 0){
				runner->right = dummy;
				dummy->vater = runner;
				fertig = true;
			}
			runner=runner->right;
		}
	}
}

void init(int nummer){
	root = new Element;
	root->No = nummer;
	root->left = 0;
	root->right = 0;
	root->vater = NULL;
}
