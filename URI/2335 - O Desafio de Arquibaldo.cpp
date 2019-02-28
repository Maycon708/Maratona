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
	
	ll l1, l2;
	
	while( scanf("%lld%lld", &l1, &l2 ) != EOF ){
		if( l2 > l1 ) swap( l2, l1 );
		double x = (-l2+sqrt(l2*l2-2*(l2*l2-l1*l1)))/2.0;
		if( fabs(x) < 1e-9 ){
			puts("Nao existe tal triangulo.");
			continue;
		}
		x = (l2+x)/l1;
		x = acos(x);
		x = (x*180)/acos(-1);
		
		if( fabs(x) < 1 ){
			puts("Nao existe tal triangulo.");
		}
		else printf("%d\n", (int) x );
	}
	
}