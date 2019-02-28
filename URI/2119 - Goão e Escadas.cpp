#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 101000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll resp, vis[MAXV], n;
ll k, v[1001], P[MAXV], pd[1001];

const int mod = 1e9+9;

ll solve( int n ){
	if( !n ) return 1;
	if( pd[n] != -1 ) return pd[n];
	ll ans = 0;
	rep( i, 0, k ){
		if( n >= v[i] ) ans = ( ans + solve( n - v[i] ) );
		if( ans > mod ) ans %= mod;
	}
	return pd[n] = ans;
}

vector < ii > adj[MAXV];

void init( int V ){
    for( int i = 0; i <= V; i++ )
        P[i] = i, adj[i].clear();
    rep( i, 0, 1001 ) pd[i] = -1;
}

int findset( int i ){ 
    if( i != P[i] ) 
        P[i] = findset(P[i]);
    return P[i];
}
 
void unionset( int a, int b ){
    int aa = findset(a); 
    int bb = findset(b);
    P[bb] = aa; 
}

bool sameset(int a, int b){
    return findset(a) == findset(b); 
}

void dfs( int u, int menor ){
	if( vis[u] ) return;
	vis[u] = 1;
	if( u == n-1 ) resp = menor;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int c = adj[u][i].S;
		dfs( v, min( menor, c ) );
	}
	return;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}

int main(){
	
	ll mm, u, w, c;
	while( scanf("%lld", &n ) != EOF ){
		mm = readInt(); k = readInt();
		init( n );
		rep( i, 0, k ) scanf("%lld", &v[i] );
		
		vector< pair < int, ii > > pq;
		rep( i, 0, mm ){
			u = readInt(); w = readInt(); c = readInt();
			pq.pb( mk( solve(c), ii( u, w ) ) );
		}
		
		sort( all(pq) );
		
		for(int i = mm-1; i >= 0; i-- ){
			u = pq[i].S.F, w = pq[i].S.S, c = pq[i].F;
			if( !sameset( u, w ) ){
				adj[u].pb( ii( w, c ) );
				adj[w].pb( ii( u, c ) );
		        unionset( u, w );  
		    }
		}
		rep( i, 0, n+1 ) vis[i] = 0;
		dfs( 0, INF );
		printf("%lld\n", resp );
	}
}

