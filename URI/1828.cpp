#include <bits/stdc++.h>
using namespace std;

map<string,int> mapa;
vector<int> jogo[5];

int main() {
	int n, pptls, t = 1;
	string sheldon, raj;

	mapa["tesoura"] = 0;
	mapa["papel"] = 1;
	mapa["pedra"] = 2;
	mapa["lagarto"] = 3;
	mapa["Spock"] = 4;

	jogo[0].push_back( 1 );
	jogo[0].push_back( 3 );
	jogo[1].push_back( 2 );
	jogo[1].push_back( 4 );
	jogo[2].push_back( 3 );
	jogo[2].push_back( 0 );
	jogo[3].push_back( 4 );
	jogo[3].push_back( 1 );
	jogo[4].push_back( 0 );
	jogo[4].push_back( 2 );

	cin >> n;
	for( int t=1; t<=n; t++ ) {
		pptls = -1;
		cin >> sheldon >> raj;
		for( int i=0; i<jogo[ mapa[sheldon] ].size() && pptls == -1; i++ )
			if( jogo[ mapa[sheldon] ][i] == mapa[raj] )
				pptls = 0;
		for( int i=0; i<jogo[ mapa[raj] ].size() && pptls == -1; i++ )
			if( jogo[ mapa[raj] ][i] == mapa[sheldon] )
				pptls = 1;

		printf( "Caso #%d: ", t );
		if( pptls == -1 )
			printf( "De novo!\n" );
		else if( pptls == 0 )
			printf( "Bazinga!\n" );
		else
			printf( "Raj trapaceou!\n" );
	}

	return 0;
}