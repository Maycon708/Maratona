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

#define gc getchar//_unlocked

const int mod = 1000000007;

inline bool scan( ll &x ){
	char aux[1111];
	x = 0;
	if( scanf("%s", aux ) != EOF ){
		int t = strlen(aux);
		rep( i, 0, t ){
			x *= 26;
			x += ( aux[i] - 'A' );
			x %= mod;
		}
		return 1;
	}
	return 0;
}

int main(){
	ll n;
	while( scan(n) ){
		printf("%lld\n", n );
	}
}

