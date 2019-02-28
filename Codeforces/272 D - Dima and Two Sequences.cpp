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

int n, m, a[100100], b[100100];
ll fat[200100], pot[200100], cnt[200100];

int main(){
	
	scanf("%d", &n );
	rep( i, 0, n ) scanf("%d", &a[i] );
	rep( i, 0, n ) scanf("%d", &b[i] );
	scanf("%d", &m );
	
	fat[0] = 1;
	cnt[0] = 0;
	pot[0] = 1;
	rep( i, 1, 200100 ){
		cnt[i] = cnt[i-1];
		int x = i;
		while( x%2 == 0 ) cnt[i]++, x /= 2;
		fat[i] = ( fat[i-1] * x )%m;
		pot[i] = ( pot[i-1] * 2 )%m;
	}
	
	int exp = 0;
	map<int, int> mp;
	ll ans = 1;
	
	rep( i, 0, n ){
		mp[a[i]]++;
		mp[b[i]]++;
		if( a[i] == b[i] ) exp--; 
	}
	for( auto x : mp ){
		ans = ( ans * fat[x.S] )%m;
		exp += cnt[x.S];
		
	}
	
	ans = ( ans * pot[exp] )%m;
	cout << ans << endl;
}
