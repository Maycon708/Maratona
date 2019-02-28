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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll pot[19];
int vis[30][200200];

ll bfs( ll u, int k ){
	priority_queue<ii, vector<ii>, greater<ii> > q;
	vector<ll> ans;
	q.push(ii(log10(u)+1, u ));
	while( !q.empty() ){
		u = q.top().S;
		int x = q.top().F;
		q.pop();
		if( vis[x][u%k] || x == 18 ) continue;
		vis[x][u%k] = 1;
		if( u%k == 0 ) return u;
		if( ans.empty() ){
			rep( i, 0, 10 ){
				ll v = u*10+i;
				q.push(ii(x+1, v));
				v = i*pot[x]+u;
				q.push(ii(x+1, v));
			}
		}
	}
}

int main(){
	pot[0] = 1;
	rep( i, 1, 19 ){
		pot[i] = pot[i-1] * 10;
	}
	ll n, k;
	scanf("%lld%lld", &n, &k);
	cout << bfs(n, k) << endl;
	
}
