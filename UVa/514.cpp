#include <bits/stdc++.h>
using namespace std;

queue<int> in, out;
stack<int> s;

int main() {
    int n, t;
    
    while( cin >> n && n ) {
        while( cin >> t && t ) {
            while( !in.empty() ) in.pop();
            while( !out.empty() ) out.pop();
            while( !s.empty() ) s.pop();
            for( int i = 1; i <= n; i++ )
                in.push( i );
            out.push( t );
            for( int i = 1; i < n; i++ )
                cin >> t, out.push( t );
            
            while( !out.empty() ) {
                if( !s.empty() && out.front() == s.top() ) {
                    out.pop();
                    s.pop();
                } else if( !in.empty() ) {
                    s.push( in.front() );
                    in.pop();
                } else
                    break;
            }
            if( out.empty() ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}
