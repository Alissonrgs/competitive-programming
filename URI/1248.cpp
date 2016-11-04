#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool cheater;
	size_t j;
	string dieta, cafe, almoco;

	cin >> n;
	cin.ignore();
	while( n-- ) {
		cheater = false;
		getline( cin, dieta );
		getline( cin, cafe );
		getline( cin, almoco );
		for( int i=0; i<cafe.size() && !cheater; i++ ) {
			j = dieta.find( cafe[i] );
		 	if( j != string::npos )
		 		dieta.erase( dieta.begin()+j );
		 	else
		 		cheater = true;
		}
		for( int i=0; i<almoco.size() && !cheater; i++ ) {
			j = dieta.find( almoco[i] );
		 	if( j != string::npos )
		 		dieta.erase( dieta.begin()+j );
		 	else
		 		cheater = true;
		}
		if( cheater )
			cout << "CHEATER\n";
		else {
			sort( dieta.begin(), dieta.end() );
			cout << dieta << endl;
		}
	}

	return 0;
}