#include <bits/stdc++.h>
using namespace std;

#define ll long long

int vetor[1000005];

void gerar_array( int n, ll s ) {
	vetor[0] = s;
	for( int i = 1; i < n; i++ )
	    vetor[i] = (1LL*vetor[i-1]*1103515245 + 12345) % (2147483648LL);
}

ll soma_intervalo( int n, int k ) {
	ll soma = 0;
	int maior, i = 0, j = k-1;
	
	maior = vetor[i];
	for( int id = i+1; id <= j; id++ )
		maior = max( maior, vetor[id] );
	i++, j++;
	soma += maior;

	while( j < n ) {
		if( maior == vetor[i-1] ) {
			maior = vetor[i];
			for( int id = i+1; id <= j; id++ )
				maior = max( maior, vetor[id] );

		} else
			maior = max( maior, vetor[j] );

		soma += maior;
		i++, j++;
	}
	return soma;
}

int main() {
	int t, n, k;
	ll s;
	
	cin >> t;
	while( t-- ) {
		cin >> n >> k >> s;
		gerar_array( n, s );
		cout << soma_intervalo( n, k ) << endl;
	}

	return 0;
}
