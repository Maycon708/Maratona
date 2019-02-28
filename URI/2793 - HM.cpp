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
	
	char c;
	const int mod = 1e9+7;
	ll cnt = 0, e = -1, ans = 1, b = 2;
	while( scanf("%c", &c ) != EOF ){
		if( c == 'M') cnt++;
		else cnt--;
		if( !cnt ) e++;
	}
	while(e){
		if(e&1) ans = ( ans * b )%mod;
		b = (b*b)%mod;
		e >>= 1;
	}	
	printf("%lld\n", ans );
}
