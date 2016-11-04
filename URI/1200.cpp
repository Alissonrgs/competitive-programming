#include <bits/stdc++.h>
using namespace std;

struct node {
	char l;
	node *esq, *dir;
	node() { esq = dir = NULL; }
	node( int _l ) : l(_l) {}
};

bool espaco;

node* search( node *tree, char l ) {
	node* aux = tree;

	while( aux != NULL && aux->l != l )
		if( l < aux->l ) aux = aux->esq;
		else aux = aux->dir;

	return aux;
}

void prefixa( node *no ) {
	if( no != NULL ) {
		printf( "%s%c", ( espaco ? " " : "" ), no->l ), espaco = true;
		prefixa( no->esq );
		prefixa( no->dir );
	}
}

void infixa( node *no ) {
	if( no != NULL ) {
		infixa( no->esq );
		printf( "%s%c", ( espaco ? " " : "" ), no->l ), espaco = true;
		infixa( no->dir );
	}
}

void posfixa( node *no ) {
	if( no != NULL ) {
		posfixa( no->esq );
		posfixa( no->dir );
		printf( "%s%c", ( espaco ? " " : "" ), no->l ), espaco = true;
	}
}

int main() {
	char l;
	string in;
	node *tree = NULL;

	while( cin >> in ) {
		if( in.size() == 1 ) {
			cin >> l;
			if( in == "I" ) {
				if( tree == NULL )
					tree = new node( l );
				else {
					node *aux = tree, *prev = NULL;
					while( aux != NULL ) {
						prev = aux;
						if( l < aux->l ) aux = aux->esq;
						else aux = aux->dir;
					}
					if( l < prev->l )
						prev->esq = new node( l );
					else
						prev->dir = new node( l );
				}
			
			} else {
				node* aux = search( tree, l );
				printf( "%c %s\n", l, ( aux == NULL ? "nao existe" : "existe" ) );
			}
		} else {
			espaco = false;
			if( in == "PREFIXA" ) prefixa( tree );
			else if( in == "INFIXA" ) infixa( tree );
			else posfixa( tree );
			printf( "\n" );
		}
	}

	return 0;
}