#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, **M;

    while( cin >> n && n ) {
        M = new int*[n];
        for( int i=0; i<n; i++ ) {
            M[i] = new int[n];
            for( int j=0; j<n; j++ ) {
                for( int k=0; k<=n/2; k++ )
                    if( i == k || j == k || i == n-k-1 || j == n-k-1 ) {
                        M[i][j] = k+1;
                        break;
                    }
                cout << setw(3) << M[i][j] << ( j == n-1 ? "\n" : " " );
            }
        }
        cout << endl;
    }

    return 0;
}
