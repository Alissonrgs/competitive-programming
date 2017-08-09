#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *n[27];
    int f;
    
    Node() {
        f = 0;
        for( int i = 0; i < 27; i++ )
            n[i] = NULL; 
    } 
};

int main() {
    int n, q;
    string name;
    Node *trie = new Node();

    cin >> n >> q;
    while( n-- ) {
        cin >> name;
        Node *aux = trie;
        for( int i = 0; i < (int)name.size(); i++ ) {
            aux->f++;
            if( aux->n[ (int)(name[i]-'a') ] == NULL )
                aux->n[ (int)(name[i]-'a') ] = new Node();
            aux = aux->n[ (int)(name[i]-'a') ];
        }
        aux->f++;
    }
    while( q-- ) {
        cin >> name;
        Node *aux = trie;
        for( int i = 0; i < (int)name.size() && aux != NULL; i++ )
            aux = aux->n[ (int)(name[i]-'a') ];
        if( aux != NULL )
            cout << aux->f << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}
