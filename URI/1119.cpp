#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *l;
    Node *r;
    
    Node( int _data ) : data(_data) { l = r = this; }
};

Node *cabeca;

bool vazia() {
    return cabeca->l == cabeca->r && cabeca->r == cabeca;
}

void inserir( int data ) {
    Node *node = new Node( data );

    node->l = cabeca->l;
    node->r = cabeca;
    cabeca->l = node;
    node->l->r = node;
}

void excluir( int data ) {
    if( !vazia() ) {
        Node *node = cabeca->r;

        while( node != cabeca && node->data != data )
            node = node->r;
        
        if( node != cabeca ) {
            node->r->l = node->l;
            node->l->r = node->r;
        }
        delete node;
    }
}

int main() {
	int n, k, m;
	Node *ik, *im;

	while( scanf( "%d%d%d", &n, &k, &m ) && n ) {
		cabeca = new Node(-1);
		ik = cabeca, im = cabeca;

		for( int i = 1; i <= n; i++ )
			inserir( i );

		int _k, _m;
		bool p = true;

		while( !vazia() ) {
			Node *node = cabeca->r;

			for( int i = 0; i < k; i++ ) {
				ik = ik->r;
				if( ik == cabeca )
					ik = ik->r;
			}
			for( int i = 0; i < m; i++ ) {
				im = im->l;
				if( im == cabeca )
					im = im->l;
			}

			if( ik == im ) {
				cout << ( p ? "" : "," ) << setw(3) << ik->data;
				p = false;
				
				_k = ik->data;
				ik = ik->l;
				if( ik == cabeca ) ik = ik->l;
				im = im->r;
				if( im == cabeca ) im = im->r;
				excluir( _k );

			} else {
				cout << ( p ? "" : "," ) << setw(3) << ik->data << setw(3) << im->data;
				p = false;

				_k = ik->data;
				ik = ik->l;
				if( ik == cabeca ) ik->l;
				excluir( _k );

				_m = im->data;
				im = im->r;
				if( im == cabeca ) im = im->r;
				excluir( _m );
			}
		}
		putchar('\n');
	}

	return 0;
}