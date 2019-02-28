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
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int MAXN = 2500, cc = 256;

int sig[MAXN][cc], term[MAXN], T[MAXN], cnt;

inline int C( char c ){
	return int(c);
}

void add( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = C( s[i] );
		if( !sig[x][c] ){
			term[cnt] = 0;
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
	}
	term[x] = 1;
}

void aho(){
	queue <int> q;
	rep( i, 0, cc ){
		int x = sig[0][i];
		if( !x ) continue;
		q.push( x );
		T[x] = 0;
	}
	while( !q.empty() ){
		int u = q.front(); 
		q.pop();
		rep( i, 0, cc ){
			int v = sig[u][i];
			if( !v ) continue;
			int w = T[u];
			while( w && !sig[w][i] ) w = T[w];
			w = sig[w][i];
			T[v] = w;
			term[v] |= term[w];
			q.push(v);
		}
	}
}

int busca( string s ){
	int x = 0, cont = 0;
	rep( i, 0, s.size() ){
		int c = C( s[i] );
		while( x && !sig[x][c] ) 
			x = T[x];
		x = sig[x][c];
		if( term[x] ){
			cont++, x = 0;
		}
	}
	return cont;
}

int main(){
	int n, m;
	string s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		memset( sig, 0, sizeof sig );
		cnt = 1;
		getchar();
		rep( i, 0, n ){
			getline( cin, s);
			add( s );
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

