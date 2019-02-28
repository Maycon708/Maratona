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

int main(){
	int n, m, k, x, cnt[100100];
	ll ans;
	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		rep( i, 0, k ) cnt[i] = 0;
		ans = 0;
		rep( i, 0, n ){
			scanf("%d", &x );
			cnt[x%k]++;
		}
		rep( i, 0, m ){
			scanf("%d", &x );
			ans += cnt[(k-x%k)%k];
		}
		printf("%lld\n", ans );
	}
}
