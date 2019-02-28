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
	
	ll v[20], aux[20];
	
	rep( i, 0, 14 ) cin >> v[i];
	ll ans = 0;
	rep( i, 0, 14 ){
		if( v[i] <= 0 ) continue;
		int rest = v[i]%14;
		int t = v[i]/14;
		rep( j, 0, 14 ) aux[j] = v[j];
		aux[i] = 0;
		rep( j, 0, 14 ) aux[j] += t;
		rep( j, 1, rest+1 ) aux[(i+j)%14]++;
		ll tt = 0;
	//	rep( j, 0, 14 ) printf("%d ", aux[j] ); printf("\n");
		rep(j, 0, 14 ) if( aux[j]%2 == 0 ) tt += aux[j];
		ans = max( ans, tt );
	}
	cout << ans << endl;
	
}
