#include <bits/stdc++.h>
using namespace std;
 
struct point {
    int x, y;
    point() { x = y = 0; }
    point( int _x, int _y ) : x(_x), y(_y) {}
} c, p;
 
int insideCircle( point p, point c, int r ) {
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
}
 
int main() {
    int n, r1, r2, dC, dP, bC, bP;
    bool cp;
     
    while( scanf( "%d", &n ) && n ) {
        cp = true;
        dC = dP = bC = bP = 0;
        scanf( "%d%d%d%d", &c.x, &c.y, &r1, &r2 );
        for( int i=0; i<(n<<1); i++ ) {
            scanf( "%d%d", &p.x, &p.y );
            if( insideCircle( p, c, r1 ) == 0 )
                cp ? dC++ : dP++;
            else if( insideCircle( p, c, r2 ) < 2 )
                cp ? bC++ : bP++;
                 
            cp = !cp;
        }
        if( dC == dP ) {
            if( bC == bP ) printf( "C = P\n" );
            else if( bC > bP ) printf( "C > P\n" );
            else printf( "P > C\n" );
             
        } else if( dC > dP ) printf( "C > P\n" );
        else printf( "P > C\n" );
    }
 
    return 0;
}