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
	ll pot[70], k;
	ll t;
	rep( i, 0, 63 ) pot[i] = ( 1LL << i );
	while( scanf("%lld%lld", &t, &k ) != EOF ){
		vector<ll> ans;
		for( int i = 62; k && i >= 0; i-- ){
			while( t >= pot[i] && t - pot[i] >= ( k-1 ) && k ){
				ans.pb( pot[i] );
				k--;
				t -= pot[i]; 
			}
		}
		ans[0] += t;
		rep( i, 0, ans.size() ){
			printf("%lld%s", ans[i], i+1 == ans.size() ? "\n" : " " );
		}
	}
}

