#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int d[] = { -17, -15, -10, -6, +6, +10, +15, +17 };
vector<int> p(8);
int n;

bool valid( int h, int x ){
	int a = (h+7)%8, b = (x+7)%8;
	if( b > a + 3 || b < a - 3 ) return 0;
	return x >= 1 && x <= 64;
}

int pd[80][10][1<<10];

int solve( int h, int cnt, int mask ){
	if( mask == (1<<n)-1 ) return 0;
	int &ans = pd[h][cnt][mask];
	if( ans == -1 ){
		ans = INF;
		rep( i, 0, 8 ){
			int x = h + d[i];
			if( !valid(h,x) ) continue;
			int aux = 1, m = mask;
			rep( j, 0, n ){
				if( mask & ( 1 << j ) ) continue;
				if( p[j] + 8 * cnt == x ) m |= ( 1 << j );
				if( p[j] + 8 * (cnt+1) == x || p[j] + 8 * cnt > 64 ) aux = 0;
			}
			if( aux ){
				ans = min( ans, 1 + solve( x, cnt+1, m ) );
			}
		}
	}
	return ans;
}

int main(){
	int h;
	while( scanf("%d", &n ) != EOF && n ){
		rep( i, 0, n ) scanf("%d", &p[i] );
		scanf("%d", &h );
		memset( pd, -1, sizeof pd );
		int ans = solve(h, 0, 0);
		if( ans >= INF ) puts("impossible");
		else printf("%d\n", ans );
	}	
	
}
