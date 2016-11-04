#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fat( ll n ) {
	ll f = 1;
	for( ll i = 2; i <= n; i++ )
		f *= i;
	return f;
}

int main() {
	string s;

	while( cin >> s && s[0] != '0' )
		printf( "%lld\n", fat( s.size() ) );

	return 0;
}
