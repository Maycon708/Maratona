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
	ll t, a, b;
	scanf("%I64d", &t );
	while( t-- ){
		scanf("%I64d%I64d", &a, &b );
		if( !b ) printf("1.00\n");
		else if( !a ) printf("0.500\n");
		else{
			double at = a*b*2;
			double ap = a*b;
			if( 4*b >= a ) ap += (a/4.0)*a/2.0;
			else ap += 2*b*b + (a-4*b)*b;
			printf("%.10f\n", ap/at );
		}
	}
}
