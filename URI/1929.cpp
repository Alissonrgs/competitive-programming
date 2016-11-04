#include <bits/stdc++.h>
using namespace std;

bool triangulo( int a, int b, int c ) {
	return ( a < b + c ) && ( b < a + c ) && ( c < a + b );
}

int main() {
	int l[4];
	bool possivel = false;

	for( int i = 0; i < 4 ; i++ )
		scanf( "%d", &l[i] );

	for( int i = 0; i < 4 && !possivel; i++ )
		for( int j = i+1; j < 4 && !possivel; j++ )
			for( int k = j+1; k < 4 && !possivel; k++ )
				possivel = triangulo( l[i], l[j], l[k] );

	printf( "%s\n", possivel ? "S" : "N" );

	return 0;
}