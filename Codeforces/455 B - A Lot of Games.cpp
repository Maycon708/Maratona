#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int sig[100010][26], cnt;
bool l[100010], v[100010];

void add( string s ){
	int x = 0;
	rep( i, 0, s.size() ){
		int c = s[i] - 'a';
		if( !sig[x][c] ){
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
	}
}

void dfs( int u ){
	l[u] = v[u] = 0;
	bool check = 1;
	rep( i, 0, 26 ){
		int x = sig[u][i];
		if( !x ) continue;
		check = 0;
		dfs( x );
		l[u] |= !l[x];
		v[u] |= !v[x];
	}
	if( check ) l[u] = 1;
}

int main(){
	
	int n, m;
	string s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		cnt = 1;
		memset( sig, 0, sizeof sig );
		rep( i, 0, n ){
			cin >> s;
			add(s);
		}
		dfs(0);
		if( !v[0] ) puts("Second");
		else if( l[0] ) puts("First");
		else if( m&1 ) puts("First");
		else puts("Second");
	}

}
