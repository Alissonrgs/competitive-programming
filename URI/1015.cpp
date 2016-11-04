#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x[2], y[2], X, Y;

    cin >> x[0] >> y[0] >> x[1] >> y[1];
    X = pow( x[1] - x[0], 2 );
    Y = pow( y[1] - y[0], 2 );
    cout.precision(4);
    cout << fixed << sqrt( X + Y ) << endl;

    return 0;
}
