#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n;
	set<string> s;
	string mDNA;

	while( cin >> n && n ) {
		s.clear();
		while( n-- ) {
			cin >> mDNA;
			sort( mDNA.begin(), mDNA.end() );
			s.insert( mDNA );
		}
		cout << s.size() << endl;
	}
	
	return 0;
}