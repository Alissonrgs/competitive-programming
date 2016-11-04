#include <bits/stdc++.h>
using namespace std;

#define LIM 2001
#define vi vector<int>
#define ull unsigned long long

bitset<LIM+10> bs;
vi prime;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    prime.push_back(2);

    for( ull j = 2*2; j <= LIM; j += 2 )
        bs[j] = false;

    for( ull i = 3; i <= LIM; i += 2 )
        if( bs[i] ) {
            for( ull j = i*i; j <= LIM; j += i )
                bs[j] = false;
            
            prime.push_back( (int)i );
        }
}

bool isPrime( ull N ) {
    if( N <= LIM ) return bs[N];
    for( int i = 0; i < (int)prime.size(); i++ )
        if( N % prime[i] == 0 )
            return false;
    
    return true;
}

int main() {
    sieve();

    int t;
    string str;
    map<char,int> mapa;
    map<char,int>::iterator it;
    bool existe;

    cin >> t;
    for( int Case = 1; Case <= t; Case++ ) {
        mapa.clear();
        existe = false;

        cin >> str;
        for( int i = 0; i < (int)str.size(); i++ ) {
            if( !mapa[ str[i] ] )
                mapa[ str[i] ] = 1;
            else
                mapa[ str[i] ]++;
        }
        cout << "Case " << Case << ": ";
        for( it = mapa.begin(); it != mapa.end(); it++ )
            if( isPrime( it->second ) )
                cout << it->first, existe = true;

        cout << ( existe ? "" : "empty" ) << endl;
    }
    
    return 0;
}