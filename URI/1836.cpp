#include <bits/stdc++.h>
using namespace std;

int main () {
	int t, l;
	double bs, iv, ev, hp, at, df, sp;
	string pokemon;
	
	cin >> t;
	for( int i = 1; i <= t; i++ ) {
		cin >> pokemon >> l;

		cin >> bs >> iv >> ev;
		hp = (( iv + bs + sqrt(ev) / 8.0 + 50.0) * l ) / 50.0 + 10.0;
		
		cin >> bs >> iv >> ev;
		at = (( iv + bs + sqrt(ev) / 8.0) * l ) / 50.0 + 5.0;
		
		cin >> bs >> iv >> ev;
		df = (( iv + bs + sqrt(ev) / 8.0) * l ) / 50.0 + 5.0;
		
		cin >> bs >> iv >> ev;
		sp = (( iv + bs + sqrt(ev) / 8.0) * l ) / 50.0 + 5.0;

		cout.precision(0);
		cout << "Caso #" << i << ": " << pokemon <<" nivel " << fixed << l << endl;
		cout << "HP: " << trunc( hp ) << endl;
		cout << "AT: " << trunc( at ) << endl;
		cout << "DF: " << trunc( df ) << endl;
		cout << "SP: " << trunc( sp ) << endl;		
	}
	
	return 0;
}