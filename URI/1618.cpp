#include <bits/stdc++.h>
using namespace std;

struct ponto {
    int x, y;
} a, b, c, d, r;
  
int main() {
    int n;
     
    scanf( "%d", &n );
    while( n-- ) {
        scanf( "%d%d%d%d%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y, &r.x, &r.y );
         
        if( a.x <= r.x && r.x <= c.x && a.y <= r.y && r.y <= c.y )
            printf( "1\n" );
        else
            printf( "0\n" );
    }
    
    return 0;
}