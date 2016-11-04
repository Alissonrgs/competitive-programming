#include <bits/stdc++.h>
using namespace std;

map<string,int> mapa;

struct team {
	int p, v, g, id;
	string nome;
	team() { p = 0; v = 0; g = 0; }
	void clear() { p = 0; v = 0; g = 0; }
} Team[105];

bool ord( team a, team b ) {
	if( a.p == b.p ) {
		if( a.v == b.v ) {
			if( a.g == b.g )
				return a.id < b.id;

			return a.g > b.g;
		}
		return a.v > b.v;
	}
	return a.p > b.p;
}

int main() {
	int t, n, m, ga, gb;
	string a, b;

	cin >> t;
	while( t-- ) {
		cin >> n >> m;
		mapa.clear();
		for( int i=0; i<n; i++ ) Team[i].clear();
		for( int i=0; i<n; i++ ) {
			cin >> Team[i].nome;
			Team[i].id = i;
			mapa[ Team[i].nome ] = i;
		}

		for( int i=0; i<m; i++ ) {
			cin >> ga >> a >> gb >> b;
			Team[ mapa[a] ].g += ga;
			Team[ mapa[b] ].g += gb;
			if( ga == gb ) {
				Team[ mapa[a] ].p++;
				Team[ mapa[b] ].p++;
			} else if( ga > gb ) {
				Team[ mapa[a] ].p += 3;
				Team[ mapa[a] ].v++;
			} else {
				Team[ mapa[b] ].p += 3;
				Team[ mapa[b] ].v++;
			}
		}
		sort( Team, Team+n, ord );
		for( int i=0; i<n; i++ )
			cout << Team[i].nome << endl;
	}

	return 0;
}