#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

int primo( int n ) {
    if( n == 0 ) return false;
    if( n != 2 )
        for( int i=2; i<=sqrt( n ); i++ )
            if( n%i == 0 ) return false;
    return true;
}

int main() {
    int soma;
    string palavra;

    while( cin >> palavra ) {
        soma = 0;
        for( int i=0; i<palavra.size(); i++ )
            if( isupper( palavra[i] ) )
                soma += palavra[i]-int('A')+27;
            else
                soma += palavra[i]-int('a')+1;

        cout << ( ( primo( soma ) )? "It is a prime word.": "It is not a prime word." ) << endl;
    }

    return 0;
}
