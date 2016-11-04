#include <iostream>
using namespace std;

int main() {
    int qnt;
    char c;
    string seq, aux;

    while( getline( cin, seq ) ) {
        qnt = 1, c = '\0', aux.clear();
        for( int i=0; i<seq.size(); i++ ) {
            if( seq[i] == c && qnt+1 <= 9 ) {
                qnt++;
                if( !aux.empty() ) cout << "1" + aux + "1", aux.clear();
            } else {
                if( ( i < seq.size()-1 && seq[i] != seq[i+1] ) || i == seq.size()-1 ) {
                    aux += seq[i];
                    aux += seq[i] == '1' ? "1" : "";
                }
                if( qnt > 1 ) cout << qnt << c, qnt = 1;
            }
            if( i == seq.size()-1 ) {
                if( qnt > 1 ) cout << qnt << c;
                else cout << "1" + aux + "1";
            }
            c = seq[i];
        }
        cout << endl;
    }
    
    return 0;
}