#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i = 0, casa = 1;
	string romano[7] = { "I", "V", "X", "L", "C", "D", "M" }, R = "";
	
	cin >> n;
	while( n ) {
		switch( n%10 ) {
			case 1: R = romano[casa-1] + R;
					break;
			case 2: R = romano[casa-1] + romano[casa-1] + R;
					break;
			case 3: R = romano[casa-1] + romano[casa-1] + romano[casa-1] + R;
					break;
			case 4: R = romano[casa-1] + romano[casa] + R;
					break;
			case 5: R = romano[casa] + R;
					break;
			case 6: R = romano[casa] + romano[casa-1] + R;
					break;
			case 7: R = romano[casa] + romano[casa-1] + romano[casa-1] + R;
					break;
			case 8: R = romano[casa] + romano[casa-1] + romano[casa-1] + romano[casa-1] + R;
					break;
			case 9: R = romano[casa-1] + romano[casa+1] + R;
					break;
		}
		casa += 2;
		n /= 10;
	}
	cout << R << endl;

	return 0;
}
