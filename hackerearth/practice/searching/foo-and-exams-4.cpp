// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/foo-and-exams-4/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, d, k;

ll Foo_funtion(ll m) {
	double t = m;
	double ans = a*t*t*t + b*t*t + c*t + d;
	if( ans > 1e18 )
		return k + 1;
	else
		return ans;
}

ll binarySearch( ll i, ll f ) {
	ll m = ( i + f ) / 2;
	ll ans = 0;
	while( i <= f ) {
		m = ( i + f ) / 2;
		if( Foo_funtion(m) > k )
			f = m-1;
		else if( Foo_funtion(m) <= k ) {
			i = m+1;
			ans = m;
		}
	}
	return ans;
}

int main() {
	int n;
	
	cin >> n;
	for( int i = 0; i < n; i++ ) {
		cin >> a >> b >> c >> d >> k;
		cout << binarySearch( 1, 1000000 ) << endl;
	}
	
    return 0;
}
