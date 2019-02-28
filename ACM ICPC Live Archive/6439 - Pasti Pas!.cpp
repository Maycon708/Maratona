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
#define MAX 50010
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const ll x = 33, mod = 1e9+7;
ll H[MAX], X[MAX];

inline int C( char c ){
	return c - 'A' + 1;
}

void precomp( string s ){
	H[0] = 0, X[0] = 1;
	s = "$" + s;
	rep( i, 1, s.size()+1 ){
		H[i] = H[i-1] * x + C( s[i] );
		H[i] %= mod;
		X[i] = ( X[i-1] * x )%mod;
	}
}

inline ll Hash( int i, int j ){
	ll ans = ( ( H[j] - ( H[i-1] * X[ j-i+1 ] )%mod ) + mod ) %mod;
	return ans;
}

int solve( int i, int l ){
	int cont = 0;
	int j = i, k = l, aux = 0;
	while( j <= k ){
		if( Hash( i, j ) == Hash( k, l ) ){
			if( j == k ) cont++;
			else cont+=2;
			aux = 0;
			j++, k--;
			i = j, l = k;
		}
		else{
			aux = 1;
			j++, k--;
		}
	}
	if( aux ) cont++;
	return cont;
}

int main(){
	char s[MAX];
	int T;
	scanf("%d", &T );
	rep( t, 1, T+1 ){
		scanf("%s", s );
		precomp( s );
		printf("Case #%d: %d\n", t, solve( 1, strlen( s ) ) );
	}

}

