#include <iostream>
using namespace std;

string s,t,u,v;
short laenge, wo;
char c;

int main(int argc, char** argv) {
	s = "RELIEFPFEILER";
	t = "Hello";
	u = "World!";
	
//Kontkatenation

	v = t + " " + u;
	cout<<v<<endl;	
	
	v = s.substr(0,6); //first = starting point, second = how long
	cout<<v<<endl;
	
	v = s.erase(6,7);
	cout<<v<<endl;
	
	laenge = s.length();
	cout<<laenge<<endl;
	
	v = s.insert(0,"ein ");
	cout<<v<<endl;
	
	v = s.replace(0,4,"wundevolles ");
	cout<<v<<endl;
	
	wo = s.find("R");
	cout<<wo<<endl;
	
	wo = s.find_first_of("E");
	cout<<wo<<endl;
	
	wo = s.find_last_of("E");
	cout<<wo<<endl;
	
	c = s[0];
	cout<<c<<endl;
	
	c = s[12];
	cout<<c<<endl;
	
	laenge = s.length();
	for (int i = 0; i<laenge;i++){
		v = s.erase(0,1);
		cout<<v<<endl;
	}
	
	string q = s;
	for (int i = 0; i<laenge; i++){
		v = v + q[i];
		cout<<v<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
