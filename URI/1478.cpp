#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, **M, k, s;

    while( cin >> n && n ) {
        M = new int*[n];
        for( int i=0; i<n; i++ ) {
            M[i] = new int[n];
            k = i+2;
            s = -1;
            for( int j=0; j<n; j++ ) {
                k += s;
                M[i][j] = k;
                if( k == 1 ) s = 1;

                cout << setw(3) << M[i][j] << ( j == n-1 ? "\n" : " " );
            }
        }
        cout << endl;
    }

    return 0;
}
