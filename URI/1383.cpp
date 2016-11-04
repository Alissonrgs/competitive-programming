#include <iostream>
using namespace std;

int main() {
    int n, m[9][9], check_l, check_c[9], check_r[3], inst = 0;
    bool linha, coluna, regiao_3x3, tudo_5;

    cin >> n;
    while( n-- ) {
        linha = coluna = regiao_3x3 = true;
        tudo_5 = false;

        for( int i = 0; i < 9; i++ ) {
            check_l = 0;

            if( i == 0 )
                for( int j = 0; j < 9; j++ )
                    check_c[j] = 0;

            if( i == 0 || i == 3 || i == 6 )
                check_r[0] = check_r[1] = check_r[2] = 0;

            for( int j = 0; j < 9; j++ ) {
                cin >> m[i][j];
                if( j > 1 && m[i][j] == m[i][j-1] && m[i][j] == 5 )
                    tudo_5 = true;

                check_l += m[i][j];

                check_c[j] += m[i][j];

                if( 0 <= j && j <= 2 )
                    check_r[0] += m[i][j];
                if( 3 <= j && j <= 5 )
                    check_r[1] += m[i][j];
                if( 6 <= j && j <= 8 )
                    check_r[2] += m[i][j];
            }
            if( check_l != 45 )
                linha = false;

            if( i == 8 )
                for( int j = 0; j < 9; j++ )
                    if( check_c[j] != 45 )
                        coluna = false;

            if( i == 2 || i == 5 || i == 8 )
                if( check_r[0] != 45 || check_r[1] != 45 || check_r[2] != 45 )
                    regiao_3x3 = false;
        }

        cout << "Instancia " << ++inst << endl;
        if( linha && coluna && regiao_3x3 && !tudo_5 )
            cout << "SIM\n\n";
        else
            cout << "NAO\n\n";
    }

    return 0;
}

