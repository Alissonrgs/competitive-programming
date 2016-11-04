#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool espaco;

	while( scanf( "%d", &n ) && n ) {
		espaco = false;
		for( int i=1; i*i<=n; i++ )
			printf( "%s%d", ( espaco ? " " : "" ), i*i ), espaco = true;
		printf( "\n" );
	}

	return 0;
}