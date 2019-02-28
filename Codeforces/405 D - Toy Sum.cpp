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

int st[1000100];

int main(){
	int n, a, par = 0;
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf("%d", &a );
		st[a] = 1;
	}
	vector<int> ans;
	rep( x, 1, 500001 ){
		int y = 1000001-x;
		if( st[x] && st[y] ) par++;
		else if( st[x] ) ans.pb(y);
		else if( st[y] ) ans.pb(x); 
	}
	rep( x, 1, 500001 ){
		int y = 1000001-x;
		if( !st[x] && !st[y] && par ) ans.pb(x), ans.pb(y), par--;
	}
	cout << ans.size() << "\n";
	for( auto x : ans ) printf("%d ", x );
}
