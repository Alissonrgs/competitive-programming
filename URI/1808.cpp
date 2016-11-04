#include <bits/stdc++.h>
using namespace std;

int ctoi( char c ) {
    return c - '0';
}

int ctoi( char c1, char c2 ) {
    int i_c1 = ctoi( c1 );
    int i_c2 = ctoi( c2 );
    return 10*i_c1 + i_c2;
}

int main() {
    int sum = 0, qn = 0;
    string n;
    
    cin >> n;
    for( int i = 0; i < n.size(); i++ ) {
        if( n[i] == '0' ) continue;
        if( n[i] != '1' )
            sum += ctoi( n[i] ), qn++;
        else if( i+1 < n.size() && n[i+1] == '0' )
            sum += ctoi( n[i], n[i+1] ), qn++;
        else
            sum += ctoi( n[i] ), qn++;
    }
    cout.precision(2);
    cout << fixed << (double)sum/(double)qn << endl;

    return 0;
}
