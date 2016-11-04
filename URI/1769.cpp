#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int num[11], j, soma, b1, b2;
    char c;
    bool cpf;

    while( scanf( " %c", &c ) != EOF ) {
        j = 0;
        cpf = true;
        num[j++] = c - '0';
        for( int i=1; i<14; i++ ) {
            scanf( " %c", &c );
            if( isdigit( c ) )
                num[j++] = c - '0';
        }
         
        soma = 0;
        for( int i=0, k=1; i<9; i++, k++ )
            soma += k*num[i];
        b1 = soma%11 == 10 ? 0 : soma%11;
        if( b1 != num[9] )
            cpf = false;

        soma = 0;
        for( int i=0, k=9; i<9; i++, k-- )
            soma += k*num[i];
        b2 = soma%11 == 10 ? 0 : soma%11;
        if( b2 != num[10] )
            cpf = false;

        printf( "%s\n", ( cpf ? "CPF valido" : "CPF invalido" ) );
    }
 
    return 0;
}