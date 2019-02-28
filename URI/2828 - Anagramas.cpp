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

const int mod = 1e9+7;

ll fastExp( ll b, ll e ){
	ll ans = 1;
	for(; e; e >>= 1 ){
		if( e&1 ) ans = ( ans * b )%mod;
		b = ( b * b )%mod;
	}
	return ans;
}

int main(){
	char s[100100];
	int t;
	ll fat[100100], cont[30];
	fat[0] = 1;
	
	rep( i, 0, 26 ) cont[i] = 0;
	scanf("%s", s );
	t = strlen(s);
	rep( i, 0, t ){
		cont[s[i]-'a']++; 
		if( i ) fat[i] = ( fat[i-1] * i )%mod;
	}
	fat[t] = (fat[t-1]*t)%mod;
	ll ans = fat[t];
	rep( i, 0, 26 ) if( cont[i]) ans = ( ans * fastExp( fat[cont[i]], mod-2 ))%mod;
	printf("%lld\n", ans );
}
