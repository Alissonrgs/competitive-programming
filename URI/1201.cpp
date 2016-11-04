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
    bool espaco;
    
    Tree() {
        root = NULL;
    }
    
    void insert( int data ) {
        Node *pai = NULL, *node = root;
    
        if( root == NULL ) {
            root = new Node(data);
            return;
        }
        while( node->data != data ) {
            if( data < node->data ) {
                if( node->l == NULL )
                    node->l = new Node(data);
                node = node->l;
            } else {
                if( node->r == NULL )
                    node->r = new Node(data);
                node = node->r;
            }
        }
    }
    
    void remove( Node *node, int data ) {
        Node *pai = NULL, *filho = node, *pai_aux = NULL, *aux = NULL;
        
        while( filho != NULL && filho->data != data ) {
            pai = filho;
            if( data < filho->data )
                filho = filho->l;
            else
                filho = filho->r;
        }
        if( filho != NULL ) {
            aux = filho;
            if( filho->r == NULL )
                filho = filho->l;
            else if( filho->l == NULL )
                filho = filho->r;
            else {
                pai_aux = filho;
                aux = filho->l;
                while( aux->r != NULL ) {
                    pai_aux = aux;
                    aux = aux->r;
                }
                filho->data = aux->data;
                if( pai_aux == filho )
                    pai_aux->l = aux->l;
                else
                    pai_aux->r = aux->l;
            }
            if( pai == NULL )
                root = filho;
            else if( pai->l == aux )
                pai->l = filho;
            else if( pai->r == aux)
                pai->r = filho;
            
            delete aux;
        }
    }
    
    bool search( Node *node, int data ) {
        while( node != NULL && node->data != data ) {
            if( data < node->data )
                node = node->l;
            else
                node = node->r;
        }
        return node != NULL;
    }

    void prefixa( Node *node ) {
	    if( node == NULL ) return;
        printf( "%s%d", ( espaco ? " " : "" ), node->data ), espaco = true;
        prefixa( node->l );
        prefixa( node->r );
    }

    void infixa( Node *node ) {
	    if( node == NULL ) return;
	    infixa( node->l );
	    printf( "%s%d", ( espaco ? " " : "" ), node->data ), espaco = true;
	    infixa( node->r );
    }

    void posfixa( Node *node ) {
	    if( node == NULL ) return;
	    posfixa( node->l );
	    posfixa( node->r );
	    printf( "%s%d", ( espaco ? " " : "" ), node->data ), espaco = true;
    }
};

int main() {
    int data;
    string comando;
    Tree tree;
    
    while( cin >> comando ) {
        if( comando == "I" ) {
            cin >> data;
            tree.insert(data);
        
        } else if( comando == "PREFIXA" ) {
            tree.espaco = false;
            tree.prefixa(tree.root);
            cout << endl;
        
        } else if( comando == "INFIXA" ) {
            tree.espaco = false;
            tree.infixa(tree.root);
            cout << endl;
        
        } else if( comando == "POSFIXA" ) {
            tree.espaco = false;
            tree.posfixa(tree.root);
            cout << endl;

        } else if( comando == "P" ) {
            cin >> data;
            if( tree.search( tree.root, data ) )
                cout << data << " existe\n";
            else
                cout << data << " nao existe\n";

        } else if( comando == "R" ) {
            cin >> data;
            tree.remove( tree.root, data );
        }
    }

    return 0;
}
