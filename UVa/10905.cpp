#include <bits/stdc++.h>
using namespace std;

vector<string> v;

bool comp( string a, string b ) {
   string ab = a + b,
          ba = b + a;
   return ab > ba;
}

int main() {
   int n;
   string s;
   
   while( cin >> n && n ) {
      v.clear();
      for( int i = 0; i < n; i++ )
         cin >> s, v.push_back( s );
      sort( v.begin(), v.end(), comp );
      for( int i = 0; i < (int)v.size(); i++ )
         cout << v[i];
      cout << endl;      
   }
   
   return 0;
}
