#include <bits/stdc++.h>
using namespace std;

vector<int> G[1005];
vector<string> amigo;
map<string, int> mapa;
string nome[1005];
int n, g, d[1005];

void bfs( int u ) {
	for( int i = 1; i <= n; i++ ) d[i] = INT_MAX;

	queue<int> q;
	q.push( u );
	d[u] = 0;
	
	while( !q.empty() ) {
		u = q.front();
		q.pop();
		
		for( int i = 0; i < G[u].size(); i++ ) {
			int v = G[u][i];
			
			if( d[v] == INT_MAX ) {
				d[v] = d[u] + 1;
				if( d[v] <= g )
					amigo.push_back( nome[v] );
				q.push( v );
			}
		}
	}
}

int main() {
	int pessoa = 1;
	string n1, n2;
	
	cin >> n >> g;
	for( int i = 0 ; i < n; i++ ) {
		cin >> n1 >> n2;
		if( !mapa[ n1 ] ) {
			nome[ pessoa ] = n1;
			mapa[ n1 ] = pessoa++;
		}
		if( !mapa[ n2 ] ) {
			nome[ pessoa ] = n2;
			mapa[ n2 ] = pessoa++;	
		}
		G[ mapa[ n1 ] ].push_back( mapa[ n2 ] );
		G[ mapa[ n2 ] ].push_back( mapa[ n1 ] );
	}
	
	bfs( mapa[ "Rerisson" ] );
	sort( amigo.begin(), amigo.end() );
	
	printf( "%d\n", amigo.size() );
	for( int i = 0; i < amigo.size(); i++ )
		cout << amigo[i] << endl;

	return 0;
}

