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

const int MAX = 100010;

struct trie{
	int sig[MAX][26], term[MAX];
	int cnt;
	
	void clear(){
		memset( sig[0], 0, sizeof sig[0] );
		cnt = 1;
	}
	void add( string s ){
		int x = 0;
		rep( i, 0, s.size() ){
			int c = s[i] - 'a';
			if( !sig[x][c] ){
				term[cnt] = 0;
				memset( sig[cnt], 0, sizeof sig[cnt] );
				sig[x][c] = cnt++;
			}
			x = sig[x][c];
		}
		term[x] = 1;
	}
};

trie suffix, prefix;
int start[26];

void dfs_suffix( int u, int depth ){
	rep( i, 0, 26 ){
		if( !suffix.sig[u][i] ) continue;
		if( depth ){
			start[i]++;
		}
		dfs_suffix( suffix.sig[u][i], depth+1 );
	}
}

ll dfs_prefix( int u, int depth ){
	ll ans = (depth) ? suffix.cnt-1 : 0;
	rep( i, 0, 26 ){
		if( !prefix.sig[u][i] ) continue;
		if( depth ){
			ans -= start[i];
		}
		ans += dfs_prefix( prefix.sig[u][i], depth+1 );
	}
	return ans;
}

int main(){
	int n, m;
	string s;
	while( scanf("%d%d", &n, &m ) != EOF && n+m ){
		prefix.clear(), suffix.clear();
		memset( start, 0, sizeof start );
		rep( i, 0, n ){
			cin >> s;
			prefix.add(s);
		}
		rep( i, 0, m ){
			cin >> s;
			reverse( all(s) );
			suffix.add(s);
		}
		dfs_suffix( 0, 0 );
		ll ans = dfs_prefix( 0, 0 );
		printf("%lld\n", ans );
	}
}

