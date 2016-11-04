#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define X first
#define Y second
#define vii vector<point>
#define vi vector<int>
#define INF 1e12

vii city[1005];
vi G[1005];
map<string,int> mapa;
int visited[1005];
double dp[1005][55];

double dist( point a, point b ) { return hypot( a.X - b.X, a.Y - b.Y ); }

void dfs( int u ) {
    visited[u] = 1;

    for( int i = 0, v; i < G[u].size(); i++ ) {
        v = G[u][i];
        if( visited[v] ) continue;
        dfs(v);
        for( int j = 0; j < city[u].size(); j++ ) {
            double ans = INF;
            for( int k = 0; k < city[v].size(); k++ )
                ans = min( ans, dp[v][k] + dist( city[u][j], city[v][k] ) );
            dp[u][j] += ans;
        }
    }
}

int main() {
    int n, c;
    string city1, city2;
    
    while( cin >> n && n ) {
        mapa.clear();
        
        for( int i = 0; i < n; i++ ) {
            G[i].clear();
            city[i].clear();
        
            cin >> city1 >> c;
            mapa[city1] = i;
            for( int j = 0, x, y; j < c; j++ ) {
                cin >> x >> y;
                city[i].push_back( make_pair( x, y ) ); 
            } 
        }
        for( int i = 1; i < n; i++ ) {
            cin >> city1 >> city2;
            G[ mapa[city1] ].push_back( mapa[city2] );
            G[ mapa[city2] ].push_back( mapa[city1] );
        }
        
        memset( dp, 0, sizeof dp );
        memset( visited, 0, sizeof visited );
        dfs(0);

        double answer = INF;
        for( int i = 0; i < city[0].size(); i++ )
            answer = min( answer, dp[0][i] );

        cout.precision(1);
        cout << fixed << answer << endl;
    }

    return 0;
}
