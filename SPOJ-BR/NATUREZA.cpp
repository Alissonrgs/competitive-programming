#include <bits/stdc++.h>
using namespace std;

map<string,int> mapa;
vector<int> G[5005];
int cor[5005];

int dfs( int i ) {
    int cadeia = 1;
    cor[i] = 1;
    
    for( int j = 0; j < G[i].size(); j++ ) {
        int k = G[i][j];
        if( !cor[k] )
            cadeia += dfs(k);
    }
    
    return cadeia;
}

int main() {
    int c, r, cadeia;
    string criatura, c1, c2;
    
    while( scanf( "%d%d", &c, &r ) && c ) {
        mapa.clear();
        for( int i = 1; i <= 5000; i++ )
            G[i].clear();
        memset( cor, 0, sizeof cor );
        cadeia = 0;
        
        for( int i = 1; i <= c; i++ ) {
            cin >> criatura;
            mapa[criatura] = i;
        }
        for( int i = 0; i < r; i++ ) {
            cin >> c1 >> c2;
            G[ mapa[c1] ].push_back( mapa[c2] );    
            G[ mapa[c2] ].push_back( mapa[c1] );
        }
        
        for( int i = 1; i <= c; i++ )
            if( !cor[i] )
                cadeia = max( cadeia, dfs( i ) );
        
        printf( "%d\n", cadeia );
    }

    return 0;
}
