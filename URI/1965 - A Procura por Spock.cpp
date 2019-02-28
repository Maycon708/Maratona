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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int n, v, last, l, r, aux;
	long double d, p;
	char s[11];
	
	while( scanf("%d%LF%LF", &n, &d, &p ) != EOF ){
		l = r = 0;
		aux = -1;
		scanf("%d", &last );
		rep( i, 1, n ){
			scanf("%d", &v );
			if( v > last && aux != 0 ) r++, aux = 0;
			if( v < last && aux != 1 ) l++, aux = 1;
			last = v;
		}
		scanf("%s", s );
		if( strcmp(s, "<)") == 0 ) p -= r*d;
		else if( strcmp(s, "(>") == 0 ) p -= l*d;
		long double ans = p/(r+l);
		if( strcmp(s, "<)") == 0 ) printf("<) %d R$%.2LF\n(> %d R$%.2LF\n", r, ans + d, l, ans );
		else if( strcmp(s, "(>") == 0 )	printf("<) %d R$%.2LF\n(> %d R$%.2LF\n", r, ans, l, ans+d );
	}
}
