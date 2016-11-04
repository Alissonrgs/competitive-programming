#include <bits/stdc++.h>
using namespace std;

int v[100005], p[100005];

int binary_search( int i, int f, int k ) {
    if( k >= v[f] ) return f;
    int m = ( i + f ) / 2;
    int ans = 0;
    while( i <= f ) {
        m = ( i + f ) / 2;
        if( v[m] > k )
            f = m-1;
        else if( v[m] <= k )
            i = m+1,
            ans = m;
    }
    return ans;
}

int main() {
    int n, m, o;
    
    cin >> n >> m;
    for( int i = 1; i <= n-1; i++ )
        cin >> v[i];
    for( int i = 1; i <= n; i++ )
        cin >> p[i];
    bool e = false;
    for( int i = 1; i <= m; i++ ) {
        cin >> o;
        int j = binary_search( 1, n-1, o );
        j++;
        if( e )
            cout << " ";
        cout << p[j];
        e = true;
    }
    cout << endl;
    
    return 0;
}
