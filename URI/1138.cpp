#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll digits( int n, int d ) {
    ll res = 0, pot = 1, rem = 0;
    
    while( n ) {
        int x = n%10;
        n /= 10;
         
        if( x > d )
            res += ( n+1 )*pot;
        else
            res += n*pot;
        
        if( x == d )
            res += rem+1;
        
        if( d == 0 )
            res -= pot;
        
        rem += pot*x;
        pot *= 10;
    }
    
    return res;
}

int main() {
    int A, B;
    
    while( cin >> A >> B && A ) {
        cout << digits( B, 0 ) - digits( A-1, 0 );
        for( int i = 1; i < 10; i++ )
            cout << " " << digits( B, i ) - digits( A-1, i );
        cout << endl;
    }
    
    return 0;
}
