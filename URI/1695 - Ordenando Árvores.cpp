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

vector<int> adj[100100];
vector<ii>  q[100100];
int mx, maior[100100], v[100100], bit[100100], st[100100], ans[100100];

void dfs( int u, int p ){
    maior[u] = 0;
	st[u] = 1;
	int aux = 0;
    rep( i, 0, adj[u].size() ){
        int v = adj[u][i];
        if( p == v ) continue;
        dfs( v, u );
        st[u] += st[v];
        if( st[v] > aux ){
        	aux = st[v];
        	maior[u] = v;
		}
    }
}

void update( int x, int v ){
    for( ; x <= mx; x += (x&-x) ) bit[x] += v;
}

int query( int x ){
    int ans = 0;
    for( ; x > 0; x -= (x&-x) ) ans += bit[x];
    return ans;
}

void dfs_update( int u, int p, int valor ){
    update( v[u], valor );
    rep( i, 0, adj[u].size() ){
        int v = adj[u][i];
        if( v == p ) continue;
        dfs_update(v, u, valor);
    }
}

int bb( int k ){
	int lo = 1, hi = mx;
	while( lo != hi ){
		int mid = (lo+hi)/2;
		int aux = query(mid);
		if( aux >= k ) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

void solve( int u, int p ){
    rep( i, 0, adj[u].size() ){
        int v = adj[u][i];
        if( v == p || v == maior[u] ) continue;
        solve( v, u );
        dfs_update( v, u, -1 );
    }
    if( maior[u] ) solve( maior[u], u );
    update( v[u], 1 );
    rep( i, 0, adj[u].size() ){
        int v = adj[u][i];
        if( v == p || v == maior[u] ) continue;
        dfs_update( v, u, +1 );
    }
    rep( i, 0, q[u].size() ){
    	int k = q[u][i].F;
    	int id = q[u][i].S;
    	ans[id] = bb(k);
	}
}

int main(){
    
    int t, aux[100100], mp[100100], n, m, a, b, x, k;
    scanf("%d", &t );
    while( t-- ){
        scanf("%d%d", &n, &m );
        
        rep( i, 0, 100100 ) adj[i].clear(), q[i].clear(), bit[i] = st[i] = ans[i] = maior[i] = 0;
        rep( i, 0, n ) scanf("%d", &v[i] ), aux[i] = v[i], adj[i].clear();
        
        sort( aux, aux+n );
        mx = unique( aux, aux+n ) - aux+1;
        rep( i, 0, n ){
            int x = lower_bound( aux, aux+n, v[i] ) - aux + 1;
            mp[x] = v[i];
            v[i] = x;
        }
        
        rep( i, 1, n ){
            scanf("%d%d", &a, &b );
            a--, b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs( 0, 0 );
        
        rep( i, 0, m ){
            scanf("%d%d", &x, &k );
            x--;
            q[x].pb( ii(k, i) );
        }
        solve( 0, 0 );
        
        rep( i, 0, m ) printf("%d ", mp[ans[i]] );   
        printf("\n");
    }
}


