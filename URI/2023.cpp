#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
    string nome;

    while( getline( cin, nome ) )
        v.push_back( nome );

    sort( v.begin(), v.end(), []( string a, string b ) {
        for( int i = 0; i < (int)a.size(); i++ )
            if( isalpha( a[i] ) )
                a[i] = tolower( a[i] );
        for( int i = 0; i < (int)b.size(); i++ )
            if( isalpha( b[i] ) )
                b[i] = tolower( b[i] );
        return a < b;
    });
    cout << v[(int)v.size()-1] << endl;

    return 0;
}
