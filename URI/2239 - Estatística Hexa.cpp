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

const int mod = 0x3b9aca07;

int n, tam[300];
ll fat[20];
char s[300][30];

struct Q{
	ll h, l, s, m;
	Q(){};
	Q( ll _l, ll _h, ll _s ){
		h = _h, l = _l, s = _s;
	}
	void init(){
		h = s = m = 0;
		l = 1LL << 60;
	}
	void cmp( Q a ){
		if( h < a.h ) h = a.h;
		if( l > a.l ) l = a.l;
		s = ( s + a.s );
		if( s >= mod ) s %= mod;
		m = 1;
	}
};

Q pd[1<<16];

inline int C( char c ){
	if( isdigit(c) ) return c - '0';
	return c - 'a' + 10;
}

Q solve( int mask ){
	int k = __builtin_popcount(mask);
	if( k == 16 ) return Q(0, 0, 0);
	if( pd[mask].m ) return pd[mask];
	Q ans = Q( 1LL << 60, 0, 0 );
	ll t = 0, aux, a2, t2 = 0;
	rep( i, 0, n ){
		aux = 0, a2 = 0;
		rep( j, 0, tam[i] ){
			int u = C( s[i][j] );
			if( mask & ( 1 << u ) ) continue;
			aux = ( aux << 4 ) + u;
		}
		t += aux;
	}
	t2 = t%mod;
	t2 = ( t2 * fat[16-k] )%mod;
	ans.s = t2;
	rep( i, 0, 16 ){
		if( mask & ( 1 << i ) ) continue;
		Q aux = solve( mask | ( 1 << i ) );
		ans.cmp( Q( aux.l + t, aux.h + t, aux.s ) );
	}
	return pd[mask] = ans;
}

int main(){
	fat[0] = 1;
	rep( i, 1, 20 ) fat[i] = ( fat[i-1] * i )%mod;
	while( scanf("%x", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%s", s[i] );
			tam[i] = strlen( s[i] );
		}
//		rep( i, 0, 1 << 16 ) pd[i].init();
		Q ans = Q( 1LL << 60, 0, 0 );
		rep( i, 0, 16 ){
			ans.cmp( solve( 1 << i ) );
		}
		printf("%llx %llx %llx\n", ans.l, ans.h, ans.s );
	}
}
/*
1
fffffffff
3
9af47c0b
2545557
ff6447979
*/
