#include <bits/stdc++.h>
using namespace std;

int main() {
	string texto, html;
	bool I, B;

	while( getline( cin, texto ) ) {
		html.clear();
		I = B = false;
		for( int i=0; i<texto.size(); i++ ) {
			if( texto[i] == '_' ) {
				if( I ) html += "</i>";
				I = !I;
				if( I ) html += "<i>";
				continue;
			}
			if( texto[i] == '*' ) {
				if( B ) html += "</b>";
				B = !B;
				if( B ) html += "<b>";
				continue;
			}
			html += texto[i];
		}
		cout << html << endl;
	}

	return 0;
}