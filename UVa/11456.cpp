#include <iostream>
#include <algorithm>
using namespace std;

int A[2500], Ma[2500], Mb[2500];
int N, T;

int main() {
    int t;

    cin >> t;
    while( t-- ) {
        int n;

        cin >> n;
        for( int i = 0; i < n; i++ )
            cin >> A[i];

        for( int i = n - 1; i >= 0; i-- ) {
            Ma[i] = 1;
            for( int j = i + 1; j < n; j++ )
                if( A[i] < A[j] ) {
                    Ma[i] = max( Ma[j] + 1, Ma[i] );
        }
        for( int i = n - 1; i >= 0; i-- ) {
            Mb[i] = 1;
            for( int j = i + 1; j < n; j++ )
                if( A[i] > A[j] )
                    Mb[i] = max( Mb[j] + 1, Mb[i] );
        }
        int ans = 0;
        for( int i = 0; i < n; i++ )
            ans = max( ans, Ma[i] + Mb[i] - 1 );
        cout << ans << endl;
    }
}
