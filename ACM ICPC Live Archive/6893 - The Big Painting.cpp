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

const ll x = 37, mod = 1e9+7;
ll H[MAX], X[MAX], P[MAX];
vector<int> pattern, text[2017];

inline int C( char c ){
	return c - 'a' + 1;
}

ll precomp( string s ){
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

void pre_process( ){
	P[0] = 0;
	int j = 0;
	rep( i, 1, pattern.size() ){
		while( j > 0 && pattern[j] != pattern[i] ) j = P[j-1];
		if( pattern[j] == pattern[i] ) j++;
		P[i] = j;
	}
}

inline int KMP( int id ){
	int j = 0, aux = 0;
	rep( i, 0, text[id].size() ){
		while( j > 0 && pattern[j] != text[id][i] ) j = P[j-1];
		if( pattern[j] == text[id][i] ){
			j++;
			if( j == pattern.size() ){
				aux++;
				j = P[j-1];
			}
		}
	}
	return aux;
}

int main(){
	int hp, wp, hm, wm;
	char s[MAX];
	while( scanf("%d%d%d%d", &hp, &wp, &hm, &wm ) != EOF ){
		pattern.clear();
		rep( i, 0, hp ){
			scanf("%s", s );
			precomp(s);
			pattern.pb(Hash(1, wp));
		}
		pre_process();
		rep( i, 0, hm ){
			scanf("%s", s );
			precomp(s);
			for( int j = 1; j <= wm-wp+1; j++ ){
				int aux = Hash( j, j+wp-1 );
				text[j].pb(aux);
			}
		}
		int ans = 0;
		for( int j = 1; j <= wm-wp+1; j++ ) ans += KMP(j), text[j].clear();
		printf("%d\n", ans );
	}
}

