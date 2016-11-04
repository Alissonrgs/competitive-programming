#include <iostream>
using namespace std;

int main() {
    int n, nota[7] = { 100, 50, 20, 10, 5, 2, 1 };
    string snota[7] = { "100,00", "50,00", "20,00", "10,00", "5,00", "2,00", "1,00" };

    cin >> n;
    cout << n << endl;
    for( int i=0; i<7; i++ ) {
        cout << n/nota[i] << " nota(s) de R$ " << snota[i] << endl;
        n %= nota[i];
    }

    return 0;
}
