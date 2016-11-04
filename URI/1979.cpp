#include <bits/stdc++.h>
using namespace std;

vector<int> G[105];
int cor[105];

bool dfs( int u, int c ) {
    bool p = true;
    cor[u] = c;
    
    for( int i = 0; i < G[u].size() && p; i++ ) {
        int v = G[u][i];
        
        if( !cor[v] ) {
            cor[v] = c;
            p = dfs( v, ( c == 1 ? 2 : 1 ) );
        } else
            p = ( cor[u] != cor[v] );
    }
    return p;
}

int main() {
    int n, x, y;
    string e;
    
    while( cin >> n && n ) {
        for( int i = 1; i <= n; i++ ) G[i].clear();
        for( int i = 0; i < n; i++ ) {
            cin >> x;
            cin.ignore();
            getline( cin, e );
            stringstream ss;
            ss << e;
            while( !ss.eof() ) {
                ss >> y;
                G[x].push_back( y );
                G[y].push_back( x );
            }
        }
        memset( cor, 0, sizeof cor );
        if( dfs( 1, 1 ) )
            cout << "SIM\n";
        else
            cout << "NAO\n";
    }

    return 0;
}
