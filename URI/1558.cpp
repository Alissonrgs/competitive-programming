#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    bool q[10005], eh;
    for( int i=0; i<=10000; i++ ) q[i] = false;
    for( int i=0; i*i<=10000; i++ ) q[i*i] = true;

    while( scanf( "%d", &N ) != EOF ) {
        eh = false;

        for( int i=0; i*i<=N; i++ )
            if( q[ N - i*i ] ) {
                eh = true;
                break;
            }
 
        printf( "%s\n", eh ? "YES" : "NO" );
    }

	return 0;
}