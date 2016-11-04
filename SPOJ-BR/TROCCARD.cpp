#include <iostream>
#include <set>
using namespace std; 

int main() {
	int a, b, qca, qcb, d;
	set<int> ca, cb, aux;
	set<int>::iterator it;

	while( cin >> a >> b && a && b ) {
		ca.clear();
		cb.clear();
		aux.clear();
		for( int i=0, v; i<a; i++ ) {
			cin >> v;
			ca.insert( v );
		}
		aux.insert( ca.begin(), ca.end() );
		for( int i=0, v; i<b; i++ ) {
			cin >> v;
			cb.insert( v );
		}
		aux.insert( cb.begin(), cb.end() );

		qca = aux.size() - ca.size();
		qcb = aux.size() - cb.size();
		d = ( qca > qcb )? qca-qcb: qcb-qca;
		cout << ( ( qca > qcb )? qca-d: qcb-d ) << endl;
	}

	return 0;
}