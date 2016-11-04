#include <iostream>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct Time {
	string nome;
	int pontos, num_jogos, gols_marcados, gols_sofridos, saldo_gols;
	double porcentagem;
	Time() {
		pontos = 0;
		num_jogos = 0;
		gols_marcados = 0;
		gols_sofridos = 0;
		saldo_gols = 0;
		porcentagem = 0.0;
	}
} Time;

bool ord( Time a, Time b ) {
	string t1( "" ), t2( "" );
	for( int i=0; i<a.nome.size(); i++ )
		if( isupper( a.nome[i] ) ) t1 += tolower( a.nome[i] );
		else t1 += a.nome[i];
	for( int i=0; i<b.nome.size(); i++ )
		if( isupper( b.nome[i] ) ) t2 += tolower( b.nome[i] );
		else t2 += b.nome[i];

	if( a.pontos == b.pontos ) {
		if( a.saldo_gols == b.saldo_gols ) {
			if( a.gols_marcados == b.gols_marcados )
				return t1 < t2;
			else
				return a.gols_marcados > b.gols_marcados;
		} else
			return a.saldo_gols > b.saldo_gols;
	} else
		return a.pontos > b.pontos;
}

int main() {
	int t, g, g1, g2;
	string t1, t2;
	char c;
	bool espaco = false;

	while( cin >> t >> g && ( t || g ) ) {
		if( espaco ) cout << endl;
		espaco = true;
		Time time[t];

		for( int i=0; i<t; i++ )
			cin >> time[i].nome;
		for( int i=0; i<g; i++ ) {
			cin >> t1 >> g1 >> c >> g2 >> t2;
			for( int j=0; j<t; j++ ) {
				if( time[j].nome == t1 ) {
					if( g1 == g2 ) time[j].pontos += 1;
					else if( g1 > g2 ) time[j].pontos += 3;
					time[j].num_jogos++;
					time[j].gols_marcados += g1;
					time[j].gols_sofridos += g2;
					time[j].saldo_gols = time[j].gols_marcados - time[j].gols_sofridos;
					time[j].porcentagem = 100.0*time[j].pontos/( time[j].num_jogos * 3 );
				}
				if( time[j].nome == t2 ) {
					if( g2 == g1 ) time[j].pontos += 1;
					else if( g2 > g1 ) time[j].pontos += 3;
					time[j].num_jogos++;
					time[j].gols_marcados += g2;
					time[j].gols_sofridos += g1;
					time[j].saldo_gols = time[j].gols_marcados - time[j].gols_sofridos;
					time[j].porcentagem = 100.0*time[j].pontos/( time[j].num_jogos * 3 );
				}
			}
		}
		sort( time, time+t, ord );
		for( int i=0; i<t; i++ ) {
			if( i == 0 )
				cout << " " << i+1 << ". ";
			else if( time[i].pontos != time[i-1].pontos ||
					 time[i].saldo_gols != time[i-1].saldo_gols ||
					 time[i].gols_marcados != time[i-1].gols_marcados )
				cout << " " << i+1 << ". ";
			else
				cout << "    ";
			cout << setw( 15 ) << time[i].nome
				 << setw( 4 )  << time[i].pontos
				 << setw( 4 )  << time[i].num_jogos
				 << setw( 4 )  << time[i].gols_marcados
				 << setw( 4 )  << time[i].gols_sofridos
				 << setw( 4 )  << time[i].saldo_gols;
			if( time[i].num_jogos == 0 )
				cout << setw( 7 ) << "N/A" << endl;
			else
				cout << setw( 7 ) << fixed << setprecision( 2 ) << time[i].porcentagem << endl;
		}
	}

	return 0;
}