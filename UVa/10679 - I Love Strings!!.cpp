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

const int cc = 52;										// Tamanho do alfabeto
const int MAX = 1000010; 									// Tamanho maximo das somas das strings

int cnt;												// Tamanho da Trie em numero de nós
int sig[MAX][cc]; 										// Trie
int term[MAX]; 											// Nós terminais
int T[MAX]; 											// Maior prefixo que é sufixo de cada nó
int v[MAX]; 											// Vetor auxiliar que indica em qual posição da Trie cada string termina 

inline int C( char c ){
	if( c >= 'a' && c <= 'z' )
		return c - 'a';									// Retorna o valor correspondente a cada caracter
	return c - 'A' + 26;
}

// Montando a Trie
void add( string s, int id ){
	int x = 0; 											// Primeiro nó é sempre a raiz
	rep( i, 0, s.size() ){		
		int c = C( s[i] );								// Valor correspondente a cada posição da string
		if( !sig[x][c] ){ 								// Nó não existente
			term[cnt] = 0; 								// Se o nó não existe, ele ainda não é terminal
			sig[x][c] = cnt++; 							// Cria o nó e incrementa cnt
		}
		x = sig[x][c]; 									// Vai para a posição na trie correspondente a posição atual da string
	}
	term[x] = 1; 										// Ultima posição da string, logo um no terminal
	v[id] = x;											// Salva no vetor auxiliar onde, na Trie, termina a string 
}

// Aho-Corasick 
void aho(){
	queue < int > q;
	rep( i, 0, cc ){									// Verifica a existencia de nos para cada valor do alfabeto saindo da raiz ( zero )
		int x = sig[0][i];				
		if( !x ) continue;								// Se o nó não existe, nada a se fazer
		q.push( x ); 									// Joga na fila cada nó existente e vizinho da raiz
		T[x] = 0;										// Maior prefixo-sufixo de uma unica letra é a propria raiz
	}
	while( !q.empty() ){
		int u = q.front();							
		q.pop();
		rep( i, 0, cc ){								// Verifica verifica a existencia de nos para cada valor do alfabeto saindo do nó u
			int x = sig[u][i]; 							
			if( !x ) continue;							// Nó inexistente, nada a se fazer
			int v = T[u];								// Inicialmente v é o maior prefixo que tambem é sufixo de u
			while( v && !sig[v][i] ) v = T[v];			// Testa para cada v se ele tambem pode ser prefixo-sufixo de x
			v = sig[v][i];								// Se dirige a posição do maior prefixo-sufixo de x
			T[x] = v;									// Salva que o maior prefixo-sufixo de x é o nó v
			term[x] += term[v];							// Se v é terminal e sufixo de x, x também sera terminal
			q.push( x );								// Adiciona x a fila
		}
	}
}

// Conta a quantidade de palavras de exatamente l caracteres que se pode formar com um determinado alfabeto, dado que algumas palavras são "proibidas"

int mod = 1e9+7;										// Modulo, caso seja necessário
ll pd[100][MAX];										// Matriz pd

ll solve( int pos, int no ){
	if( pos == 0 ) return 1;							// Se não há mais posições pra se colocar letras, retorna q uma palvra foi formada
	if( pd[pos][no] != -1 ) return pd[pos][no];			// Bom e velho memoize
	ll ans = 0;											// Inicialização :P
	rep( i, 0, cc ){									// Tenta colocar todas as letras do alfabeto
		int v = no;										// A variavel "v" começa com o valor do nó atual
		while( v && !sig[v][i] ) v = T[v];				// Procura o maior prefixo-sufixo do nó atual que possui caminho para a letra i
		v = sig[v][i];									// Se move para o no encontrado
		if( term[v] ) continue;							// se o nó v é terminal, tal palavra é uma das palvras proibidas, portanto n deve ser formada
		ans = ( ans + solve( pos-1, v ) )%mod;			// Uma posição a menos a ser preenchida, agora no nó v
	}
	return pd[pos][no] = ans;						
}

void Qttd_de_Palavras(){ 
	
	while( 1 ){
		memset( sig, 0, sizeof sig );					// Zera a trie
		memset( pd, -1, sizeof pd );					// Inicializa a matriz pd com -1, inicialmente 1, a raiz
		cnt = 1;										// Inicializa o tamanho da arvore
		int l = readInt(); 								// Tamanho max das palavras
		if( !l ) break;
		int n = readInt();								// Numero de strings proibidas
		string pattern;
		rep( i, 0, n ){ 							
			cin >> pattern;								// Palavras proibidas
			add( pattern, i );							// Adiciona a Trie as palavras proibidas
		}
		aho();											// Monta Aho-Corassick
		ll ans = 0;
		rep( i, 1, l+1 )  
			ans = ( ans + solve( i, 0 ) )%mod;			// Varia todos s tamanhos, para pegar todas as palavras de até l caracteres
		printf("%d\n", ans );							// Mostra a resposta
	}
}

// Verifica quais padrões ocorreram em um texto

int alc[MAX]; 											// Indica quais posições da trie foram alcançadas durante o texto

