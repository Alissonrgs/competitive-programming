#include <bits/stdc++.h>
using namespace std;

vector<int> v[105];

int main() {
	int n, m, c, chave;
	bool barraN = false;

	scanf( "%d", &n );
	while( n-- ) {
		printf( "%s", ( barraN ? "\n" : "" ) ), barraN = true;

		scanf( "%d%d", &m, &c );
		for( int i=0; i<c; i++ ) {
			scanf( "%d", &chave );
			v[ chave%m ].push_back( chave );
		}
		for( int i=0; i<m; i++ ) {
			printf( "%d -> ", i );
			for( int j=0; j<v[i].size(); j++ )
				printf("%d -> ", v[i][j] );
			v[i].clear();
			printf( "\\\n" );
		}
	}

	return 0;
}