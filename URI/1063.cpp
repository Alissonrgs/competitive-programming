#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j;
	char vi[30], vf[30];
	stack<int> pilha;

	while( scanf( "%d", &n ) && n ) {
		while( !pilha.empty() ) pilha.pop();
		for( i=0; i<n; i++ )
			scanf( " %c", &vi[i] );
		for( i=0; i<n; i++ )
			scanf( " %c", &vf[i] );

		i = j = 0;
		printf( "I" );
		pilha.push( vi[j++] );
		while( !pilha.empty() ) {
			if( vf[i] == pilha.top() ) {
				printf( "R" );
				pilha.pop();
				i++;
				
			} else {
				if( j == n ) break;
				printf( "I" );
				pilha.push( vi[j] );
				j++;
			}
			if( pilha.empty() && j < n ) {
				printf( "I" );
				pilha.push( vi[j++] );
			}
		}
		printf( "%s\n", pilha.empty() ? "" : " Impossible" );
	}

	return 0;
}