#include <iostream>
using namespace std;

int main() {
	string num;

	while( cin >> num ) {
		for( int i=0; i<num.size(); i++ ) {
			if( 'A' <= num[i] && num[i] <= 'C' ) num[i] = '2';
			else if( 'D' <= num[i] && num[i] <= 'F' ) num[i] = '3';
			else if( 'G' <= num[i] && num[i] <= 'I' ) num[i] = '4';
			else if( 'J' <= num[i] && num[i] <= 'L' ) num[i] = '5';
			else if( 'M' <= num[i] && num[i] <= 'O' ) num[i] = '6';
			else if( 'P' <= num[i] && num[i] <= 'S' ) num[i] = '7';
			else if( 'T' <= num[i] && num[i] <= 'V' ) num[i] = '8';
			else if( 'W' <= num[i] && num[i] <= 'Z' ) num[i] = '9';
		}
		cout << num << endl;
	}

	return 0;
}