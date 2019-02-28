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

int solve( string a, string b ){
	int n = a.size(), m = b.size(), pd[111][111];
	pd[n][m] = 0;
	for( int i = n-1; i >= 0; i-- ) pd[i][m] = pd[i+1][m]+1;
	for( int i = m-1; i >= 0; i-- ) pd[n][i] = pd[n][i+1]+1;
	for( int i = n-1; i >= 0; i-- ) 
		for( int j = m-1; j >= 0; j-- ){
			pd[i][j] = min( pd[i+1][j+1] + (a[i] != b[j]), min( pd[i][j+1], pd[i+1][j])+1  ) ;
		}
		
	int ed = pd[0][0];
	return ed;
}

int main(){
	int n, m, menor, ans;
	string d[1010], r, l;
	scanf("%d", &n );
	rep( i, 0, n ) cin >> d[i];
	scanf("%d", &m );
	rep( i, 0, m ){
		cin >> l;
		menor = INF;
		rep( j, 0, n ){
			ans = solve( l, d[j] );
			if( ans < menor ){
				menor = ans;
				r = d[j];
			}
		}
		if( i ) printf(" ");
		printf("%s", r.c_str() );
	}
	printf("\n");
}
