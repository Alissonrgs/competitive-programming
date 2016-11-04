#include <bits/stdc++.h>
using namespace std;

int char_to_int( char c ) {
    return c - '0';
}

int sum( string m ) {
    int s = 0;
    for( int i = 0; i < m.size(); i++ )
        s += char_to_int( m[i] );
    return s;
}

int main() {
    int n;
    string m;
    
    while( cin >> n >> m ) {
        int soma = sum( m );
        cout << soma << " " << ( soma%3 == 0 ? "sim" : "nao" ) << endl;
    }

    return 0;
}
