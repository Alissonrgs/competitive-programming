#include <bits/stdc++.h>
using namespace std;

int main() {
	string number;

	while( cin >> number ) {
		for( int i = 0; i < number.size(); i++ ) {
			if( 'A' <= number[i] && number[i] <= 'C' )
				number[i] = '2';
			else if( 'D' <= number[i] && number[i] <= 'F' )
				number[i] = '3';
			else if( 'G' <= number[i] && number[i] <= 'I' )
				number[i] = '4';
			else if( 'J' <= number[i] && number[i] <= 'L' )
				number[i] = '5';
			else if( 'M' <= number[i] && number[i] <= 'O' )
				number[i] = '6';
			else if( 'P' <= number[i] && number[i] <= 'S' )
				number[i] = '7';
			else if( 'T' <= number[i] && number[i] <= 'V' )
				number[i] = '8';
			else if( 'W' <= number[i] && number[i] <= 'Z' )
				number[i] = '9';
		}
		cout << number << endl;
	}

	return 0;
}