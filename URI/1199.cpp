#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
	int n;
	string num;

	while( cin >> num && num[0] != '-' ) {
		if( num[0] == '0' ) {
			n = stoi( num, NULL, 16 );
			cout << dec << n << endl;
		} else {
			n = stoi( num, NULL, 10 );
			stringstream str;
			str << hex << n;
			cout << "0x";
			for( int i=0; i<str.str().size(); i++ )
				if( isalpha( str.str()[i] ) )
					cout << (char)toupper( str.str()[i] );
				else
					cout << str.str()[i];
			cout << endl;
		}
	}

	return 0;
}