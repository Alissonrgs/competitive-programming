#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c[1005], v[1005], ret;

	while( scanf( "%d", &n ) && n ) {
		for( int i=0; i<n; i++ )
			scanf( "%d%d", &c[i], &v[i] );

		ret = 0;
		for( int i=0; i<n; i++ ) {
			while( v[i] >= 4 )
				v[i] -= 4, ret++;
			for( int j=i+1; j < n && v[i] >= 2; j++ )
				while( v[i] >= 2 && v[j] >= 2 )
					v[i] -= 2, v[j] -= 2, ret++;
		}

		printf( "%d\n", ret );
	}

	return 0;
}