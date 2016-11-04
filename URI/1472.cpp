#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, p[100005], qnt, d;

	while( cin >> n ) {
		qnt = 0;
		for( int i=0, dp; i<n; i++ ) {
			cin >> p[i];
			if( i != 0 ) p[i] += p[i-1];
		}
		d = p[n-1]/3;
		for( int i=0, dp; i<n; i++ ) {
			dp = lower_bound( p, p+n, p[i]+d ) - p;
			if( p[i]+d == p[dp] ) {
				dp = lower_bound( p, p+n, p[i]+2*d ) - p;
				if( p[i]+2*d == p[dp] )
					qnt++;
			}
		}
		cout << qnt << endl;
	}

	return 0;
}