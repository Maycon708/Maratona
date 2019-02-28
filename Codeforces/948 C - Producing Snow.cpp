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
#define N 100100
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll bit[N];

void update( int x, int v ){
	for( int i = x; i < N; i += (i&-i) ) bit[i] += v;
}

ll query( int x ){
	ll ans = 0;
	for( int i = x; i > 0; i -= (i&-i) ) ans += bit[i];
	return ans;
}

int n;
ll v[N], a[N], sum[N], ans[N];

int main(){
	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, N ){
			bit[i] = ans[i] = 0;
		}
		rep( i, 1, n+1 ){
			scanf("%lld", &v[i] );
		}
		sum[0] = 0;
		rep( i, 1, n+1 ){
			scanf("%lld", &a[i] );
			sum[i] = a[i] + sum[i-1];
		}
		rep( i, 1, n+1 ){
			int p = upper_bound( sum, sum+n+1, v[i] + sum[i-1] ) - sum;
			update(i, 1);
			update(p, -1);
			ans[p] += ( v[i] - sum[p-1] + sum[i-1] ); 
			int aa = query(i);
			printf("%lld%s", aa*a[i] + ans[i], i==n? "\n":" " );
		}		
	}
	
}
