#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n, op, num;
	bool f, fp, p;

	while( cin >> n ) {
        p = f = fp = true;
        stack<int> pilha;
        queue<int> fila;
        priority_queue<int> fila_p;
 
        for( int i=0; i<n; i++ ) {
            cin >> op >> num;
            if( op == 1 ) {
                pilha.push( num );
                fila.push( num );
                fila_p.push( num );
            }
            if( op == 2 ) {
                if( pilha.top() == num ) pilha.pop();
                else p = false;
                if( fila.front() == num ) fila.pop();
                else f = false;
                if( fila_p.top() == num ) fila_p.pop();
                else fp = false;
            }
        }
        if( p && !f && !fp ) cout << "stack\n";
        else if( !p && f && !fp ) cout << "queue\n";
        else if( !p && !f && fp ) cout << "priority queue\n";
        else if( !p && !f && !fp ) cout << "impossible\n";
        else cout << "not sure\n";
	}

	return 0;
}