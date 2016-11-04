#include <iostream>
using namespace std;

int main() {
    int tam, n1=0, n2=1;

    cin >> tam;
    for( int i=1; i<=tam; i++ ) {
        cout << n1 << ( i == tam ? "\n": " " );
        n2 += n1;
        n1 = n2 - n1;
    }

    return 0;
}
