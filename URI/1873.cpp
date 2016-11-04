#include <bits/stdc++.h>
using namespace std;

map< string, vector<string> > mapa;

int main() {
	mapa["tesoura"].push_back("papel");
	mapa["tesoura"].push_back("lagarto");
	mapa["papel"].push_back("pedra");
	mapa["papel"].push_back("spock");
	mapa["pedra"].push_back("lagarto");
	mapa["pedra"].push_back("tesoura");
	mapa["lagarto"].push_back("spock");
	mapa["lagarto"].push_back("papel");
	mapa["spock"].push_back("tesoura");
	mapa["spock"].push_back("pedra");

	int c;
	string a, b;

	cin >> c;
	while( c-- ) { 
		cin >> a >> b;
		if( mapa[a][0] == b || mapa[a][1] == b )
			cout << "rajesh" << endl;
		else if( mapa[b][0] == a || mapa[b][1] == a )
			cout << "sheldon" << endl;
		else
			cout << "empate" << endl;
	}

	return 0;
}