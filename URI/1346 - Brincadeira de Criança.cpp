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
typedef pair <int, int> ii;

ii pd[2][402000][2];
int n;
ii v[402];

ii solve( int difM ){
	for( int i = 1; i < 402000; i++ ){
		pd[1][i][0] = pd[1][i][1] = ii(-INF, INF);
	}
	pd[1][0][0] = pd[1][0][1] = ii( 0, INF );
	
	int t = 0;
	
	for( int i = 0; i < n; i++, t ^= 1){
		int dif = v[i].S - v[i].F, sum = v[i].F + v[i].S;
		for( int j = 0; j <= difM; j++ ){
			for( int k = 0; k < 2; k++ ){
				pd[t][j][k] = max( pd[t^1][j+dif][k], pd[t^1][abs(j-dif)][k] );
				pd[t][j][k].F += sum;
				if( !k ) pd[t][j][k] = max( pd[t][j][0], ii( pd[t^1][j][1].F, i ) );
			}
		}
	}
	return pd[t^1][0][0];
}

int main(){
	//freopen("child.in.txt", "r", stdin );
	while( scanf("%d", &n ) != EOF && n ){
		int difMax = 0;
		rep( i, 0, n ){
			scanf("%d%d", &v[i].F, &v[i].S );
			if( v[i].F > v[i].S ) swap( v[i].F, v[i].S );
			difMax += v[i].S - v[i].F;
		}
		
		if( n == 1 ){
			if( v[0].F == v[0].S ) printf("%d discard none\n", v[0].F );
			else puts("impossible");
			continue;
		}
		
		
		ii ans = solve(difMax);
		if( ans.F < 0 ) puts("impossible");
		else if( ans.S >= n ) printf("%d discard none\n", ans.F/2 );
		else printf("%d discard %d %d\n", ans.F/2, v[ans.S].F, v[ans.S].S );
	}
}
