#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi G[100005];
int n1, n2, d, dep1[100005], dep2[100005];

int main() {
    int troca[2], isnt;
    queue<int> fila1, fila2;

    while( scanf( "%d%d%d", &n1, &n2, &d ) && n1 ) {
        for( int i = 1; i <= 100000; i++ )
            G[i].clear();
        memset( dep1, 0, sizeof dep1 );
        memset( dep2, 0, sizeof dep2 );

        for( int i = 0, x, y; i < d; i++ ) {
            scanf( "%d%d", &x, &y );
            G[y].push_back(x);
            dep1[x]++;
            dep2[x]++;
        }

        if( !fila1.empty() ) fila1.pop();
        if( !fila2.empty() ) fila2.pop();

        for( int u = 1; u <= n1+n2; u++ )
            if( dep1[u] == 0 ) {
                if( u <= n1 )
                    fila1.push(u);
                else
                    fila2.push(u);
            }

        troca[0] = isnt = 0;
        while( isnt < n1+n2 ) {
            troca[0]++;
            while( !fila1.empty() ) {
                int u = fila1.front(); fila1.pop();
                isnt++;
                for( int i = 0, v; i < G[u].size(); i++ ) {
                    v = G[u][i];
                    dep1[v]--;
                    if( dep1[v] == 0 ) {
                        if( v <= n1 )
                            fila1.push(v);
                        else
                            fila2.push(v);
                    }
                }
            }

            if( isnt == n1+n2 ) break;

            troca[0]++;
            while( !fila2.empty() ) {
                int u = fila2.front(); fila2.pop();
                isnt++;
                for( int i = 0, v; i < G[u].size(); i++ ) {
                    v = G[u][i];
                    dep1[v]--;
                    if( dep1[v] == 0 ) {
                        if( v <= n1 )
                            fila1.push(v);
                        else
                            fila2.push(v);
                    }
                }
            }
        }
        troca[0]++;

        if( !fila1.empty() ) fila1.pop();
        if( !fila2.empty() ) fila2.pop();

        for( int u = 1; u <= n1 + n2; u++ )
            if( dep2[u] == 0 ) {
                if( u <= n1 )
                    fila1.push(u);
                else
                    fila2.push(u);
            }
        troca[1] = isnt = 0;
        while( isnt < n1+n2 ) {
            troca[1]++;
            while( !fila2.empty() ) {
                int u = fila2.front(); fila2.pop();
                isnt++;
                for( int i = 0, v; i < G[u].size(); i++ ) {
                    v = G[u][i];
                    dep2[v]--;
                    if( dep2[v] == 0 ) {
                        if( v <= n1 )
                            fila1.push(v);
                        else
                            fila2.push(v);
                    }
                }
            }

            if( isnt == n1+n2 ) break;

            troca[1]++;
            while( !fila1.empty() ) {
                int u = fila1.front(); fila1.pop();
                isnt++;
                for( int i = 0, v; i < G[u].size(); i++ ) {
                    v = G[u][i];
                    dep2[v]--;
                    if( dep2[v] == 0 ) {
                        if( v <= n1 )
                            fila1.push(v);
                        else
                            fila2.push(v);
                    }
                }
            }
        }
        troca[1]++;

        cout << min( troca[0], troca[1] ) << endl;
    }

    return 0;
}
