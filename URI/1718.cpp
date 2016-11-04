#include <bits/stdc++.h>
using namespace std;

bool verifica( string p ) {
	int a = 0;
	for( int i=0; i<p.size() && a<=1; i++ )
		if( p[i] == '1' )
			a++;
	return a == 1;
}

int main() {
	int c, n, x;
	bool possivel;
	string p = "";

	scanf( "%d%d", &c, &n );
	for( int i=0; i<c; i++ ) p += "0";
	for( int i=0; i<n; i++ )
		scanf( "%d", &x ), p[x] = '1';

	p += p;
	for( int i=0; i<p.size()-c; i++ ) {
		possivel = true;
		for( int j=i; j<i+c && possivel; j+=c/n )
			possivel = verifica( p.substr( j, c/n ) );
		if( possivel )
			break;
	}
	printf( "%s\n", possivel ? "S" : "N" ); 

	return 0;
}