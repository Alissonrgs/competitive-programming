#include <bits/stdc++.h>
using namespace std;

queue<int> ql, qr;

int main() {
    int c, l, m, length, ans;
    string d;
    
    cin >> c;
    while( c-- ) {
        cin >> l >> m;
        l *= 100;
        while( m-- ) {
            cin >> length >> d;
            if( d == "left" )
                ql.push( length );
            else
                qr.push( length );
        }
        
        int b = 0;
        ans = length = 0;
        while( !ql.empty() || !qr.empty() ) {
            if( b == 0 ) {
                while( !ql.empty() && length + ql.front() <= l ) {
                    length += ql.front();
                    ql.pop();
                }
                
            } else {
                while( !qr.empty() && length + qr.front() <= l ) {
                    length += qr.front();
                    qr.pop();
                }
            }
            b = !b;
            length = 0;
            ans++;
        }
        cout << ans << endl;
    } 

    return 0;
}
