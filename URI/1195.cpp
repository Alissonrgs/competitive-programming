#include <bits/stdc++.h>
using namespace std;

struct no {
	int v;
	no *esq, *dir;

	no( int v ) {
		this->v = v;
		esq = dir = NULL;
	}
};

void pre_ordem( no *v ) {
	if( v != NULL ) {
		printf( " %d", v->v );
		pre_ordem( v->esq );
		pre_ordem( v->dir );
	}
}
void em_ordem( no *v ) {
	if( v != NULL ) {
		em_ordem( v->esq );
		printf( " %d", v->v );
		em_ordem( v->dir );
	}
}
void pos_ordem( no *v ) {
	if( v != NULL ) {
		pos_ordem( v->esq );
		pos_ordem( v->dir );
		printf( " %d", v->v );
	}	
}

int main() {
	int c, n, v;

	scanf( "%d", &c );
	for( int t=1; t<=c; t++ ) {
		no *raiz = NULL;

		scanf( "%d", &n );
		for( int i=0; i<n; i++ ) {
			scanf( "%d", &v );
			no *novo = new no( v );

			if( raiz == NULL )
				raiz = novo;
			else {
				no *aux = raiz, *ante = NULL;
				while( aux != NULL ) {
					ante = aux;
					if( v < aux->v )
						aux = aux->esq;
					else
						aux = aux->dir;
				}
				if( v < ante->v )
					ante->esq = novo;
				else
					ante->dir = novo;
			}
		}
		printf( "Case %d:", t );
		printf( "\nPre.:" );
		pre_ordem( raiz );
		printf( "\nIn..:" );
		em_ordem( raiz );
		printf( "\nPost:" );
		pos_ordem( raiz );
		printf( "\n\n" );
	}

	return 0;
}