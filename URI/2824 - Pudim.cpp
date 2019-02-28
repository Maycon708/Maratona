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

int pd[5005][5005], n, m;
char s1[5005], s2[5005];

int solve( int i, int j ){
	if( i == n || j == m ) return 0;
	int &ans = pd[i][j];
	if( ans == -1 ){
		ans = max( solve(i+1, j), solve(i, j+1) );
		if( s1[i] == s2[j] ) ans = max( ans, 1+solve(i+1, j+1) );
	}
	return ans;
}

int main(){
	scanf("%s", s1 );
	scanf("%s", s2 );
	n = strlen(s1);
	m = strlen(s2);
	memset(pd, -1, sizeof pd );
	printf("%d\n", solve(0, 0) );
}
