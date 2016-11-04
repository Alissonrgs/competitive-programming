#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, t=1, num[10], senha[6][10];
	char c;

	while( cin >> n && n ) {
		memset( senha, 0, sizeof senha );
		for( int j=0; j<n; j++ ) {
			for( int i=0; i<10; i++ )
				cin >> num[i];
			for( int i=0; i<6; i++ ) {
				cin >> c;
				if( c == 'A' ) {
					senha[i][num[0]]++;
					senha[i][num[1]]++;
				}
				if( c == 'B' ) {
					senha[i][num[2]]++;
					senha[i][num[3]]++;
				}
				if( c == 'C' ) {
					senha[i][num[4]]++;
					senha[i][num[5]]++;
				}
				if( c == 'D' ) {
					senha[i][num[6]]++;
					senha[i][num[7]]++;
				}
				if( c == 'E' ) {
					senha[i][num[8]]++;
					senha[i][num[9]]++;
				}
			}
		}
		cout << "Teste " << t++ << endl;
		for( int i=0; i<6; i++ )
			for( int j=0; j<10; j++ )
				if( senha[i][j] == n ) {
					if( i != 0 ) cout << " ";
					cout << j;
					break;
				}
		cout << endl << endl;
	}

	return 0;
}
