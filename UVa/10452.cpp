#include <bits/stdc++.h>
#define point pair<int,int>
#define X first
#define Y second
using namespace std;

char lab[8][8];
int n, m, d[8][8], dx[] = { 0, 0, -1 }, dy[] = { 1, -1, 0 };
map<point, point> f;
point a, b;
string IEHOVA = "IEHOVA#";

bool valid( point p ) { return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < m; } 
bool equal( point p1, point p2 ) { return p1.X == p2.X && p1.Y == p2.Y; }

void dfs( point u, int id ) {
    if( id > 6 ) return;

    for( int i = 0; i < 3; i++ ) {
        point v = point( u.X + dx[i], u.Y + dy[i] );
        
        if( valid( v ) && !d[v.X][v.Y] && lab[v.X][v.Y] == IEHOVA[id] ) {
            d[v.X][v.Y] = 1;
            f[u] = point( v.X, v.Y );
            dfs( v, id+1 );
            d[v.X][v.Y] = 0;
        }
    }
}

int main() {
    int t;
    
    cin >> t;
    while( t-- ) {
        cin >> n >> m;
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ ) {
                cin >> lab[i][j];
                if( lab[i][j] == '@' )
                    a = point( i, j );
                if( lab[i][j] == '#' )
                    b = point( i, j );
            }
        f.clear();
        memset( d, 0, sizeof d );
        dfs( a, 0 );
        
        bool e = false;
        while( !equal( a, b ) ) {
            if( e ) putchar( ' ' );
            e = true;
            
            if( a.Y-1 == f[a].Y )
                cout << "left";
            if( a.Y+1 == f[a].Y )
                cout << "right";
            if( a.X-1 == f[a].X )
                cout << "forth";
            a = f[a];
        }
        putchar( '\n' );
    }
    
    return 0;
}
