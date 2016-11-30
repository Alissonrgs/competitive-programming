#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    list<char> s;
    list<char>::iterator it;
    
    while( cin >> text ) {
        s.clear();
        it = s.begin();
        for( int i = 0; i < (int)text.size(); i++ ) {
            if( text[i] == '[' )
                it = s.begin();
            else if( text[i] == ']' )
                it = s.end();
            else
                s.insert( it, text[i] );
        }
        for( it = s.begin(); it != s.end(); it++ )
            cout << *it;
        cout << endl;
    }

    return 0;
}
