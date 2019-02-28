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

int main(){
	int d[7][7], n, v[100010];
	rep( i, 1, 7 ){
		rep( j, 1, 7 ) d[i][j] = 1;
		d[i][i] = 0;
		d[i][7-i] = 2;
	}
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf("%d", &v[i] );
	}
	int ans = INF;
	rep( i, 1, 7 ){
		int cnt = 0;
		rep( j, 0, n ) cnt += d[v[j]][i];
		ans = min( ans, cnt );
	}
	printf("%d\n", ans );
}
