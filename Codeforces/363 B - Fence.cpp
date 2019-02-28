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
	int n, k, sum[150010], v;
	while( scanf("%d%d", &n, &k ) != EOF ){
		sum[0] = 0;
		int ans = INF, id;
		rep( i, 1, n+1 ){
			scanf("%d", &v );
			sum[i] = sum[i-1]+v;
			if( i >= k && sum[i] - sum[i-k] < ans ) ans = sum[i] - sum[i-k], id = i;
		}
		printf("%d\n", id-k+1 );
	}
}

