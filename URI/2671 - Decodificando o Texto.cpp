#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int L[N], R[N], n, p;
char text[N], ans[N], tmp[N];

void build(){
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		cnt++;
		L[u] = R[u] = -1;
		if( cnt >= n ) continue;
		L[u] = 2*u;
		q.push(L[u]);
		cnt++;
		if( cnt >= n ) continue;
		R[u] = 2 * u + 1;
		q.push(R[u]);
	}
}

void dfs( int u ){
	if( L[u] != -1 ) dfs(L[u]);
	tmp[u] = text[p++];
	if( R[u] != -1 ) dfs(R[u]);
}

void bfs(){
	queue<int> q;
	q.push(1);
	p = 0;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		ans[p++] = tmp[u];
		if( L[u] != -1 ) q.push(L[u]);
		if( R[u] != -1 ) q.push(R[u]);
	}
	ans[p++] = '\0';
}

int main(){
	while( scanf("%d", &n ) != EOF && n ){
		gets(text);
		gets(text);
		p = 0;
		build();
		dfs(1);
		bfs();
		printf("%s\n", ans );
	}
}
