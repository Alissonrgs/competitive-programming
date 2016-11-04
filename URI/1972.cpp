#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

int n, m;
int d[505][505], dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
char l[505][505];

void dijkstra( point u ) {
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m ; j++ )
            d[i][j] = INT_MAX;
            
    queue<point> q;
    q.push( u );
    d[u.x][u.y] = 0;
    
    while( !q.empty() ) {
        u = q.front();
        q.pop();
        
        for( int i = 0; i < 4; i++ ) {
            point v = point( u.x + dx[i], u.y + dy[i] );
            int vd = 0;
            
            if( 0 <= v.x && v.x < n && 0 <= v.y && v.y < m && l[v.x][v.y] != '#' ) {
                if( l[v.x][v.y] != 'H' && l[v.x][v.y] != 'E' && l[v.x][v.y] != '.' )
               		vd = (int)l[v.x][v.y] - (int)'0';
                    
                if( d[v.x][v.y] > d[u.x][u.y] + vd ) {
                    d[v.x][v.y] = d[u.x][u.y] + vd;
                    q.push( v );
                }
            }
        }
    }
}

int main() {
    point H, E;

    cin >> n >> m;
    
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ ) {
            cin >> l[i][j];
            if( l[i][j] == 'H' )
                H = point( i, j );
            if( l[i][j] == 'E' )
                E = point( i, j );
        }
        
    dijkstra( H );
    if( d[E.x][E.y] == INT_MAX )
        printf( "ARTSKJID\n" );
    else
        printf( "%d\n", d[E.x][E.y] );   
    
    return 0;
}
