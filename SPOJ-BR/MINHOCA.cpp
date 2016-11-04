#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m, soma, maior;
	
	cin >> n >> m;
	int matriz[n][m];

	for( int i=0; i<n; i++ ) {
		soma = 0;
		for( int j=0; j<m; j++ ) {
			cin >> matriz[i][j];
			soma += matriz[i][j];	
		}
		if( i == 0 ) maior = soma;
		if( maior < soma ) maior = soma;
	}
	for( int i=0; i<m; i++ ) {
		soma = 0;
		for( int j=0; j<n; j++ )
			soma += matriz[j][i];
		if( maior < soma ) maior = soma;	
	}
	cout << maior << endl;
	
	return 0;
}