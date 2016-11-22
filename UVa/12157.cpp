#include <bits/stdc++.h>
using namespace std;

int mile( int time ) {
    int ans = (time+1)/30;
    if( (time+1)%30 != 0 )
        ans++;
    return 10*ans;
}

int juice( int time ) {
    int ans = (time+1)/60;
    if( (time+1)%60 != 0 )
        ans++;
    return 15*ans;
}

int main() {
    int t, n, time, m, j;
    
    scanf( "%d", &t );
    for( int _case = 1; _case <= t; _case++ ) {
        m = j = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            scanf( "%d", &time );
            m += mile( time );
            j += juice( time );
        }
        printf( "Case %d: ", _case );
        if( m == j )
            printf( "Mile Juice %d\n", m );
        else if( m < j )
            printf( "Mile %d\n", m );
        else
            printf( "Juice %d\n", j );
    }

    return 0;
}
