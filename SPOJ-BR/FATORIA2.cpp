#include <iostream>
using namespace std;

int fat( int n ) {
	int fat = 1;
	
	for( int i=2; i<=n; i++ )
		fat *= i;
	return fat;
}

int main() {
	int n;

	cin >> n;
	cout << fat( n ) << endl;

	return 0; 
}