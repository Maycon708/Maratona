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

int main(){
	ll n, aux;
	while( scanf("%lld", &n ) != EOF ){
		map<ll, ll> mp;
		vector<ll> v;
		rep( i, 0, n ){
			scanf("%lld", &aux );
			if( !mp.count(aux) ) v.pb(aux);
			mp[aux]++;
		}
		sort( all(v) );
		n = v.size()-1;
		if( !n ){
			printf("0 %lld\n", mp[v[n]] * (mp[v[n]]-1)/2 );
			continue;
		}
		printf("%lld %lld\n", v[n] - v[0], mp[v[0]] * mp[v[n]] );
	}
}

