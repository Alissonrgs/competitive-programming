#include <bits/stdc++.h>
using namespace std;

int main() {
	int qnt, msstr;
	string a, b;

	while( getline( cin, a ) && getline( cin, b ) ) {
		msstr = 0;
		for( int i=0; i<a.size(); i++ )
			for( int j=0; j<b.size(); j++ )
				if( a[i] == b[j] ) {
					qnt = 1;
					for( int x=i+1, y=j+1; x<a.size() && y<b.size(); x++, y++ )
						if( a[x] == b[y] ) qnt++;
						else break;

					msstr = max( msstr, qnt );
				}

		printf( "%d\n", msstr );
	}

	return 0;
}