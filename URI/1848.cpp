#include <bits/stdc++.h>
using namespace std;

int main() {
	int v = 0;
	string s, bin;

	while( getline( cin, s ) ) {
		if( s == "caw caw" )
			printf( "%d\n", v ), v = 0;
		else {
			bin.clear();
			for( int i = 0; i < s.size(); i++ )
				bin += ( s[i] == '*' ? "1" : "0" );
			v += stoi( bin, NULL, 2 );
		}
	}

	return 0;
}