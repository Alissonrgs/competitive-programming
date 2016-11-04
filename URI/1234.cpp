#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	
	bool f = false;
	while( ( c = getchar() ) != EOF  ) {
		switch( c ) {
			case 'b':
			case 's':
			case 'z':
			case 'v':
			case 'x':
			case 'p':
			case 'j':
			case 'f':
				if( !f ) putchar( 'f' ), f = true;
				break;
			case 'B':
			case 'S':
			case 'Z':
			case 'V':
			case 'X':
			case 'P':
			case 'J':
			case 'F':
				if( !f ) putchar( 'F' ), f = true;
				break;
			default:
				putchar( c );
				f = false;
		}
	}

	return 0;
}