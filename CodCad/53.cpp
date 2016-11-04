#include <bits/stdc++.h>
using namespace std;

int v[100005];

int binary_search( int i, int f, int k ) {
    int m = ( i + f ) / 2;
    
    while( i <= f ) {
        m = ( i + f ) / 2;
        if( v[m] > k )
            f = m-1;
        else if( v[m] < k )
            i = m+1;
        else
            return m;
    }
    return -1;
}

int main() {
    int n, k;
    
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> v[i];
    cin >> k;
    for( int i = 1; i <= n; i++ ) {
        //int j = binary_search( 1, n, k - v[i] );
        int j = lower_bound( v+1, v+n+1, k - v[i] ) - v;
        if( k - v[i] == v[j] ) {
            if( v[i] > v[j] )
                swap( v[i], v[j] );
            cout << v[i] << " " << v[j] << endl;
            break;
        }
    }
    
    return 0;
}
