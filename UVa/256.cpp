#include <bits/stdc++.h>
using namespace std;

set<string> s[4];

int main() {
    int d, pot = 10;

    /*for( int k = 1; k <= 4; k++ ) {
        for( int i = 0; i < pot; i++ )
            for( int j = 0; j < pot; j++ ) {
                string ni = to_string(i),
                       nj = to_string(j),
                       n;
                while( ni.size() < k ) ni = "0" + ni;
                while( nj.size() < k ) nj = "0" + nj;
                n = ni + nj;
                if( n.size() == 2*k && (i+j)*(i+j) == stoi( n, NULL, 10 ) )
                    s[k-1].insert( n ), cout << (i+j)*(i+j) << " == " << n << endl;
            }
        pot *= 10;
    }*/
    s[0].insert("00");
    s[0].insert("01");
    s[0].insert("81");
    s[1].insert("0000");
    s[1].insert("0001");
    s[1].insert("2025");
    s[1].insert("3025");
    s[1].insert("9801");
    s[2].insert("000000");
    s[2].insert("000001");
    s[2].insert("088209");
    s[2].insert("494209");
    s[2].insert("998001");
    s[3].insert("00000000");
    s[3].insert("00000001");
    s[3].insert("04941729");
    s[3].insert("07441984");
    s[3].insert("24502500");
    s[3].insert("25502500");
    s[3].insert("52881984");
    s[3].insert("60481729");
    s[3].insert("99980001");
    
    while( cin >> d ) {
        d = d/2 - 1;
        for( string str : s[d] )
            cout << str << endl;
    }
    
    return 0;
}
