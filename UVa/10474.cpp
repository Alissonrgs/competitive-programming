#include <bits/stdc++.h>
#define NMAX 10000
using namespace std;

int v[NMAX+1];

int binary_search( int l, int r, int x ) {
   int m;
   
   while( l <= r ) {
      m = ( l + r )/2;
      if( v[m] == x ) {
         if( m-1 >= 0 && v[m] == v[m-1] ) {
            r = m-1;
            continue;
         }
         return m;
      }
      if( v[m] < x )
         l = m+1;
      else
         r = m-1;
   }
   return -1;
}

int main() {
   int n, q, _case = 1;
   
   while( scanf( "%d%d", &n, &q ) && n ) {
      for( int i = 0; i < n; i++ )
         scanf( "%d", &v[i] );
      sort( v, v+n );
      printf( "CASE# %d:\n", _case++ );
      for( int i = 0, x; i < q; i++ ) {
         scanf( "%d", &x );
         int p = binary_search( 0, n, x );
         if( p == -1 )
            printf( "%d not found\n", x );
         else
            printf( "%d found at %d\n", x, p+1 );
      }
   }

   return 0;
}
