#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll Threebonacci( ll n ) {
	ll prev = 1, fib = 1, threebonacci = 0;
	while( threebonacci < n ) {
		ll aux = prev;
		prev = fib;
		fib = aux + prev;
		aux = fib;
		
		bool tree = false;
		ll sum = 0;
		while( aux ) {
			int num = aux%10;
			if( num == 3 ) tree = true;
			sum += num;
			aux /= 10;
		}
		if( tree || sum%3 == 0 ) threebonacci++;
	}
	return fib;
}

int main() {
	int n;
	
	while( scanf( "%d", &n ) != EOF )
		printf( "%lld\n", Threebonacci(n) );
		
	return 0;
}
