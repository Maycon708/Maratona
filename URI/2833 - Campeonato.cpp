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
	int a, b;
	int k;
	rep( i, 0, 16 ){
		scanf("%d", &k );
		if( k == 1 ) a = i;
		else if( k == 9 ) b = i;
	}
	
	if( a/2 == b/2 ) puts("oitavas");
	else if( a/4 == b/4 ) puts("quartas");
	else if( a/8 == b/8 ) puts("semifinal");
	else puts("final");
}
