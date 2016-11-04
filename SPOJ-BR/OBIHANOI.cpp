#include <iostream>
#include <cmath>
using namespace std;

#define lli long long int

int main() {
	int n, t=1;
	
	while( cin >> n && n )
		cout << "Teste " << t++ << endl
			 << ( lli )pow( 2, n )-1 << endl << endl;
	
	return 0;
} 