#include <iostream>
using namespace std;

int main() {
    char N;
    string D;

    while( cin >> N >> D && ( N != '0' && D != "0" ) ) {
        string num = "";

        for( string::iterator it=D.begin(); it!=D.end(); it++ ) {
            if( *it == N )
                continue;
            num += *it;
            if( num[0] == '0' )
                num = "";
        }
        if( num == "" ) num = "0";
        cout << num << endl;
    }

    return 0;
}
