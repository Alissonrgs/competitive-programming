#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, d, r, dist;
   char str;
   
   while( cin >> n && n ) {
      dist = INT_MAX;
      d = r = -1;
      
      for( int i = 0; i < n; i++ ) {
         cin >> str;
         if( str == 'Z' )
            dist = 0;
         if( str == 'D' ) {
            d = i;
            if( r != -1 )
               dist = min( dist, abs( d - r ) );
         }
         if( str == 'R' ) {
            r = i;
            if( d != -1 )
               dist = min( dist, abs( d - r ) );
         }
      }
      
      cout << dist << endl;
   }

   return 0;
}