void busca( string s ){	
	int x = 0;											// Inicialmente se posiciona na raiz da Trie
	rep( i, 0, s.size() ){								// Percorre toda a string
		int c = C( s[i] );								// Valor da posição atual da string
		while( x && !sig[x][c] ) x = T[x];				// Procura o maior prefixo-sufixo do no atual que possui caminho para c  
		x = sig[x][c];									// Se move para o nó encontrado
		alc[x] = 1;										// Marca que o nó encontrado pode ser alcançado durante o texto
	}
}

void Ql_Ocorreu(){
	string pattern, text;
	int test = readInt();
	while( test-- ){
		cin >> text;									// Texto onde serão buscados os padrões
		memset( sig, 0, sizeof sig );					// Zera a Trie
		memset( alc, 0, sizeof alc );					// Zera o vetor de alcançados
		cnt = 1;										// Inicializa o tamanho da Trie
		int n = readInt();								// Numero de padões a serem buscados no texto
		rep( i, 0, n ){
			cin >> pattern;								
			add( pattern, i );							// Adiciona os padrões a Trie
		}
		aho();											// Monta Aho-Corasick
		busca( text );									// Faz a busca no texto para demarcar quais nós podem ser alcançados
		for( int i = cnt-1; i >= 0; i-- ){				// Testa para todos os nós da trie se eles foram alcançados
			if( alc[i] ) alc[ T[i] ] = 1;				// Todos os nós cujos prefixos sejam iguais a seu sufixo também foram alcançados
		}											
		rep( i, 0, n ){
			int u = v[i];								// A variavel "u" representa em que nó da arvore cada string foi encerrada
			if( alc[u] ) printf("y\n");					// Se o nó onde tal string foi encerrada foi alcançado, o padrão existe no texto
			else printf("n\n");							// Caso o contrario, o padrão não existe
		}
	}
}

// Total de ocorrencias de cada padrão em uma string, mesmo com sufixos iguais
ll busca2( string s ){
	ll x = 0, cont = 0;									// Nó inicial ( raiz ) e contador de ocorrencias
	rep( i, 0, s.size() ){								// Para cada posição da string
		int c = C( s[i] );								// A variavel "c" corresponde ao valor da string naquela posição
		while( x && !sig[x][c] ) x = T[x];				// Volta os nós até encontrar um prefixo sufixo da posição atual e que contem caminho para "c" 
		x = sig[x][c];									// Se move para o nó encontrado
		cont += term[x];								// Conta quantas strings terminam naquele nó
	}
	return cont;										// Retorna o valor do contador
}

void Qnts_vezes_Ocorreu(){
	string text, pattern;				
	while( cin >> text ){								// String onde serão procurados os padrões
		if( text == "*" ) break;
		memset( sig, 0, sizeof sig );					// Zera a Trie
		cnt = 1;										// Inicializa o tamanho da Trie
		int n = readInt();								// Numero de padões a serem buscados no texto
		rep( i, 0, n ){			
			cin >> pattern;						
			add( pattern, i );							// Adiciona na Trie cada padrão
		}
		aho();											// Monta o Aho-Corasick
		cout << busca2( text ) << endl;					// Mostra o resultado da busca
	}
}

//Encontra a primeira ocorrencia de cada padrão em uma string
void busca3( string s ){
	int x = 0;											// Inicialmente na matriz
	rep( i, 0, s.size() ){								// Percorre toda a string
		int c = C( s[i] );								// A variavel "c" corresponde ao valor da string na posição atual
		while( x && !sig[x][c] ) x = T[x];				// Volta os nós até encontrar um prefixo sufixo da posição atual e que contem caminho para c 
		x = sig[x][c];									// Se move para o nó encontrado
		if( alc[x] ) alc[x] = i+1;						// Salva a menor posição onde o no x pode ser alcançado
	}
}

void Onde_Ocorreu(){
	string pattern, text;
	int tam[1000]; 										// Vetor para salvar o tamanho de cada padrão
	while( cin >> text ){								// String onde os padrões serão buscados
		if( text == "*" ) break;
		memset( sig, 0, sizeof sig );					// Zera a Trie
		memset( alc, INF, sizeof alc );					// Inicializa o vetor de alcançados com INF
		cnt = 1;										// Inicializa o tamanho da arvore
		int n = readInt();								// Numero de padões a serem buscados no texto
		rep( i, 0, n ){
			cin >> pattern;					
			tam[i] = pattern.size();					// Salva o tamanho de cada padrão
			add( pattern, i );							// Adiciona cada padrão a Trie
		}	
		aho();											// Monta o Aho-Corasick
		busca3( text );
		for( int i = cnt-1; i >= 0; i-- ){				// Para cada nó da arvore
			alc[ T[i] ] = min( alc[i], alc[ T[i] ] );	// Tenta atualizar a primeira ocorrencia do maior prefixo que também é sufixo de cada nó
		}
		rep( i, 0, n ){
			int u = v[i];								// No onde termina o padrão i
			if( alc[u] != INF ){						// Se u foi alcançado, o padrão esta presente no texto
				int k = alc[u] - tam[i] + 1;			// Posição onde começa o padrão no texto ( pos. final - tamanho )
				printf("De %d a %d\n", k, alc[u] );
			}
			else  										// Se alc[u] for INF, o padrão não existe no texto
				printf("Nao ocorreu\n");
		}
	}
}

int main(){
	Ql_Ocorreu();
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

