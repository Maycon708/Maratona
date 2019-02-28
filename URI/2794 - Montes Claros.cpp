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

bool cmp( ii a, ii b ){
	return a.first < b.first;
}

int main(){
	int n;
	ii v[5050];
	scanf("%d", &n );
	rep( i, 0, n ) scanf("%d%d", &v[i].first, &v[i].second );
	sort( v, v+n );
	bool aux = 1;
	rep( i, 0, n-1 ) aux &= ( v[i].second > v[i+1].second );
	printf("%c\n", aux? 'S' : 'N' );	 
}
