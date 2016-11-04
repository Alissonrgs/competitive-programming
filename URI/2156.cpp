#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, C, I, pastilhas;
	string mapa[105], inst;

	while( cin >> L >> C >> I && L ) {
		int pi, pj;
		char pak_man = 'R';
		pastilhas = 0;

		cin.ignore();
		for( int i = 0; i < L; i++ ) {
			getline( cin, mapa[i] );
			for( int j = 0; j < C; j++ )
				if( mapa[i][j] == '<' )
					pi = i, pj = j;
		}

		cin >> inst;
		for( int i = 0; i < I; i++ ) {
			if( inst[i] == 'W' ) {
				switch( pak_man ) {
					case 'U':
						if( pi-1 >= 0 && mapa[pi-1][pj] != '#' )
							pi--;
						break;
					case 'D':
						if( pi+1 < L && mapa[pi+1][pj] != '#' )
							pi++;
						break;
					case 'L':
						if( pj-1 >= 0 && mapa[pi][pj-1] != '#' )
							pj--;
						break;
					case 'R':
						if( pj+1 < C && mapa[pi][pj+1] != '#' )
							pj++;
						break;
				}
				if( mapa[pi][pj] == '*' ) {
					pastilhas++;
					mapa[pi][pj] = ' ';
				}
			} else
				pak_man = inst[i];
		}
		cout << pastilhas << endl;
	}

	return 0;
}