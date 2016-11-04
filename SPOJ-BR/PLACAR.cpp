#include <iostream>
#include <algorithm>
using namespace std;
 
typedef struct {
	string nome;
	int nota;
} Aluno;

bool troca( Aluno a, Aluno b ) {
	if( a.nota == b.nota ) return a.nome > b.nome;
	else return a.nota < b.nota;
}
 
int main() {
	int n, k = 1;
	Aluno aluno[105];

	while( cin >> n ) {
		for( int i=0; i<n; i++ )
			cin >> aluno[i].nome >> aluno[i].nota;
		
		sort( &aluno[0], &aluno[n], troca );
 
		cout << "Instancia " << k++ << endl
			 << aluno[0].nome << endl << endl;
	}
 
	return 0;
} 