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

int n, k, x[1001], y[1001];
set<int> st;

void dfs( int u ){
	if( st.count(u) ) return;
	st.insert(u);
	rep( i, 0, n ){
		if( i == u ) continue;
		int dx = x[i] - x[u];
		int dy = y[i] - y[u];
		int d = dx*dx + dy*dy;
		if( d <= k ) dfs(i);
	}
}

int main(){
	while( cin >> n >> k ){
		k *= k;
		st.clear();
		rep( i, 0, n )	cin >> x[i] >> y[i];
		dfs(0);
		if( st.size() == n ) printf("S\n");
		else printf("N\n");
	}
}

