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

int mat[1010][1010], n, m, c, cont[1010];

bool check(){
	rep( i, 1, m ) 
		if( cont[i] && cont[i-1] ) return 0;
	rep( j, 0, m ){
		if( !cont[j] ) continue;
		int l1 = -2000, l2 = -2000;
		rep( i, 0, n ){
			if( mat[i][j] == 1 ){
				if( i - l1 <= c ) return 0;
				l1 = i;
			}
			if( mat[i][j] == 2 ){
				if( i - l2 <= c ) return 0;
				l2 = i;
			}
		}
	}
}

int main(){
	
	scanf("%d%d%d", &n, &m, &c );
	rep( i, 0, n )
		rep( j, 0, m )
			scanf("%d", &mat[i][j] ), cont[j] += mat[i][j];
	
	printf("%c\n", check()? 'S':'N' );
			
}
