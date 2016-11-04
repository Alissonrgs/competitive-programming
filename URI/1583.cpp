#include <bits/stdc++.h>
#define point pair<int,int>
#define x first
#define y second
using namespace std;

vector<point> T;
char mapa[55][55];
int n, m, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

bool check( int a, int b ) {
    return 0 <= a && a < n && 0 <= b && b < m; 
}

void dfs( point u ) {
    mapa[u.x][u.y] = 'T';
    
    for( int i = 0; i < 4; i++ ) {
        point v = point( u.x + dx[i], u.y + dy[i] );
        if( check( v.x, v.y ) && mapa[v.x][v.y] == 'A' )
            dfs( v );
    }
}

void print_map() {
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ )
            printf( "%c", mapa[i][j] );
        printf( "\n" );
    }
    printf( "\n" );
}

int main() {
    while( cin >> n >> m && n ) {
        T.clear();
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                cin >> mapa[i][j];
                if( mapa[i][j] == 'T' )
                    T.push_back( make_pair( i, j ) );
            }
        }
        for( int i = 0; i < T.size(); i++ )
            dfs( T[i] );
        print_map();
    }

    return 0;
}
