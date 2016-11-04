#include <bits/stdc++.h>
using namespace std;

int main() {   
    string str;
    char c, letra = '0';
    bool tautograma = true;
    
    while( cin >> str && str[0] != '*' ) {
        c = getchar();
        str[0] = tolower( str[0] );
        
        if( letra == '0' )
            letra = str[0];
            
        if( str[0] != letra )
            tautograma = false;
        
        if( c == '\n' ) {
            cout << ( tautograma ? "Y" : "N" ) << endl;
            letra = '0';
            tautograma = true;
        }
    }    
}
