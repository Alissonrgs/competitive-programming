#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool ord( int a, int b ) {
	return a > b;
}

int main() {
	int n, v;
	vector<int> par, impar;

	scanf( "%d", &n );
	for( int i=0; i<n; i++ ) {
		scanf( "%d", &v );
		if( v&1 ) impar.push_back( v );
		else par.push_back( v );
	}
	sort( par.begin(), par.end() );
	sort( impar.begin(), impar.end(), ord );
	for( int i=0; i<par.size(); i++ )
		printf( "%d\n", par[i] );
	for( int i=0; i<impar.size(); i++ )
		printf( "%d\n", impar[i] );
	

	return 0;
}