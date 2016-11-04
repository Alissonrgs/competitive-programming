#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l, a[100005], ntrocas;

	while( cin >> n >> l && ( n && l ) ) {
		ntrocas = n;
		for( int i=0; i<l; i++ )
			cin >> a[i];

		for( int i=0, p; i<l; i++ ) {
			p = upper_bound( a, a+l, a[i]+n-1 ) - a;
			if( ntrocas > n-( p-i ) )
				ntrocas = n-( p-i );
		}
		cout << ntrocas << endl;
	}

	return 0;
}