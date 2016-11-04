#include <bits/stdc++.h>
using namespace std;

#define ll long long

int coin[] = { 0, 1, 5, 10, 25, 50 };
ll dp[30005][10];

ll count_ways( int value, int id ) {
    if( coin[id] == 0 ) return 0;
    if( dp[value][id] ) return dp[value][id];
    
    if( value - coin[id] >= 0 )
        dp[value][id] += count_ways( value - coin[id], id );
    dp[value][id] += count_ways( value, id-1 );
    
    return dp[value][id];
}

int main() {
    int n;
    ll ways;
    memset( dp, 0, sizeof dp );
    for( int i = 1; i <= 5; i++ )
        dp[0][i] = 1LL;
    
    while( scanf( "%d", &n ) != EOF ) {
        ways = count_ways( n, 5 );
        if( ways == 1 )
            printf( "There is only 1 way to produce %d cents change.\n", n );
        else
            printf( "There are %lld ways to produce %d cents change.\n", ways, n );
    }

    return 0;
}
