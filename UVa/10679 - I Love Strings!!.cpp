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

int cnt;												// Tamanho da Trie em numero de n�s
int sig[MAX][cc]; 										// Trie
int term[MAX]; 											// N�s terminais
int T[MAX]; 											// Maior prefixo que � sufixo de cada n�
int v[MAX]; 											// Vetor auxiliar que indica em qual posi��o da Trie cada string termina 

inline int C( char c ){
	if( c >= 'a' && c <= 'z' )
		return c - 'a';									// Retorna o valor correspondente a cada caracter
	return c - 'A' + 26;
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
			term[x] += term[v];							// Se v � terminal e sufixo de x, x tamb�m sera terminal
			q.push( x );								// Adiciona x a fila
		}
	}
}

// Conta a quantidade de palavras de exatamente l caracteres que se pode formar com um determinado alfabeto, dado que algumas palavras s�o "proibidas"

int mod = 1e9+7;										// Modulo, caso seja necess�rio
ll pd[100][MAX];										// Matriz pd

ll solve( int pos, int no ){
	if( pos == 0 ) return 1;							// Se n�o h� mais posi��es pra se colocar letras, retorna q uma palvra foi formada
	if( pd[pos][no] != -1 ) return pd[pos][no];			// Bom e velho memoize
	ll ans = 0;											// Inicializa��o :P
	rep( i, 0, cc ){									// Tenta colocar todas as letras do alfabeto
		int v = no;										// A variavel "v" come�a com o valor do n� atual
		while( v && !sig[v][i] ) v = T[v];				// Procura o maior prefixo-sufixo do n� atual que possui caminho para a letra i
		v = sig[v][i];									// Se move para o no encontrado
		if( term[v] ) continue;							// se o n� v � terminal, tal palavra � uma das palvras proibidas, portanto n deve ser formada
		ans = ( ans + solve( pos-1, v ) )%mod;			// Uma posi��o a menos a ser preenchida, agora no n� v
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
			ans = ( ans + solve( i, 0 ) )%mod;			// Varia todos s tamanhos, para pegar todas as palavras de at� l caracteres
		printf("%d\n", ans );							// Mostra a resposta
	}
}

// Verifica quais padr�es ocorreram em um texto

int alc[MAX]; 											// Indica quais posi��es da trie foram alcan�adas durante o texto

void busca( string s ){	
	int x = 0;											// Inicialmente se posiciona na raiz da Trie
	rep( i, 0, s.size() ){								// Percorre toda a string
		int c = C( s[i] );								// Valor da posi��o atual da string
		while( x && !sig[x][c] ) x = T[x];				// Procura o maior prefixo-sufixo do no atual que possui caminho para c  
		x = sig[x][c];									// Se move para o n� encontrado
		alc[x] = 1;										// Marca que o n� encontrado pode ser alcan�ado durante o texto
	}
}

void Ql_Ocorreu(){
	string pattern, text;
	int test = readInt();
	while( test-- ){
		cin >> text;									// Texto onde ser�o buscados os padr�es
		memset( sig, 0, sizeof sig );					// Zera a Trie
		memset( alc, 0, sizeof alc );					// Zera o vetor de alcan�ados
		cnt = 1;										// Inicializa o tamanho da Trie
		int n = readInt();								// Numero de pad�es a serem buscados no texto
		rep( i, 0, n ){
			cin >> pattern;								
			add( pattern, i );							// Adiciona os padr�es a Trie
		}
		aho();											// Monta Aho-Corasick
		busca( text );									// Faz a busca no texto para demarcar quais n�s podem ser alcan�ados
		for( int i = cnt-1; i >= 0; i-- ){				// Testa para todos os n�s da trie se eles foram alcan�ados
			if( alc[i] ) alc[ T[i] ] = 1;				// Todos os n�s cujos prefixos sejam iguais a seu sufixo tamb�m foram alcan�ados
		}											
		rep( i, 0, n ){
			int u = v[i];								// A variavel "u" representa em que n� da arvore cada string foi encerrada
			if( alc[u] ) printf("y\n");					// Se o n� onde tal string foi encerrada foi alcan�ado, o padr�o existe no texto
			else printf("n\n");							// Caso o contrario, o padr�o n�o existe
		}
	}
}

