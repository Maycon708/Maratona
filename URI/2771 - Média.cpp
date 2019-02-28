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

bool cmp( double a, double b ){
	return a > b;
}

int main(){
	
	int n, m, v[111];
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		vector<double> aux;
		rep( i, 0, n ){
			rep( j, i+1, n ){
				rep( k, j+1, n ){
					aux.pb((v[i]+v[j]+v[k])/3.0);
				}
			}
		}
		sort( all(aux), cmp );
		
		printf("%.1f\n", aux[m-1] );
	}
	
	
	return 0;
}

