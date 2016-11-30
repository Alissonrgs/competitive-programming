#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct player {
    string name;
    int a, d;
    player( string _name, int _a, int _d ) : name(_name), a(_a), d(_d) {}
};

vector<player> v;

bool comp( player A, player B ) {
    if( A.a == B.a ) {
        if( A.d == B.d )
            return A.name < B.name;
        return A.d < B.d;
    }
    return A.a > B.a;
}

int main() {
    int t, a, d, _case = 1;
    string name;
    
    cin >> t;
    while( t-- ) {
        v.clear();
        for( int i = 0; i < 10; i++ ) {
            cin >> name >> a >> d;
            v.pb( player( name, a, d ) );
        }
        sort( v.begin(), v.end(), comp );
        vector<string> v1, v2;
        for( int i = 0; i < 5; i++ )
            v1.pb( v[i].name );
        for( int i = 5; i < 10; i++ )
            v2.pb( v[i].name );
        sort( v1.begin(), v1.end() );
        sort( v2.begin(), v2.end() );
    
        cout << "Case " << _case++ << ":" << endl << "(";
        cout << v1[0];
        for( int i = 1; i < 5; i++ )
            cout << ", " << v1[i];
        cout << ")" << endl << "(";
        cout << v2[0];
        for( int i = 1; i < 5; i++ )
            cout << ", " << v2[i];
        cout << ")" << endl;
        
    }

    return 0;
}
