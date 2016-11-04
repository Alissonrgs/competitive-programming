#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

struct aresta {
	point p;	
	int d;
	
	aresta( point _p, int _d ) : p(_p), d(_d) {}
	bool operator<( aresta a ) const { return a.d > d; }
};

vector<aresta> G[105];
map<point, int> mapa; 
int n, d[105];

void dijkstra( aresta u ) {
	for( int i = 1; i <= 100; i++ ) d[i] = INT_MAX;
	
	priority_queue<aresta> q;
	q.push( u );
	d[ mapa[ u.p ] ] = 0;
	
	while( !q.empty() ) {
		u = q.top();
		q.pop();
		
		for( int i = 0; i < G[ mapa[ u.p ] ].size(); i++ ) {
			aresta v = G[ mapa[ u.p ] ][i];
			
			if( d[ mapa[ v.p ] ] > d[ mapa[ u.p ] ] + v.d ) {
				d[ mapa[ v.p ] ] = d[ mapa[ u.p ] ] + v.d;
				q.push( aresta( v.p, d[ mapa[ v.p ] ] ) );
			}
		}
	}
}

bool existe( int x, int y ) { return 0 <= x && x < n && 0 <= y && y < n; }

int main() {
	int q, p, node, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
	
	while( cin >> n && n ) {
		for( int i = 1; i <= 100; i++ ) G[i].clear();
		mapa.clear();
		node = 1;

		for( int i = n-1; i >= 0; i-- ) {
			for( int j = 0; j < n; j++ ) {
				point _point = point( i, j );
				for( int k = 0; k < 4; k++ ) {
					cin >> p;
					if( p )
						G[ node ].push_back( aresta( point( i+dx[k], j+dy[k] ), 1 ) );
				}
				if( !mapa[ _point ] )
					mapa[ _point ] = node++;
			}
		}

		cin >> q;
		
		for( int i = 0, x1, y1, x2, y2; i < q; i++ ) {		
			cin >> x1 >> y1 >> x2 >> y2;
			dijkstra( aresta( point( y1, x1 ), 0 ) );
	
			if( d[ mapa[ point( y2, x2 ) ] ] == INT_MAX )
				cout << "Impossible" << endl;
			else
				cout << d[ mapa[ point( y2, x2 ) ] ] << endl;
		}
		cout << endl;
	}

	return 0;
}

