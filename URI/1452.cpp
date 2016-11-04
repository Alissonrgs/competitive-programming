#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

map< string, vector<int> > mapa;
bool server[205];

int main() {
	int n, m, q, qnt;
    string app;

	while( cin >> n >> m && n ) {
        mapa.clear();
        for( int i=0; i<n; i++ ) {
            cin >> q;
            for( int j=0; j<q; j++ ) {
                cin >> app;
                mapa[app].push_back(i);
            }
    	}
        qnt = 0;
        for( int i=0; i<m; i++ ) {
            memset( server, false, sizeof server );
            cin >> q;
            for( int j=0; j<q; j++ ) {
                cin >> app;
                for( int k=0; k<mapa[app].size(); k++ )
                    if( !server[ mapa[app][k] ] )
                        qnt++, server[ mapa[app][k] ] = true;
            }
        }
        cout << qnt << endl;
    }

	return 0;
}