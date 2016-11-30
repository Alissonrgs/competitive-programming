#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define LSOne(s) ( s & (-s) )
using namespace std;

class FenwickTree {
   private:
      vll ft;
   public:
      FenwickTree( int n ) { ft.assign( n+1, 0 ); }
      ll rsq( int b ) {
         ll sum = 0;
         for( ; b; b -= LSOne( b ) ) sum += ft[b];
         return sum;
      }
      ll rsq( int a, int b ) {
         return rsq( b ) - ( a == 1 ? 0 : rsq( a-1 ) );
      }
      void update( int k, ll v ) {
         for( ; k < (int)ft.size(); k += LSOne( k ) )
            ft[k] += v;
      }
};

int main() {
   int n, u, v, _case = 1;
   string o;
   bool e = false;
   
   while( cin >> n && n ) {
      FenwickTree ft( n );
      
      for( int i = 1; i <= n; i++ ) {
         cin >> v;
         ft.update( i, v );
      }
      if( e ) putchar( '\n' );
      e = true;
      cout << "Case " << _case++ << ":" << endl;
      while( cin >> o && o != "END" ) {
         cin >> u >> v;
         if( o[0] == 'M' )
            cout << ft.rsq( u, v ) << endl;
         else {
            ft.update( u, -ft.rsq( u, u ) );
            ft.update( u, v );
         }
      }
   }
   
   return 0;
}
