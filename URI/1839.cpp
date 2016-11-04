#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

ll C[2505][2505];

void comb() {
	//C(n,k) = C(n-1,k-1)+C(n-1,k)
  	for( int n=0; n<=2500; n++ )
  		C[n][0] = C[n][n] = 1LL;
  
  	for( int n=1; n<=2500; n++ )
    	for( int k=1; k<=n; k++ )
    		C[n][k] = ( C[n-1][k-1] + C[n-1][k] )%MOD;
}

int main() {
	int n, m, x1, y1, x2, y2, k;
	char cs[55][55];
	comb();

	scanf( "%d%d", &n, &m );
	for( int i=1; i<=n; i++ )
		for( int j=1; j<=m; j++ )
			scanf( " %c", &cs[i][j] );

	while( scanf( "%d", &x1 ) != EOF ) {
		scanf( "%d%d%d", &y1, &x2, &y2 );
		k = 0;
		for( int i=x1; i<=x2; i++ )
			for( int j=y1; j<=y2; j++ )
				if( cs[i][j] == '#' )
					k++;
				
		n = (x2-x1+1)*(y2-y1+1);
		printf( "%lld\n", C[n][k]-1 );
	}

	return 0;
}