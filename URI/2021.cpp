#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, p, q, x;
    
    while( cin >> m >> n >> p && m ) {
        x = 0;
        while( p-- ) {
            cin >> q;
            x += n - (q-1)%n;
        }
        cout << "Lights: " << x << endl;
    }

    return 0;
}
