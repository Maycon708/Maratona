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
	
	int n, k1, k2;
	int a[10100], b[10100];
	while( scanf("%d%d%d", &n, &k1, &k2 ) != EOF ){
		priority_queue<int> pq;
		rep( i, 0, n ) scanf("%d", &a[i] );
		rep( i, 0, n ) scanf("%d", &b[i] );
		rep( i, 0, n ) pq.push( abs(a[i]-b[i]));
		rep( i, 0, k1+k2 ){
			int p = pq.top();
			pq.pop();
			pq.push( abs(p-1) );
		}
		ll ans = 0;
		while( !pq.empty() ){
			ll p = pq.top();
			pq.pop();
			ans += p*p;
		}
		cout << ans << "\n";
	}
	
}
