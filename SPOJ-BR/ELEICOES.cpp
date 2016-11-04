#include <cstdio>
#include <map>

std::map<int,int> candidato;

int main() {
	int n, id, qvm = 0, e;

	scanf( "%d", &n );
	while( n-- ) {
		scanf( "%d", &id );
		if( !candidato[id] ) candidato[id] = 1;
		else candidato[id]++;
		
		if( qvm < candidato[id] ) {
			qvm = candidato[id];
			e = id;
		}
	}
	printf("%d\n", e );

	return 0;
}