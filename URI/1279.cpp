#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ll n3, n5, n11, n400;
	string ano;
	bool barraN = false, a, div3, div4, div5, div11, div15, div55, div100, div400;

	while( cin >> ano ) {
		printf( "%s", barraN ? "\n" : "" ), barraN = true;
		div3 = div4 = div5 = div11 = div15 = div55 = div100 = div400 = false;
		n3 = n11 = n400 = 0;

		a = true;
		for( int i=0; i<ano.size(); i++ ) {
			n3 += (int)( ano[i] - '0' );
			n11 += a ? (int)( ano[i] - '0' ) : -(int)( ano[i] - '0' );
			a = !a;
		}
		if( n3%3 == 0 ) div3 = true;
		if( n11%11 == 0 ) div11 = true;

		n5 = (int)( ano[ ano.size()-1 ] - '0' );
		if( n5 == 0 || n5 == 5 ) div5 = true;
		if( div3 && div5 ) div15 = true;
		if( div5 && div11 ) div55 = true;

		n400 = (int)( 10*( ano[ ano.size()-2 ] - '0' ) + ano[ ano.size()-1 ] - '0' );
		if( n400%4 == 0 ) div4 = true;
		if( n400 == 0 ) {
			div100 = true;
			n400 = (int)( 10*( ano[ ano.size()-4 ] - '0' ) + ano[ ano.size()-3 ] - '0' );
			if( n400%4 == 0 )
				div400 = true;
		}

		if( ( div4 && !div100 ) || div400 ) {
			printf( "This is leap year.\n" );
			if( div15 ) printf( "This is huluculu festival year.\n" );
			if( div55 ) printf( "This is bulukulu festival year.\n" );
		
		} else if( div15 )
			printf( "This is huluculu festival year.\n" );

		else
			printf( "This is an ordinary year.\n" );
	}

	return 0;
}