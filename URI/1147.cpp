#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 }, dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };

bool valid( int x, int y ) {
    return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

int main() {
    int X, Y, t[10][10], _case = 1, mov;
    string p;

    while( cin >> p && p != "0" ) {
        memset( t, 0, sizeof t );
        
        X = p[0]-'0';
        Y = p[1]-'a'+1;
        
        for( int i = 1; i <= 8; i++ ) {
            cin >> p;
            t[ p[0]-'0' ][ p[1]-'a'+1 ] = 1;
        }
        
        mov = 0;
        for( int i = 0, x, y; i < 8; i++ ) {
            x = X + dx[i], y = Y + dy[i];
            
            if( valid( x, y ) )
                if( x + 1 <= 8 ) {
                    bool l = false, r = false;
                    if( y-1 >= 1 && t[x+1][y-1] )
                        l = true;
                    if( y+1 <= 8 && t[x+1][y+1] )
                        r = true;
                    if( !l && !r )
                        mov++;
                } else
                    mov++;
        }
        
        cout << "Caso de Teste #" << _case++ << ": " << mov << " movimento(s)." << endl;
    }

    return 0;
}
