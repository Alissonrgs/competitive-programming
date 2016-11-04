#include <bits/stdc++.h>
using namespace std;

int main() {
	int count;
	string vogal, texto;

	while( getline( cin, vogal ) ) {
		if( !getline( cin, texto ) )
			break;

		count = 0;
		for( int i = 0; i < texto.size(); i++ )
			for( int j = 0; j < vogal.size(); j++ )
				if( texto[i] == vogal[j] )
					count++;

		cout << count << endl;
	}

	return 0;
}