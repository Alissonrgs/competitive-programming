#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int N, D, jantar, aluno[105], mj;

	while( scanf( "%d%d", &N, &D ) && N ) {
		memset( aluno, 0, sizeof aluno );
		mj = 0;
		for( int j=0; j<D; j++ )
			for( int i=0; i<N; i++ ) {
				scanf( "%d", &jantar );
				aluno[i] += jantar;
				mj = max( mj, aluno[i] );
			}
		printf( "%s\n", ( mj == D ? "yes" : "no" ) );
	}

	return 0;
}