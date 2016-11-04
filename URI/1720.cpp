#include <bits/stdc++.h>
using namespace std;

map< string, int > mapa;

struct Point {
	int x, y, z;
	string r;
	Point() { x = y = z = 0; }
	Point( int _x, int _y, int _z ) : x(_x), y(_y), z(_z) {}
} p[10005];

struct Plano {
	int a, b, c, d;
	Plano() { a = b = c = d = 0; }
} plano[505];

int main() {
	int m, n, qp;
	string r = "";

	scanf( "%d%d", &m ,&n );
	for( int i=0; i<m; i++ ) {
		r += "0";
		scanf( "%d%d%d%d", &plano[i].a, &plano[i].b, &plano[i].c, &plano[i].d );
	}
	qp = 0;
	for( int i=0; i<n; i++ ) {
		scanf( "%d%d%d", &p[i].x, &p[i].y, &p[i].z );
		p[i].r = r;
		for( int j=0; j<m; j++ )
			if( plano[j].a*p[i].x + plano[j].b*p[i].y + plano[j].c*p[i].z > plano[j].d )
				p[i].r[j] = '1';
		
		qp = max( qp, ++mapa[ p[i].r ] );
	}

	printf( "%d\n", qp );

	return 0;
}