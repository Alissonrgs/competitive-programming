#include <iostream>
#include <map>
using namespace std;

map<string,int> mapa;
map<string,int>::iterator it;
 
int main() {
    int n, qnt;
    string arv;
    bool barraN = false;
 
    cin >> n;
    cin.ignore();
    getline( cin, arv );
    while( n-- ) {
        if( barraN ) cout << endl;
        qnt = 0;
        mapa.clear();
 
        while( getline( cin, arv ) ) {
            if( arv.size() == 0 ) break;
            if( !mapa[arv] ) mapa[arv] = 1;
            else mapa[arv]++;
            qnt++;
        }
        cout.precision(4);
        for( it=mapa.begin(); it!=mapa.end(); it++ )
            cout << fixed << it->first << " " << 100.0*it->second/qnt << endl;
    	barraN = true;
    }
 
    return 0;
}