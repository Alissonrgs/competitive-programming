#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ll long long int

int** matMult( int n, int **A, int **B ) {
	int **M;
	M = new int*[n];
	for( int i = 0; i < n; i++ ) {
		M[i] = new int[n];
		for( int j = 0; j < n; j++ ) {
			ll Mij = 0;
			for( int k = 0; k < n; k++ )
				Mij = ( Mij + (ll)A[i][k]*(ll)B[k][j] )%MOD;
			M[i][j] = Mij%MOD;
		}
	}
	return M;
}

int** matPow( int n, int **M, int p ) {
	int **r;
	r = new int*[n];
	for( int i = 0; i < n; i++ ) r[i] = new int[n], r[i][i] = 1;
	while( p ) {
		if( p&1 ) r = matMult( n, r, M );
		M = matMult( n, M, M );
		p >>= 1;
	}
	return r;
}

int main() {
	int a, b, n, **fib, **fibA, **fibB, **fibo, **r;
	int aux[2][2] = { 1, 1,
 					  1, 0 };
	fib = new int*[2];
	for( int i = 0; i < 2; i++ ) {
		fib[i] = new int[2];
 		for( int j = 0; j < 2; j++ )
 			fib[i][j] = aux[i][j];
	}

	int aux2[5][5] = { 1, 1, 1, 1, 1,
					   1, 0, 0, 0, 0,
					   1, 0, 1, 0, 0,
					   1, 0, 0, 1, 0,
					   0, 0, 0, 0, 1 };
	fibo = new int*[5];
	for( int i = 0; i < 5; i++ ) {
		fibo[i] = new int[5];
		for( int j = 0; j < 5; j++ )
			fibo[i][j] = aux2[i][j];
	}

	while( scanf( "%d%d%d", &a, &b, &n ) && a ) {
 		fibA = matPow( 2, fib, a );
		fibB = matPow( 2, fib, b );
  
		r = matPow( 5, fibo, n-1 );
		ll soma = 0;
		soma = ( soma + ( ( ( (ll)fibA[0][0] * (ll)fibB[0][0] )%MOD ) * (ll)r[0][4] )%MOD )%MOD;
		soma = ( soma + ( ( ( (ll)fibA[0][1] * (ll)fibB[0][1] )%MOD ) * (ll)r[1][4] )%MOD )%MOD;
		soma = ( soma + ( ( ( (ll)fibA[0][0] * (ll)fibB[0][1] )%MOD ) * (ll)r[2][4] )%MOD )%MOD;
		soma = ( soma + ( ( ( (ll)fibA[0][1] * (ll)fibB[0][0] )%MOD ) * (ll)r[3][4] )%MOD )%MOD;
		soma = ( soma + ( ( ( (ll)fibA[0][1] * (ll)fibB[0][1] )%MOD ) * (ll)r[4][4] )%MOD )%MOD;
		printf( "%lld\n", soma );
	}
 
	return 0;
}