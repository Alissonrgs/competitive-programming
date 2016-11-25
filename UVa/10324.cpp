#include <bits/stdc++.h>
#define NMAX 1000000
using namespace std;

int sum[NMAX+1];

int ctoi( char c ) { return (int)( c - '0' ); }

int main() {
    string s;
    int q, i, j, _case = 1;
   
    while( cin >> s ) {
        sum[0] = ctoi( s[0] );
        for( int k = 1; k < (int)s.size(); k++ )   
            sum[k] = sum[k-1] + ctoi( s[k] );
   
        cin >> q;
        cout << "Case " << _case++ << ":" << endl;
        while( q-- ) {
            cin >> i >> j;
            if( i > j ) swap( i, j );
         
            int v = sum[j] - sum[i] + ctoi( s[i] );
            if( v == j-i+1 || v == 0 )
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
      }
   }

   return 0;
}
