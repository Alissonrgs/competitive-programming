#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int** multM( int **m1, int **m2, int b ) {
    int **M;
     
    M = new int*[3];
    for( int i=0; i<3; i++ ) {
        M[i] = new int[3];
        for( int j=0; j<3; j++ ) {
            M[i][j] = 0;
            for( int k=0; k<3; k++ )
                M[i][j] = ( M[i][j] + m1[i][k]*m2[k][j] )%b;
        }
    }
    return M;
}
 
int main() {
    int **M, **x, b, c = 1;
    ll n, temp;
     
    M = new int*[3];
    x = new int*[3];
    for( int i=0; i<3; i++ )
        M[i] = new int[3], x[i] = new int[3];
         
    while( scanf( "%lld%d", &n, &b ) && b ) {
        temp = n;
        x[0][0] = 0, x[0][1] = 1, x[0][2] = 0;
        x[1][0] = 1, x[1][1] = 1, x[1][2] = 0;
        x[2][0] = 0, x[2][1] = 1, x[2][2] = 1;
         
        M[0][0] = 1, M[0][1] = 0, M[0][2] = 0;
        M[1][0] = 0, M[1][1] = 1, M[1][2] = 0;
        M[2][0] = 0, M[2][1] = 0, M[2][2] = 1;
         
        while( temp ) {
            if( temp&1 )
                M = multM( M, x, b );
            x = multM( x, x, b );
            temp >>= 1;
        }
        printf( "Case %d: %lld %d %d\n", c++, n, b, ( M[0][0] + M[1][0] + M[2][0] )%b );
    }   
 
    return 0;
}