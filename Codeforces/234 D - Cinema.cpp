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

int n, m, x, k, v[200], best[200], worst[200], used[200];
char nome[111];

int main(){
	
	freopen("input.txt", "r", stdin );
	freopen("output.txt", "w", stdout );
	
	int aux;
	scanf("%d%d", &n, &m );
	rep( i, 0, m ){
		scanf("%d", &aux );
		v[aux] = 1;
	}
	
	scanf("%d", &x );
	rep( i, 0, x ){
		scanf("%s", nome );
		scanf("%d", &k );
		int cnt = 0, fav = 0;
		memset( used, 0, sizeof used );
		rep( j, 0, k ){
			scanf("%d", &aux );
			if( !aux ) cnt++;
			else used[aux] = 1; 
			fav += v[aux];
		}
		best[i] = fav;
		worst[i] = fav+cnt;
		rep( j, 1, n+1 ){
			if( v[j] && !used[j] ) best[i]++;
			if( !v[j] && !used[j] ) worst[i]--;
		}
		worst[i] = max( worst[i], fav );
		best[i] = min( best[i], fav+cnt );
	}	
	rep( i, 0, x ){
		int status = 0;
		rep( j, 0, x ){
			if( i == j ) continue;
			if( worst[i] < best[j] && !status ) status = 2;
			if( best[i] < worst[j] ) status = 1;
		}
		printf("%d\n", status ); 
	}
}
