#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

int n, m, visited[105][105], dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
char mapa[105][105];

void bfs( point u ) {
    memset( visited, -1, sizeof visited );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ )
            visited[i][j] = INT_MAX;
     
    queue<point> q;
    q.push( u );
    visited[u.x][u.y] = 0;    
    
    while( !q.empty() ) {
        u = q.front(); q.pop();
        
        for( int i = 0; i < 4; i++ ) {
            point v = point( u.x + dx[i], u.y + dy[i] );
            // i 0 >
            // i 1 <
            // i 2 v
            // i 3 ^
            
            if( 0 <= v.x && v.x < n && 0 <= v.y && v.y < m ) {
                if( visited[v.x][v.y] > visited[u.x][u.y] ) {
                    if( i == 0 ) {
                        if( mapa[v.x][v.y] == '>' ) {
                            visited[v.x][v.y] = visited[u.x][u.y] + 1;
                            q.push( v );
                        } else if( mapa[v.x][v.y] == '<' ) {
                            visited[v.x][v.y] = visited[u.x][u.y];
                            q.push( v );
                        }
                    }
                    if( i == 1 ) {
                        if( mapa[v.x][v.y] == '<' ) {
                            visited[v.x][v.y] = visited[u.x][u.y] + 1;
                            q.push( v );
                        } else if( mapa[v.x][v.y] == '>' ) {
                            visited[v.x][v.y] = visited[u.x][u.y];
                            q.push( v );
                        }
                    }
                    if( i == 2 ) {
                        if( mapa[v.x][v.y] == 'v' ) {
                            visited[v.x][v.y] = visited[u.x][u.y] + 1;
                            q.push( v );
                        } else if( mapa[v.x][v.y] == '^' ) {
                            visited[v.x][v.y] = visited[u.x][u.y];
                            q.push( v );
                        }
                    }
                    if( i == 3 ) {
                        if( mapa[v.x][v.y] == '^' ) {
                            visited[v.x][v.y] = visited[u.x][u.y] + 1;
                            q.push( v );
                        } else if( mapa[v.x][v.y] == 'v' ) {
                            visited[v.x][v.y] = visited[u.x][u.y];
                            q.push( v );
                        }
                    }
                }
            }
        }
    }
}

bool borda( int x, int y ) {
    return x == 0 || y == 0 || x == n-1 || y == m-1;
}

int main() {
    int k; 
    point px;

    while( scanf( "%d%d%d", &n, &m, &k ) && n ) {
        for( int i = 0 ; i < n; i++ )
            for( int j = 0 ; j < m; j++ ) {
                scanf( " %c", &mapa[i][j] );
                if( mapa[i][j] == 'x' )
                    px = point( i, j );
            }

        bfs( px );
        bool b = false;
        for( int i = 0; i < n && !b; i++ ) {
            for( int j = 0; j < m && !b; j++ ) {
                //printf( "%d ", visited[i][j] );
                if( borda( i, j ) ) {
                    if( visited[i][j] - k <= 0 )
                        b = true;
                }
            }
            //printf( "\n" );
        }
        
        printf( "%s\n", ( b ? "Sim" : "Nao" ) );
    }    

    return 0;
}
