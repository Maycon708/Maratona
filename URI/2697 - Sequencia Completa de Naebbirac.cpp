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
	
	int k, n, v, cnt[1111];
	
	while( scanf("%d%d", &k, &n ) != EOF ){
		memset( cnt, 0, sizeof cnt );
		rep( i, 0, n ){
			scanf("%d", &v );
			cnt[v]++;
		}
		int x = (n+1)/k;
		int s = 0, f = 0, si, fi;
		rep( i, 1, k+1 ){
			if( cnt[i] > x ) s += cnt[i]-x, si = i;
			if( cnt[i] < x ) f += x-cnt[i], fi = i;
		}
		if( s == 1 && f == 1 ) printf("-%d +%d\n", si, fi );
		else if( s == 1 && !f ) printf("-%d\n", si );
		else if( f == 1 && !s ) printf("+%d\n", fi );
		else puts("*");
	}
	
}
