#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k, sk, suvo, suvojit;
    char str[155], sjit[7] = {'S', 'U', 'V', 'O', 'J', 'I', 'T'};
    
    scanf( "%d", &n );
    for( i = 0; i < n; i++ ) {
    	scanf( "%s", str );
    	suvo = suvojit = 0;
    	for( j = 0; j < strlen( str ); j++ ) {
    		for( k = j, sk = 0; k < strlen( str ) && sk < 7; k++, sk++ ) {
    			if( str[k] != sjit[sk] )
    				break;
    		}
    		if( sk == 7 )
    			suvojit++;
    		else if( sk >= 4 )
    			suvo++;
    	}
    	printf( "SUVO = %d, SUVOJIT = %d\n", suvo, suvojit );
    }
    
    return 0;
}

