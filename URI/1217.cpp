#include <iostream>
using namespace std;

int main() {
	int n, kg, qkg = 0;
	double valor, total = 0;
	string fruta;

	cin >> n;
	for( int day=1; day<=n; day++ ) {
		cin >> valor;
		total += valor;
		
		kg = 1;
		cin.ignore();
		getline( cin, fruta );
		for( int i=0; i<fruta.size(); i++ )
			if( fruta[i] == ' ' )
				kg++;
		
		cout << "day " << day << ": " << kg << " kg\n";
		qkg += kg;
	}
	cout.precision(2);
	cout << fixed << (double)qkg/n << " kg by day\n"
		 << "R$ " << total/n << " by day\n";

	return 0;
}