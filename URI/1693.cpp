#include <bits/stdc++.h>
using namespace std;

/*
X(t) = V*cos(a)*t
Y(t) = V*sen(a)*t - G*t²/2

t = X/( V*cos(a) )
Y = H + V*sen(a)*( X/V.cos(a) ) - G*( X/V*cos(a) )²/2
Y = H + tan(a)*X - G*X²/( 2*V²*cos²(a) )

Como o alcance max é X e ele ocorre quando Y = 0, 1 = sen²(a) + cos²(a) -> 1/cos²(a) = tan²(a) + 1
0 = H + tan(a)*Am - G*Am²/( 2*V²*( 1/( tan²(a) + 1 ) ) )
0 = h + tan(a)*Am - G*Am²tan²(a)/( 2*V² ) - G*Am²/( 2*V² )
tan²(a)*G*Am²/( 2*V² ) + G*Am²/( 2*V² ) - tan(a)*Am - H = 0  *( 2*V²/(G*Am²) )
tan²(a) - ( 2*V²/(G*Am) )*tan(a) + 1 - 2*V²*H/(G*Am²) = 0

Agora podemos encontrar o angulo resolvendo a equação do segundo grau para tan(a)
Como queremos apenas um angulo, as duas raiz devem ser reais e iguais, delta = 0
delta = b² - 4*a*c = 0
( 2*V²/(G*Am) )² - 4*[ 1 - 2*V²*H/(G*Am²) ] = 0
4*V^4/(G²Am²) + 8*V²*H/(G*Am²) = 4
4*Am² = 4*V^4/G² + 8*V²*H/G
Am² = V²/G² * ( V² + 2*H*G )
*/

int main() {
	double R, H, V, G;

	while( scanf( "%lf%lf%lf%lf", &R, &H, &V, &G ) != EOF )
		printf( "%s\n", V/G*sqrt( V*V + 2.0*H*G ) - R > 0.01 ? "Y" : "N" );

	return 0;
}