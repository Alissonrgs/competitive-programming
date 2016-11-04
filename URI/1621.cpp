#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

int n, m, d[505][505], dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 }, maior;
char l[505][505];

void bfs( point u ) {
    queue<point> fila;
    fila.push( u );
    d[u.x][u.y] = 0;

    while( !fila.empty() ) {
        u = fila.front();
        fila.pop();
        
        for( int i = 0; i < 4; i++ ) {
            point v = point( u.x + dx[i], u.y + dy[i] );
            
            if( 0 <= v.x && v.x < n && 0 <= v.y && v.y < m )
                if( l[v.x][v.y] != '#' && d[v.x][v.y] == -1 ) {
                    d[v.x][v.y] = d[u.x][u.y] + 1;
                    fila.push( v );
                }
        }
    }
}

int main() {
    while( scanf( "%d%d", &n, &m ) && n ) {
        point a( -1, -1 ), b;
        
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ ) {
                scanf( " %c", &l[i][j] );
                if( l[i][j] != '#' && a == point(-1,-1) )
                    a = point(i,j);
            }
        
        memset( d, -1, sizeof d );    
        bfs( a );
        
        maior = 0;
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                if( d[i][j] > maior ) {
                    b = point(i,j);
                    maior = max( maior, d[i][j] );
                }
        
        memset( d, -1, sizeof d );
        bfs( b );
        
        maior = 0;
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                if( d[i][j] > maior )
                    maior = max( maior, d[i][j] );

        printf( "%d\n", maior );
    }

    return 0;
}
