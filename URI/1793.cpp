#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, c, tu;
    
    while( cin >> n && n ) {
        t = tu = 0;
        while( n-- ) {
            cin >> c;
            if( c >= t )
                tu += 10;
            else
                tu += 10 - t + c;
            t = c + 10;
        }
        cout << tu << endl;
    }

    return 0;
}
