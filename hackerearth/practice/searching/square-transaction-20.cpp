// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/square-transaction-20/
#include <bits/stdc++.h>
using namespace std;

int v[100005];

int binarySearch( int i, int f, int k ) {
	int m = ( i + f ) / 2;
	int ans = -1;
	while( i <= f ) {
		m = ( i + f ) / 2;
		if( v[m] < k ) {
			i = m+1;
		} else if( v[m] >= k ) {
			f = m-1;
			ans = m;
		}
	}
	return ans;
}

int main() {
	int t, q, x;
	
	cin >> t;
	v[0] = 0;
	for( int i = 1; i <= t; i++ )
		cin >> v[i], v[i] += v[i-1];
	cin >> q;
	for( int i = 0; i < q; i++ ) {
		cin >> x;
		if( x > v[t] )
			cout << -1 << endl;
		else
			cout << binarySearch( 1, t, x ) << endl;
	}
	
    return 0;
}
