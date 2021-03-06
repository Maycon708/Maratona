#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef pair <string, int> si;
typedef long long int ll;

const int cc = 26;										// Tamanho do alfabeto
const int MAX = 1000100; 									// Tamanho maximo das somas das strings

int cnt;												// Tamanho da Trie em numero de n�s
int sig[MAX][cc]; 										// Trie
int term[MAX]; 											// N�s terminais
int T[MAX]; 											// Maior prefixo que � sufixo de cada n�
int v[MAX]; 											// Vetor auxiliar que indica em qual posi��o da Trie cada string termina 
int aux[MAX];

inline int C( char c ){
	return c - 'a'; 									// Retorna o valor correspondente a cada caracter
}

// Montando a Trie
void add( string s, int id ){
	int x = 0; 											// Primeiro n� � sempre a raiz
	rep( i, 0, s.size() ){		
		int c = C( s[i] );								// Valor correspondente a cada posi��o da string
		if( !sig[x][c] ){ 								// N� n�o existente
			term[cnt] = 0; 								// Se o n� n�o existe, ele ainda n�o � terminal
			sig[x][c] = cnt++; 							// Cria o n� e incrementa cnt
		}
		x = sig[x][c]; 									// Vai para a posi��o na trie correspondente a posi��o atual da string
	}
	term[x] = 1; 										// Ultima posi��o da string, logo um no terminal
	v[id] = x;											// Salva no vetor auxiliar onde, na Trie, termina a string 
}

// Aho-Corasick 
void aho(){
	queue < int > q;
	rep( i, 0, cc ){									// Verifica a existencia de nos para cada valor do alfabeto saindo da raiz ( zero )
		int x = sig[0][i];				
		if( !x ) continue;								// Se o n� n�o existe, nada a se fazer
		q.push( x ); 									// Joga na fila cada n� existente e vizinho da raiz
		T[x] = 0;										// Maior prefixo-sufixo de uma unica letra � a propria raiz
	}
	while( !q.empty() ){
		int u = q.front();							
		q.pop();
		rep( i, 0, cc ){								// Verifica verifica a existencia de nos para cada valor do alfabeto saindo do n� u
			int x = sig[u][i]; 							
			if( !x ) continue;							// N� inexistente, nada a se fazer
			int v = T[u];								// Inicialmente v � o maior prefixo que tambem � sufixo de u
			while( v && !sig[v][i] ) v = T[v];			// Testa para cada v se ele tambem pode ser prefixo-sufixo de x
			v = sig[v][i];								// Se dirige a posi��o do maior prefixo-sufixo de x
			T[x] = v;									// Salva que o maior prefixo-sufixo de x � o n� v
			term[x] |= term[v];							// Se v � terminal e sufixo de x, x tamb�m sera terminal
			q.push( x );								// Adiciona x a fila
		}
	}
}

// Total de ocorrencias de cada padr�o em uma string, mesmo com sufixos iguais
ll busca2( string s ){
	int x = 0, ans = 0;									// N� inicial ( raiz ) e contador de ocorrencias
	rep( i, 0, s.size() ){								// Para cada posi��o da string
		int c = C( s[i] );								// A variavel "c" corresponde ao valor da string naquela posi��o
		while( x && !sig[x][c] ) x = T[x];				// Volta os n�s at� encontrar um prefixo sufixo da posi��o atual e que contem caminho para "c" 
		x = sig[x][c];									// Se move para o n� encontrado
		if( term[x] ){
			int k = x;
			while( k ){
				if( term[k] ) ans = max( ans, aux[k] );
				k = T[k];
			}
		}
	}
	return ans;										// Retorna o valor do contador
}

inline bool cmp( si a, si b ){
	return a.F.size() < b.F.size();
}

int main(){

	int n;
	string s;
		
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;

		cnt = 1;
		vector < si > V;
		
		int tam = 10;
		rep( i, 0, n ){
			cin >> s;
			tam += s.size();
			V.pb( si( s, i ) );
		}
		rep( i, 0, tam ){
			rep( j, 0, cc ) sig[i][j] = 0;
			aux[i] = 0;
		}
		
		rep( i, 0, n ) add( V[i].F, V[i].S );
		aho();
		sort( all( V ), cmp );
		
		ll ans = 0;
		rep( i, 0, n ){
			ll a = busca2( V[i].F ) + 1;
			ans = max( ans, a );
			aux[ v[ V[i].S ] ] = a;
		}
		printf("%lld\n", ans );
	}

}

