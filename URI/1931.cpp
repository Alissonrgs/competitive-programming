#include <bits/stdc++.h>
using namespace std;

#define ve vector<edge>
#define MAX 10005
#define INF (int)1e9

struct edge {
	int v, p, ne;
	edge() {};
	edge( int _v, int _p, int _ne ) : v(_v), p(_p), ne(_ne) {}
	bool operator<( const edge &a ) const { return p > a.p; }
};

ve AdjList[MAX];
priority_queue<edge> pqueue;
int p[MAX][2];

int main() {
	int c, v, c1, c2, vp;

	scanf( "%d%d", &c, &v );
	for( int i = 0; i < v; i++ ) {
		scanf( "%d%d%d", &c1, &c2, &vp );
		AdjList[ c1 ].push_back( edge( c2, vp, 0 ) );
		AdjList[ c2 ].push_back( edge( c1, vp, 0 ) );
	}

	for( int i = 1; i <= c; i++ ) p[i][0] = p[i][1] = INF;
	p[1][0] = 0;
	pqueue.push( edge( 1, 0, 0 ) );
	while( !pqueue.empty() ) {
		edge A = pqueue.top(); pqueue.pop();

		for( int u = 0; u < (int)AdjList[ A.v ].size(); u++ ) {
			edge B = AdjList[ A.v ][u];
			if( p[ B.v ][ !A.ne ] > p[ A.v ][ A.ne ] + B.p ) {
				p[ B.v ][ !A.ne ] = p[ A.v ][ A.ne ] + B.p;
				pqueue.push( edge( B.v, p[ B.v ][ !A.ne ], !A.ne ) );
			}
		}
	}
	printf( "%d\n", p[c][0] == INF ? -1 : p[c][0] );

	return 0;
}