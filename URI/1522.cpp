#include <bits/stdc++.h>
using namespace std;
 
stack<int> a, b, c;
 
bool verificar(){
    if( a.empty() && b.empty() && c.empty() ) return true;
    if( ( a.empty() && b.empty() ) || ( b.empty() && c.empty() ) || ( a.empty() && c.empty() ) ) return false;
    
    if( a.empty() ) {
        if( ( b.top() + c.top() )%3 ) return false;
        else b.pop(), c.pop();
        return verificar();
    
    } else if( b.empty() ) {
        if( ( c.top() + a.top() )%3 ) return false;
        else a.pop(), c.pop();
        return verificar();
    
    } else if( c.empty() ) {
        if( ( b.top() + a.top() )%3 ) return false;
        else b.pop(), a.pop();
        return verificar();
    
    } else {
        if( !( ( a.top() + b.top() + c.top() )%3 ) ) {
            a.pop(); b.pop(); c.pop();
            return verificar();
        }
        bool parab, parbc, parac;
        int A = a.top(), B = b.top(), C = c.top();
 
        if( ( A + B ) % 3 == 0 ) {
            a.pop(); b.pop();
            parab = verificar();
            a.push( A ); b.push( B );
        } else if( ( B + C ) % 3 == 0 ){
            b.pop(); c.pop();
            parbc = verificar();
            b.push( B ); c.push( C );
        } else if( ( A + C ) % 3 == 0 ){
            a.pop(); c.pop();
            parac = verificar();
            a.push( A ); c.push( C );
        }
        return parab || parbc || parac;
    }
}
 
int main() {
    int n;
 
    while( scanf( "%d", &n ) && n ) {
        int cont = 0;
        while( !a.empty() ) a.pop();
        while( !b.empty() ) b.pop();
        while( !c.empty() ) c.pop();
 
        for( int i=0, A, B, C; i<n; i++ ){
            scanf( "%d%d%d", &A, &B, &C );
            cont += A%3 + B%3 + C%3;
            if( A%3 ) a.push( A );
            if( B%3 ) b.push( B );
            if( C%3 ) c.push( C );
        }
        printf( "%d\n", cont%3 ? 0 : verificar() );
    }

    return 0;
}