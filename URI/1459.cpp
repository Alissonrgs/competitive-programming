#include <bits/stdc++.h>
using namespace std;

struct foco {
	int x, y;

	foco( int x, int y ) {
		this->x = x;
		this->y = y;
	}
};

vector<foco> F;

bool ord( foco A, foco B ) {
	return A.y < B.y;
}

int main() {
	int n, a, b, fotos;

	while( scanf( "%d", &n ) != EOF ) {
		fotos = 1;
		F.clear();
		for( int i=0; i<n; i++ ) {
			scanf( "%d%d", &a, &b );
			F.push_back( foco( a, b ) );
		}
		sort( F.begin(), F.end(), ord );
		for( int i=0; i<F.size()-1; i++ )
			if( F[i+1].x <= F[i].y )
				F[i+1] = F[i];
			else
				fotos++;

		printf( "%d\n", fotos );
	}

	return 0;
}