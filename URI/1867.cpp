#include <bits/stdc++.h>
using namespace std;

int ctoi( char c ) {
    return (int)( c - '0' );
}

char itoc( int i ) {
    return (char)( i + '0' );
}

int cal_alg( string n ) {
    int result = 0;    
    for( int i = 0; i < (int)n.size(); i++ )
        result += ctoi( n[i] );
    
    if( result >= 10 ) {
        n.clear();
        while( result ) {
            n += itoc( result%10 );
            result /= 10;
        }
        reverse( n.begin(), n.end() );
        return cal_alg( n );
    }
    return result;
}

int main() {
    int a1, a2;
    string n1, n2;
    
    while( cin >> n1 >> n2 ) {
        if( n1 == "0" && n2 == "0" )
            break;
        a1 = cal_alg( n1 );
        a2 = cal_alg( n2 );
        if( a1 == a2 )
            cout << "0" << endl;
        else
            cout << ( a1 > a2 ? "1" : "2" ) << endl;
    }
    
    return 0;
}
