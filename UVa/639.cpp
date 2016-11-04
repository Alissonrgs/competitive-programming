#include <iostream>
using namespace std;

bool livre( string *m, int n, int x, int y ) {
	bool l = true;

	for( int i=x-1; i>=0; i-- ) {
		if( m[i][y] == 'B' ) { l = false; break; }
		if( m[i][y] == 'X' ) break;
	}
	if( l ) {
		for( int i=x+1; i<n; i++ ) {
			if( m[i][y] == 'B' ) { l = false; break; }
			if( m[i][y] == 'X' ) break;
		}
		if( l ) {
			for( int j=y-1; j>=0; j-- ) {
				if( m[x][j] == 'B' ) { l = false; break; }
				if( m[x][j] == 'X' ) break;
			}
			if( l ) {
				for( int j=y+1; j<n; j++ ) {
					if( m[x][j] == 'B' ) { l = false; break; }
					if( m[x][j] == 'X' ) break;
				}
			}
		}
	}

	return l;
}

int inserir_T( string *m, int n, int x, int y ) {
	int qm = 0, qnt;
	m[x][y] = 'B';

	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			if( m[i][j] != 'B' && m[i][j] != 'X' && livre( m, n, i, j ) ) {
				string m_aux[4];
				m_aux[0] = m[0];
				m_aux[1] = m[1];
				m_aux[2] = m[2];
				m_aux[3] = m[3];
				qnt = 1 + inserir_T( m_aux, n, i, j );
				if( qm < qnt ) qm = qnt;
			}
	
	return qm;
}

int main() {
	int n, qm, qnt;
	string m[4];

	while( cin >> n && n ) {
		qm = 0;
		for( int i=0; i<n; i++ )
			cin >> m[i];

		for( int i=0; i<n; i++ )
			for( int j=0; j<n; j++ )
				if( m[i][j] != 'X' ) {
					string m_aux[4];
					m_aux[0] = m[0];
					m_aux[1] = m[1];
					m_aux[2] = m[2];
					m_aux[3] = m[3];
					qnt = 1 + inserir_T( m_aux, n, i, j );
					if( qm < qnt ) qm = qnt;
				}

		cout << qm << endl;
	}
	
	return 0;
}