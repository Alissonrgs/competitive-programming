#include <iostream>
using namespace std;

int main() {
    double n;
    int N, nota[12] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1 }, NOTA;

    cin >> n;
    n = n*100.0;
    N = (int)n;
    for( int i=0; i<12; i++ ) {
        NOTA = nota[i];
        nota[i] = 0;
        while( N >= NOTA ) {
            nota[i]++;
            N -= NOTA;
        }
    }
    cout << "NOTAS:\n"
         << nota[0] << " nota(s) de R$ 100.00\n"
         << nota[1] << " nota(s) de R$ 50.00\n"
         << nota[2] << " nota(s) de R$ 20.00\n"
         << nota[3] << " nota(s) de R$ 10.00\n"
         << nota[4] << " nota(s) de R$ 5.00\n"
         << nota[5] << " nota(s) de R$ 2.00\n"
         << "MOEDAS:\n"
         << nota[6] << " moeda(s) de R$ 1.00\n"
         << nota[7] << " moeda(s) de R$ 0.50\n"
         << nota[8] << " moeda(s) de R$ 0.25\n"
         << nota[9] << " moeda(s) de R$ 0.10\n"
         << nota[10] << " moeda(s) de R$ 0.05\n"
         << nota[11] << " moeda(s) de R$ 0.01\n";

    return 0;
}
