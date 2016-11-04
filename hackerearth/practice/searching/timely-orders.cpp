// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/timely-orders/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int v[100005];
ll w[100005];

int main() {
    int q, t, X, T, k1, k2;
    
    cin >> q;
    w[0] = 0;
    for( int i = 0, j = 1; i < q; i++ ) {
        cin >> t >> X >> T;
    	if( t == 1 ) {
    		v[j] = T, w[j] = X;
    		w[j] += w[j-1];
    		j++;
    	} else {
    	    k1 = lower_bound( v+1, v+j, T-X ) - v;
            k1--;
            
            if( T > v[j-1] )
                k2 = j-1;
    		else
    		    k2 = lower_bound( v+1, v+j, T ) - v;
    		
    		if( k1 > k2 )
    		    cout << 0 << endl;
    		else
    		    cout << w[k2] - w[k1] << endl;
    	}
    }
    
    return 0;
}
