#include <bits/stdc++.h>
#define NMAX 18
#define ll long long
using namespace std;

int v[NMAX+1];

int main() {
   int n, _case = 1;
   
   while( ~scanf( "%d", &n ) && n ) {
      for( int i = 0; i < n; i++ )
         scanf( "%d", &v[i] );
      
      ll maxp = 0;
      for( int i = 1; i <= n; i++ ) {
         for( int j = 0; j < n; j++ ) {
            ll p = 1;
            for( int k = j; k < j + i && k < n; k++ )
               p *= v[k];
            maxp = max( maxp, p );
         }
      }
   
      printf( "Case #%d: The maximum product is %Ld.\n\n", _case++, maxp );
   }

   return 0;
}
