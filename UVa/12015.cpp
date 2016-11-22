#include <bits/stdc++.h>
#define pb push_back
using namespace std;

map<int, vector<string> > m;

int main() {
    int t, size, max_s;
    string site;
    
    cin >> t;
    for( int _case = 1; _case <= t; _case++ ) {
        max_s = 0;
        m.clear();
        for( int i = 0; i < 10; i++ )
            cin >> site >> size,
            m[size].pb( site ),
            max_s = max( max_s, size );
        
        cout << "Case #" << _case << ":" << endl;
        for( int i = 0; i < (int)m[max_s].size(); i++ )
            cout << m[max_s][i] << endl;
    }

    return 0;
}
