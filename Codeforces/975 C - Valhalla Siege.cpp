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
#define N 250000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int n, q;
	ll sum[N], shoot;
	while( scanf("%d%d", &n, &q ) != EOF ){
		sum[0] = 0;
		FOR( i, 1, n ){
			cin >> sum[i];
			sum[i] += sum[i-1];
		}
		int id = 1;
		ll at = 0;
		while( q-- ){
			cin >> shoot;
			ll d = shoot + at + sum[id-1];
			int p = lower_bound( sum+id, sum+n+1, d ) - sum;
			if( p >= n && d >= sum[p]){
				printf("%d\n", n );
				id = 1, at = 0; 
				continue;
			}
			if( sum[p] == d ) p = (p+1)%(n+1);
			at = d - sum[p-1];
			printf("%d\n", n - p + 1 );
			id = p;
		}
	}
}
