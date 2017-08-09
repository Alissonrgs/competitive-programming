#include <bits/stdc++.h>
using namespace std;

int main() {
   int s, _case = 1, q[13];
   
   while( scanf( "%d", &s ) && s >= 0 ) {
      q[0] = s;
      for( int i = 1; i <= 12; i++ )
         scanf( "%d", &q[i] );
         
      printf( "Case %d:\n", _case++ );
      for( int i = 1; i <= 12; i++ ) {
         scanf( "%d", &s );
         if( s > q[i-1] )
            printf( "No problem. :(\n" );
         else {
            q[i-1] -= s;
            printf( "No problem! :D\n" );
         }
         q[i] += q[i-1];
      }
   }

   return 0;
}
