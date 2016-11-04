#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

char G[1030][1030];
int n, m, cor[1030][1030], dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

void dfs( point u ) {
    cor[u.x][u.y] = 1;

    for( int i = 0; i < 4; i++ ) {
        point v = point( u.x + dx[i], u.y + dy[i] );
        
        if( 0 <= v.x && v.x < n && 0 <= v.y && v.y < m )
            if( !cor[v.x][v.y] )
                dfs( v );
    }
}

int main() {
    memset( cor, 0, sizeof cor );
    
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ ) {
            scanf( " %c", &G[i][j] );
            if( G[i][j] == 'o' )
                cor[i][j] = 1;
        }
    
    int cores = 0;
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ )
            if( !cor[i][j] ) {
                dfs( point( i, j ) );
                cores++;
            }

    printf( "%d\n", cores );
    
    return 0;
}
