#include <bits/stdc++.h>
using namespace std;

int mapa[1000000];
map< int, queue<int> > fila;
queue<int> ord;

int main() {
    int t, n, id, cenario = 1;
    string comando;
    
    while( cin >> t && t ) {
        fila.clear();
        while( !ord.empty() )
            ord.pop();
        
        for( int i = 0; i < t; i++ ) {
            scanf( "%d", &n );
            for( int j = 0; j < n; j++ ) {
                scanf( "%d", &id );
                mapa[id] = i;
            }
        }
        cout << "Scenario #" << cenario++ << endl;
        while( cin >> comando && comando != "STOP" ) {
            if( comando == "ENQUEUE" ) {
                cin >> id;
                if( fila[ mapa[id] ].size() ) {
                    fila[ mapa[id] ].push( id );
                } else {
                    ord.push( mapa[id] );
                    fila[ mapa[id] ].push( id );
                }
                
            } else {
                cout << fila[ ord.front() ].front() << endl;
                fila[ ord.front() ].pop();
            
                if( fila[ ord.front() ].empty() )
                    ord.pop();
            }
        }
        cout << endl;
    }

    return 0;
}
