#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<string> v;

bool comp( string a, string b ) {
   for( int i = 0; i < (int)a.size(); i++ ) {
      char x = tolower( a[i] );
      char y = tolower( b[i] );
      if( x == y && a[i] != b[i] )
         return a < b;
      else if( a[i] != b[i] )
         return x < y;
   }
   return a < b;
}

int main() {
   int n;
   string str;
   
   cin >> n;
   while( n-- ) {
      cin >> str;
      sort( str.begin(), str.end() );
      
      v.clear();
      do
         v.pb( str );
      while( next_permutation( str.begin(), str.end() ) );
   
      sort( v.begin(), v.end(), comp );
      for( string s : v )
         cout << s << endl;
   }

   return 0;
}