// Total de ocorrencias de cada padr�o em uma string, mesmo com sufixos iguais
ll busca2( string s ){
	ll x = 0, cont = 0;									// N� inicial ( raiz ) e contador de ocorrencias
	rep( i, 0, s.size() ){								// Para cada posi��o da string
		int c = C( s[i] );								// A variavel "c" corresponde ao valor da string naquela posi��o
		while( x && !sig[x][c] ) x = T[x];				// Volta os n�s at� encontrar um prefixo sufixo da posi��o atual e que contem caminho para "c" 
		x = sig[x][c];									// Se move para o n� encontrado
		cont += term[x];								// Conta quantas strings terminam naquele n�
	}
	return cont;										// Retorna o valor do contador
}

void Qnts_vezes_Ocorreu(){
	string text, pattern;				
	while( cin >> text ){								// String onde ser�o procurados os padr�es
		if( text == "*" ) break;
		memset( sig, 0, sizeof sig );					// Zera a Trie
		cnt = 1;										// Inicializa o tamanho da Trie
		int n = readInt();								// Numero de pad�es a serem buscados no texto
		rep( i, 0, n ){			
			cin >> pattern;						
			add( pattern, i );							// Adiciona na Trie cada padr�o
		}
		aho();											// Monta o Aho-Corasick
		cout << busca2( text ) << endl;					// Mostra o resultado da busca
	}
}

//Encontra a primeira ocorrencia de cada padr�o em uma string
void busca3( string s ){
	int x = 0;											// Inicialmente na matriz
	rep( i, 0, s.size() ){								// Percorre toda a string
		int c = C( s[i] );								// A variavel "c" corresponde ao valor da string na posi��o atual
		while( x && !sig[x][c] ) x = T[x];				// Volta os n�s at� encontrar um prefixo sufixo da posi��o atual e que contem caminho para c 
		x = sig[x][c];									// Se move para o n� encontrado
		if( alc[x] ) alc[x] = i+1;						// Salva a menor posi��o onde o no x pode ser alcan�ado
	}
}

void Onde_Ocorreu(){
	string pattern, text;
	int tam[1000]; 										// Vetor para salvar o tamanho de cada padr�o
	while( cin >> text ){								// String onde os padr�es ser�o buscados
		if( text == "*" ) break;
		memset( sig, 0, sizeof sig );					// Zera a Trie
		memset( alc, INF, sizeof alc );					// Inicializa o vetor de alcan�ados com INF
		cnt = 1;										// Inicializa o tamanho da arvore
		int n = readInt();								// Numero de pad�es a serem buscados no texto
		rep( i, 0, n ){
			cin >> pattern;					
			tam[i] = pattern.size();					// Salva o tamanho de cada padr�o
			add( pattern, i );							// Adiciona cada padr�o a Trie
		}	
		aho();											// Monta o Aho-Corasick
		busca3( text );
		for( int i = cnt-1; i >= 0; i-- ){				// Para cada n� da arvore
			alc[ T[i] ] = min( alc[i], alc[ T[i] ] );	// Tenta atualizar a primeira ocorrencia do maior prefixo que tamb�m � sufixo de cada n�
		}
		rep( i, 0, n ){
			int u = v[i];								// No onde termina o padr�o i
			if( alc[u] != INF ){						// Se u foi alcan�ado, o padr�o esta presente no texto
				int k = alc[u] - tam[i] + 1;			// Posi��o onde come�a o padr�o no texto ( pos. final - tamanho )
				printf("De %d a %d\n", k, alc[u] );
			}
			else  										// Se alc[u] for INF, o padr�o n�o existe no texto
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

