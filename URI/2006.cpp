#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, p, count = 0;
    
    cin >> t;
    for( int i = 0; i < 5; i++ )
        cin >> p, count += ( p == t ? 1 : 0 );
    cout << count << endl;

    return 0;
}
