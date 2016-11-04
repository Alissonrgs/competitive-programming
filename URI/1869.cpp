#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int

string dec_to_base32( ull n ) {
    string c = "0123456789ABCDEFGHIJKLMNOPQRSTUV", base32 = "";
    
    while( n ) {
        base32 += c[ n%32 ];
        n /= 32;
    }
    reverse( base32.begin(), base32.end() );

    return base32;
}

int main() {
    ull n;

    while( cin >> n && n )
        cout << dec_to_base32( n ) << endl;
    cout << "0\n";

    return 0;
}
