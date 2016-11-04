#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long int

int main() {
	int n;
	bool espaco;
	ll v[10];

	while( scanf( "%d", &n ) && n ) {
		for( int i=0; i<n; i++ )
			scanf( "%lld", &v[i] );
		sort( v, v+n );
		do {
			espaco = false;
			for( int i=0; i<n; i++ )
				printf( "%s%lld", ( espaco ? " " : "" ), v[i] ), espaco = true;
			printf( "\n" );	
		} while( next_permutation( v, v+n ) );
	}

	return 0;
}