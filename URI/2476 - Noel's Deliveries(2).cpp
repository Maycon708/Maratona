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
#define maxn 100010
#define maxl 20
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

vector<int> E[maxn];
int pai[maxn];
int depth[maxn];
int s[maxn];
bool vis[maxn];
map<string,int> mp;

void dfs( int u, int p, int d ){
	if( vis[u] ) return;
	vis[u] = 1;
	pai[u] = p;
	depth[u] = d;
	rep( i, 0, E[u].size() ){
		int v = E[u][i];
		dfs( v, u, d+1 );
	}
}

int solve( int a, int b ){
	set<int> st;
	st.insert( s[a] );
	st.insert( s[b] );
	 
	if( depth[a] > depth[b] ) swap( a, b );
	while( depth[a] != depth[b] ){
		b = pai[b];
		st.insert( s[b] );
	}
	while( a != b ){
		a = pai[a], b = pai[b];
		st.insert( s[a] );
		st.insert( s[b] );
	}
	return st.size();
}

int main(){
	
	int n, q, a, b;
	string S;
	while( scanf("%d%d", &n, &q ) != EOF ){
		int cnt = 0;
		mp.clear();
		rep( i, 1, n+1 ){
			cin >> S;
			if( mp.count(S) == 0 ) mp[S] = cnt++;
			s[i] = mp[S];
			E[i].clear();
		}
		
		rep( i, 0, n-1 ){
			scanf("%d%d", &a, &b );
			E[a].pb(b);
			E[b].pb(a);
		}
		dfs( 1, -1, 0 );
		while( q-- ){
			scanf("%d%d", &a, &b );
			printf("%d\n", solve( a, b ) );
		}
		break;
	}
}

