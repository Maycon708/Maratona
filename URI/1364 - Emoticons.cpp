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
typedef long long int ll;

ll readInt();

const int cc = 256;										// Tamanho do alfabeto
const int MAX = 2500; 									// Tamanho maximo das somas das strings

int cnt;												// Tamanho da Trie em numero de n�s
int sig[MAX][cc]; 										// Trie
int term[MAX]; 											// N�s terminais
int T[MAX]; 											// Maior prefixo que � sufixo de cada n�
int v[MAX]; 											// Vetor auxiliar que indica em qual posi��o da Trie cada string termina 

inline int C( char c ){
	return int( c );
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

int busca( string s ){
	int x = 0, cnt = 0;
	rep( i, 0, s.size() ){
		int c = C( s[i] );
		while( x && !sig[x][c] ) 
			x = T[x];
		x = sig[x][c];
		if( term[x] ){
			cnt++; x = 0;
		}
	}
	return cnt;
}

int main(){
	
	int n, m;
	string s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		memset( sig, 0, sizeof sig );
		cnt = 1;
		if( !n && !m ) break;
		getchar();
		rep( i, 0, n ){
			getline( cin, s );
			add( s, i );
		}
		aho();
		int resp = 0;
		rep( i, 0, m ){
			getline( cin, s );
			resp += busca( s );
		}
		printf("%d\n", resp );
	}
	
}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

