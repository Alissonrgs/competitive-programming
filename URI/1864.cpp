#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string text = "LIFE IS NOT A PROBLEM TO BE SOLVED";

	scanf( "%d", &n );
	for( int i=0; i<n; i++ )
		printf( "%c", text[i] );
	printf( "\n" );

	return 0;
}