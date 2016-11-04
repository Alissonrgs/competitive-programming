#include <bits/stdc++.h>
using namespace std;

int posfixo( char pai, string preEsq, string preDir, string inEsq, string inDir ) {
	int p;

	p = -1;
	for( int i=0; i<inEsq.size(); i++ )
		if( inEsq[i] == preEsq[0] ) {
			p = i;
			break;
		}
	if( p != -1 )
		posfixo( preEsq[0], preEsq.substr( 1, p ), preEsq.substr( p+1, preEsq.size()-p ),
				            inEsq.substr( 0, p ), inEsq.substr( p+1, inEsq.size()-p ) );
	
	p = -1;
	for( int i=0; i<inDir.size(); i++ )
		if( inDir[i] == preDir[0] ) {
			p = i;
			break;
		}
	if( p != -1 )
		posfixo( preDir[0], preDir.substr( 1, p ), preDir.substr( p+1, preDir.size()-p ),
				        	inDir.substr( 0, p ), inDir.substr( p+1, inDir.size()-p ) );

	cout << pai;
}

int main() {
	int pai;
	string prefixo, infixo;

	while( cin >> prefixo >> infixo ) {
		for( int i=0; i<infixo.size(); i++ )
			if( infixo[i] == prefixo[0] ) {
				pai = i;
				break;
			}
		posfixo( prefixo[0], prefixo.substr( 1, pai ), prefixo.substr( pai+1, prefixo.size()-pai ),
				             infixo.substr( 0, pai ), infixo.substr( pai+1, infixo.size()-pai ) );
		
		cout << endl;
	}

	return 0;
}