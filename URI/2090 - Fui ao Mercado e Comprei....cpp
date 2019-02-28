#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){

	ll n, m, T;
	while( scanf("%lld%lld", &n, &m ) != EOF ){
		if( !n && !m ) break;
		vector < string > v;
		rep( i, 0, n ){
			string s;
			cin >> s;
			v.pb( s );
		}
		ll resp = 0;
		rep( i, 1, 1000000 ){
			resp += i;
			if( resp >= m ){
				resp -= i;
				break;
			}
		}
		printf("%s\n", v[m-resp-1].c_str() );
	}

}

