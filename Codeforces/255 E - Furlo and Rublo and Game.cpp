#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 1000001;

map<ll, ll> mp[N];
ll g[N];

ll grundy( ll u ){
	ll a = sqrt(u);
	ll b = sqrt(a);
	while( b*b*b*b < u ) b++;
	int ans = 0;
	while( b <= a && mp[a][ans] != mp[b-1][ans] ) ans++;
	
	return ans;
}

int main(){
	ll n, aux;
	
	mp[0][0] = 1; mp[1][0] = 2;
	g[0] = g[1] = 0;
	for( int i = 2; i < N; i++ ){
		aux = grundy(i);
		mp[i] = mp[i-1]; mp[i][aux]++; 
		g[i] = aux;
	}
	
	while( scanf("%I64d", &n ) != EOF ){
		ll ans = 0;
		rep( i, 0, n ){
			scanf("%I64d", &aux );
			if( aux < N ) ans ^= g[aux];
			else ans ^= grundy(aux);
		}
		if( !ans ) puts("Rublo");
		else puts("Furlo");
	}
}
