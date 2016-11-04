#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, m[15], sm, l[15], sl, em, el;

	while( scanf( "%d", &r ) && r ) {
		sm = 0, em = r;
		for( int i=0; i<r; i++ ) {
			scanf( "%d", &m[i] );
			sm += m[i];
			if( em == r && i >= 2 && m[i] == m[i-1] && m[i-1] == m[i-2] )
				em = i;
		}
		sl = 0, el = r;
		for( int i=0; i<r; i++ ) {
			scanf( "%d", &l[i] );
			sl += l[i];
			if( el == r && i >= 2 && l[i] == l[i-1] && l[i-1] == l[i-2] )
				el = i;
		}
		if( em < el ) sm += 30;
		if( el < em ) sl += 30;
		if( sm == sl )
			printf( "T\n" );
		else
			printf( "%s\n", sm > sl ? "M" : "L" );
	}

	return 0;
}