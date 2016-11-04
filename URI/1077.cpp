#include <bits/stdc++.h>
using namespace std;

string infixaParaPosfixa( string inf ) {
    string posf = "";
    stack<char> pilha;

    for( int i=0; i<inf.size(); i++ )
        switch( inf[i] ) {
            case '(':
                pilha.push( inf[i] );
                break;
            case ')':
                while( !pilha.empty() ) {
                    if( pilha.top() == '(' ) {
                        pilha.pop();
                        break;
                    }
                    posf += pilha.top(), pilha.pop();
                }
                break;
            case '+':
            case '-':
                while( !pilha.empty() ) {
                    if( pilha.top() == '(' )
                        break;
                    posf += pilha.top(), pilha.pop();
                }
                pilha.push( inf[i] );
                break;
            case '*':
            case '/':
                while( !pilha.empty() ) {
                    if( pilha.top() == '(' || pilha.top() == '+' || pilha.top() == '-' )
                        break;
                    posf += pilha.top(), pilha.pop();
                }
                pilha.push( inf[i] );
                break;
            case '^':
                while( !pilha.empty() ) {
                    if( pilha.top() == '(' || pilha.top() == '+' || pilha.top() == '-' || pilha.top() == '/' || pilha.top() == '*' )
                        break;
                    posf += pilha.top(), pilha.pop();
                }
                pilha.push( inf[i] );
                break;
            default:
                posf += inf[i];
        }
    while( !pilha.empty() )
        posf += pilha.top(), pilha.pop();

    return posf;
} 

int main() {
    int n;
    string inf;

    cin >> n;
    while( n-- ) {
        cin >> inf;
        cout << infixaParaPosfixa( inf ) << endl;
    }

    return 0;
}