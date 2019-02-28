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
	int n;
	while( scanf("%d", &n ) != EOF ){
		int lim = 2*sqrt(n);
		int ans = (1+n)*2;
		rep( i, 1, 1020 ){
			rep( j, 1, 1020 ){
				if( i*j > n ) break;
				int t = (i+j)*2;
				int s = n - i * j;
				if( s > i && s > j ) continue;
				if( s ) t += 2;
				ans = min( ans, t ); 
			}
		}
		printf("%d\n", ans );
	}
}
