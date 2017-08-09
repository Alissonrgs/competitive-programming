#include <bits/stdc++.h>
#define NMAX 100
using namespace std;

int ut[NMAX+1], uq[NMAX+1][10], uqi[NMAX+1][10], q[NMAX+1], u[NMAX+1];
vector<int> v;

bool comp( int a, int b ) {
    if( q[a] == q[b] ) {
        if( ut[a] == ut[b] )
            return a < b;
        return ut[a] < ut[b];
    }
    return q[a] > q[b];
}

int main() {
    int t, id, id_q, t_q;
    char r;
    bool e = false;
    string in;
    
    cin >> t;
    cin.ignore();
    getline( cin, in );
    while( t-- ) {
        if( e ) putchar( '\n' );
        e = true;
    
        memset( ut, 0, sizeof ut );
        memset( uq, 0, sizeof uq );
        memset( uqi, 0, sizeof uqi );
        memset( q, 0, sizeof q );
        memset( u, 0, sizeof u );
        v.clear();
        
        while( getline( cin, in ) && !in.empty() ) {
            stringstream ss( in );
            ss >> id >> id_q >> t_q >> r;
            if( !u[id] )
                v.push_back( id ), u[id] = 1;
            
            if( r == 'C' ) {
                if( !uq[id][id_q] ) {
                    uq[id][id_q] = 1; 
                    q[id]++;
                    ut[id] += t_q + uqi[id][id_q];
                }
            } else if( r == 'I' )
                uqi[id][id_q] += 20;
        }
        sort( v.begin(), v.end(), comp );
        for( int i = 0; i < (int)v.size(); i++ )
            cout << v[i] << " " << q[ v[i] ] << " " << ut[ v[i] ] << endl;
    }

    return 0;
}
