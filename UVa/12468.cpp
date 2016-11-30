#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    
    while( scanf( "%d%d", &a, &b ) && a != -1 ) {
        int left = a, right = a, c = 0;
        while( left != b && right != b ) {
            left = ( left-1 < 0 ? left+99 : left-1 );
            right = ( right+1 )%100;
            c++;
        }
        printf( "%d\n", c );
    }

    return 0;
}
