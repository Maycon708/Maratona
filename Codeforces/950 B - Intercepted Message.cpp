#include <bits/stdc++.h>

#define INF 200*18+10
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
	
	int n[2];
	int v[2][100010];
	
	while( scanf("%d%d", &n[0], &n[1] ) != EOF ){
		rep( i, 0, 2 ){
			rep( j, 0, n[i] ){
				scanf("%d", &v[i][j] );
			}
		}
		int a = 0, b = 0, j = 0, cnt = 0;
		rep( i, 0, n[0] ){
			a += v[0][i];
			while( b < a && j < n[1] ){
				b += v[1][j++];
			}
			if( a == b ) cnt++;
		}
		printf("%d\n", cnt );
	}
	
}