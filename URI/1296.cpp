#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long double m1, m2, m3, o, a;
 
    while( scanf( "%Lf%Lf%Lf", &m1, &m2, &m3 ) != EOF ) {
        o = ( m1 + m2 + m3 )/2.0;
        o = o*( o - m1 )*( o - m2 )*( o - m3 );
        if( o > 0 ) {
            a = 4.0*( sqrt( o ) )/3.0;  
            printf( "%.3Lf\n", a );
         
        } else
            printf( "-1.000\n" );   
    } 
 
    return 0;
}