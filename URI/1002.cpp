#include <iostream>
using namespace std;

#define PI 3.14159

int main() {
    double raio;

    cin >> raio;
    cout.precision(4);
    cout << "A=" << fixed << (double)PI*raio*raio << endl;

    return 0;
}
