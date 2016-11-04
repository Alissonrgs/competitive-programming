#include <cstdio>
#include <algorithm>
#include <string> 
using namespace std;

int main() {
	int n, uns;
	string numb;

	while( scanf( "%d", &n ) && n ) {
		uns = 0;
		numb = "";
		while( n ) {
			if( n&1 ) {
				uns++;
				numb += "1";
			} else
				numb += "0";
			n = n >> 1;
		}
		reverse( numb.begin(), numb.end() );
		printf("The parity of %s is %d (mod 2).\n", numb.c_str(), uns );
	}

	return 0;
}