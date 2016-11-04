#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *l, *r;
    
    Node( int data ) {
        l = r = NULL;
        this->data = data;
    }
};

struct Tree {
    Node *root;
    
    Tree() {
        root = NULL;
    }
    
    void insert( int data ) {
        if( root == NULL ) {
            root = new Node(data);
            return;
        }
        
        insert( root, data );
    }
    
    void insert( Node *node, int data ) {
        if( node->data == data )
            return;

        if( data < node->data ) {
            if( node->l == NULL )
                node->l = new Node(data);
            else
                insert( node->l, data );
        }
        else {
            if( node->r == NULL )
                node->r = new Node(data);
            else
                insert( node->r, data );
        }
    }
    
    void bfs() {
        bool espaco = false;
        queue<Node*> fila;
        fila.push( root );
        
        while( !fila.empty() ) {
            Node *node = fila.front();
            fila.pop();
            
            if( node == NULL )
                continue;
            
            printf( "%s%d", espaco ? " " : "", node->data );
            espaco = true;
            fila.push( node->l );
            fila.push( node->r );
        }
    }
};

int main() {
    int c, n, data;
    
    scanf( "%d", &c );
    for( int i = 1; i <= c; i++ ) {
        Tree tree;
        
        scanf( "%d", &n );
        for( int j = 0; j < n; j++ ) {
            scanf( "%d", &data );
            tree.insert( data );
        }
        
        printf( "Case %d:\n", i );
        tree.bfs();
        printf( "\n\n" );
    }   

    return 0;
}
