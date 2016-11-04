#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int main() {
	int n, x, y, i, j;

	while( scanf( "%d", &n ) != EOF ) {
		p.clear();
		for( i=0; i<n; i++ ) {
			scanf( "%d%d", &x, &y );
			for( j=x; j<=y; j++ )
				p.push_back( j );
		}
		sort( p.begin(), p.end() );
		scanf( "%d", &n );
		i = 0, j = -1;
		while( i < p.size() && p[i] <= n ) {
			if( j == -1 && p[i] == n )
				j = i;
			i++;
		}
		if( j != -1 )
			printf( "%d found from %d to %d\n", n, j, i-1 );
		else
			printf( "%d not found\n", n );
	}

	return 0;
}