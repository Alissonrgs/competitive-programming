#include <bits/stdc++.h>
using namespace std;

vector<int> G[1001];
int cor[1001];

int main() {
    int n, x, y, q;
    char c;
    
    while( scanf( "%d", &n ) && n ) { 
        for( int i = 1; i <= 1000; i++ )
            G[i].clear();
        memset( cor, 0, sizeof cor );
        q = 0;
        
        for( int i = 0; i < n; i++ ) {
            scanf( " %c%d%c%d%c", &c, &x, &c, &y, &c );
            G[x].push_back(y);
            G[y].push_back(x);
        }
        queue<int> fila;
        fila.push(1);
        
        while( !fila.empty() ) {
            int i = fila.front();
            fila.pop();
            
            if( cor[i] ) continue;
            cor[i] = 1;
            q++;
        
            for( int j = 0; j < G[i].size(); j++ ) {
                int k = G[i][j];
                if( !cor[k] )
                    fila.push(k);
            }
        }
        
        printf( "%d\n", q );
    }
    
    return 0;
}
