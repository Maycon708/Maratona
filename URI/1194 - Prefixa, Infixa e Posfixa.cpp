#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

struct tree{
	char v;
	int l, r;
	void clear(){
		l = r = 0; v = '*';
	}
};

int val[100], cnt;

tree T[100];

inline int C( char a ){
	if( a >= 'A' && a <= 'Z' ) return a - 'A';
	return a - 'a';
}

inline bool cmp( char a, char b ){
	int aa = C(a), bb = C(b);
	return val[aa] < val[bb];
}

void build( int no, char s ){
	if( T[no].v == '*' ){
		T[no].v = s;
		return;
	}
	if( cmp( s, T[no].v ) ){
		if( !T[no].l ) T[no].l = cnt, T[cnt++].clear();
		build( T[no].l, s );
	}
	else{
		if( !T[no].r ) T[no].r = cnt, T[cnt++].clear();
		build( T[no].r, s );
	}
}

void posfixo( int no ){
	if( T[no].l ) posfixo( T[no].l );
	if( T[no].r ) posfixo( T[no].r );
	printf("%c", T[no].v );
}

int main(){
	
	char pre[30], inf[30];
	int t, tam;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%s%s", &tam, pre, inf );
		cnt = 1; T[0].clear();
		
		rep( i, 0, tam ){
			int u = C( inf[i] );
			val[u] = i;
		}
		
		rep( i, 0, tam ) build( 0, pre[i] );
		
		posfixo( 0 );
		printf("\n");
	}
	
}

