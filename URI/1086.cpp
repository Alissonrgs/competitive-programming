#include <bits/stdc++.h>
using namespace std;

bool ord( int a, int b ) {
    return a > b;
}

int main() {
	int n, m, l, k, x[100005], qt, qtl, t;

	while( scanf( "%d%d", &n, &m ) && n ) {
	    scanf( "%d%d", &l, &k );
		for( int i = 0; i < k; i++ ) {
			scanf( "%d", &x[i] );
	        x[i] *= 100;
	    }
		n *= 100;
	    m *= 100;
	    t = k+1;
		sort( &x[0], &x[k], ord );

		if( n%l != 0 && m%l != 0 ) {
		    printf( "impossivel\n" );
		    continue;
		}
		
		qt = 0;
		qtl = 0;
		if( n%l == 0 ) {
		    for( int i = 0, j = k-1; qtl < n/l && i < k && j >= 0; i++ ) {
		        if( x[i] <= m ) {
		            if( x[i] == m ) {
		                qt++, qtl++;
		                continue;
		            }
		            while( i < j && j >= 0 && x[i] + x[j] < m )
		                j--;
		            if( i >= j )
		                break;
		            if( x[i] + x[j] == m )
		                qt += 2, qtl++, j--;
		        }
		    }
		}
		if( qtl == n/l )
		    t = min( t, qt );
		
		qt = 0;
	    qtl = 0;
		if( m%l == 0 ) {
		    for( int i = 0, j = k-1; qtl < m/l && i < k && j >= 0; i++ ) {
		        if( x[i] <= n ) {
		            if( x[i] == n ) {
		                qt++, qtl++;
		                continue;
		            }
		            while( i < j && j >= 0 && x[i] + x[j] < n )
		                j--;
		            if( i >= j )
		                break;
		            if( x[i] + x[j] == n )
		                qt += 2, qtl++, j--;
		        }
		    }
		}
		if( qtl == m/l )
		    t = min( t, qt );
		
		if( t == k+1 ) {
		    printf( "impossivel\n" );
		    continue;
		}
	    printf( "%d\n", t );
	}

	return 0;
}
