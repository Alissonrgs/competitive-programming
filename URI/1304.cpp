#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0, t0 = 0, v = 0;
	double d = 0.0;
	string s, tempo;

	cout.precision( 2 );
	while( getline( cin, s ) ) {
		t0 = t;
		t = 3600*( 10*(int)( s[0] - '0' ) + (int)( s[1] - '0' ) );
		t += 60*( 10*(int)( s[3] - '0' ) + (int)( s[4] - '0' ) );
		t += 10*(int)( s[6] - '0' ) + (int)( s[7] - '0' );
		tempo.clear();
		for( int i = 0; i < 8; i++ ) tempo += s[i];
		
		d += v*( t - t0 )/3600.0;
		if( s.size() == 8 )
			cout << tempo << " " << fixed << d << " km\n";
		
		else {
			v = 0;
			for( int i = s.size()-1, j = 0; i >= 9; i--, j++ )
				v += pow( 10, j )*(int)( s[i] - '0' );
		}
	}

	return 0;
}