#include <bits/stdc++.h>
#define NMAX 10000
using namespace std;

int v[NMAX+1];

int main() {
   int a, c;
   
   while( scanf( "%d", &a ) && a ) {
      scanf( "%d", &c );
      for( int i = 0; i < c; i++ )
         scanf( "%d", &v[i] );
      v[c] = a;
         
      int ans = 0;
      for( int i = 1 ; i <= c; i++ )
         if( v[i] > v[i-1] )
            ans += v[i] - v[i-1];
            
      printf( "%d\n", ans );
   };

   return 0;
}
