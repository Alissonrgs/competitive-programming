#include<bits/stdc++.h>
using namespace std;

vector<int> G[105];
int cor[105];

void dfs( int i ) {
    cor[i] = 1;
    for( int j = 0; j < G[i].size(); j++ ) {
        int k = G[i][j];
        if( !cor[k] )
            dfs( k );
    }
}

int main() {
    int t, n, m, x, y, estradas;
    
    scanf( "%d", &t );
    for( int k = 1; k <= t; k++ ) {
        for( int i = 1; i <= 100; i++ )
            G[i].clear();        
        memset( cor, 0, sizeof cor );
        estradas = -1;
        
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < m; i++ ) {
            scanf( "%d%d", &x, &y );
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        for( int i = 1; i <= n; i++ )
            if( !cor[i] )
                estradas++, dfs(i);

        if( estradas )
            printf( "Caso #%d: ainda falta(m) %d estrada(s)\n", k, estradas );
        else
            printf( "Caso #%d: a promessa foi cumprida\n", k );
    }

    return 0;
}
