#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
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

#define MAX 200000
#define cc 26

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

struct state{
	int len, link;
	map< int, int > next;
};

state st[2*MAX];	  //vetor que armazena os estados
int sz; 			 //contador do número de estados
int last; 			//número do estado que corresponde ao texto todo

void sa_init(){
	sz = 1;
	last = 0;
	st[0].len = 0;
	st[0].link = -1;
	st[0].next.clear(); //limpa o mapeamento de transições
}

int l;
ll ret;

void sa_extend( int c ){
	int cur = sz++; 				// novo estado a ser criado
	st[cur].len = st[last].len + 1;
	st[cur].next.clear();
	int p; 							// variável que itera sobre os estados terminais
	for( p = last; p != -1 && !st[p].next.count(c); p = st[p].link ){
		st[p].next[c] = cur;
	}
	if(p == -1){					// não ocorreu transição c nos estados terminais
		st[cur].link = 0;
	}
	else{ 							// ocorreu transição c no estado p
		int q = st[p].next[c];
		if( st[p].len + 1 == st[q].len ) st[cur].link = q;
		else{
			int clone = sz++; 		// criação do vértice clone de q
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for(; p != -1 && st[p].next[c] == q; p = st[p].link ){// atualização das transições 
				st[p].next[c] = clone;
			}
			st[q].link = st[cur].link = clone;
		}
	}								// atualização do estado que corresponde ao texto
	last = cur;
	ret += st[cur].len - st[ st[cur].link ].len; 
}

int main(){
	
	string s;
	while( getline( cin, s ) ){

		ret = 0; l = 1;
		sa_init();
		
		rep( i, 0, s.size() ){
			if( s[i] >= 'a' && s[i] <= 'z' )
				sa_extend( s[i]-'a' );
			else{
				printf("%llu\n", ret ); 
			}
		}
	}
}
