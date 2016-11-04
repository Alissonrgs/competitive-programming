#include <bits/stdc++.h>
using namespace std;

int main() {
    int uns = 0;
    string n;
    
    cin >> n;
    for( int i = 0; i < (int)n.size(); i++ )
        if( n[i] == '1' )
            uns++;
    
    cout << n << ( uns&1 ? "1" : "0" ) << endl;

    return 0;
}
