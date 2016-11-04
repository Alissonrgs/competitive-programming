#include <iostream>
#include <cmath>
using namespace std;
 
bool primo( int n ) {
	if( n == 1 || n == 0 ) return false;	
	if( n != 2 )
		for( int i=2; i<=sqrt(n); i++ )
			if( n%i == 0 )
				return false;
	return true;
}
 
int main() {
	int n;

	cin >> n;
	cout << ( ( primo(n) )? "sim": "nao" ) << endl;

	return 0; 
}