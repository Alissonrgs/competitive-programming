#include <iostream>
#include <sstream>
using namespace std;

int ctoi( char c ) {
	return (int)c - 48;
}

int main() {
	unsigned int a, b;
	int vai1, qnt;

	while( cin >> a >> b && ( a || b ) ) {
		qnt = vai1 = 0;
		stringstream sa;
		stringstream sb;
		sa << a;
		sb << b;
		for( int i=sa.str().size()-1, j=sb.str().size()-1, k; i>=0 || j>=0; i--, j-- ) {
			if( i >= 0 && j >= 0 )
				k = ctoi( sa.str()[i] ) + ctoi( sb.str()[j] ) + vai1;
			else if( i >= 0 )
				k = ctoi( sa.str()[i] ) + vai1;
			else
				k = ctoi( sb.str()[j] ) + vai1;
			vai1 = 0;
			if( k > 9 )
				vai1 = 1, qnt++;
		}
		if( qnt )
			cout << qnt << " carry operation" << ( qnt == 1 ? "." : "s." ) << endl;
		else
			cout << "No carry operation." << endl;
	}

	return 0;
}