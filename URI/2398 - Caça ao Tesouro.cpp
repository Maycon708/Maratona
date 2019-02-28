#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int n;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int cnt[210][210];
bool vis[210][210];

bool dentro( int x, int y ){
	return x >= 0 && x < n && y >= 0 && y < n;
}

void propagate( int x, int y, int k ){
	queue<pair<ii, int> > q;
	q.push( mk( ii( x, y ), k ));
	memset( vis, 0, sizeof vis );
	while( !q.empty() ){
		int x = q.front().F.F;
		int y = q.front().F.S;
		int k = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		if( !k ) cnt[x][y]++;
		else{
			rep( i, 0, 4 ){
				int xx = x + dx[i], yy = y + dy[i];
				if( dentro( xx, yy ) ) q.push( mk( ii( xx, yy ), k-1 )); 
			}
		}
	}	
}

int main(){
	int m, x, y, k;
	while( cin >> n >> m ){
		memset( cnt, 0, sizeof cnt );
		rep( i, 0, m ){
			cin >> x >> y >> k;
			propagate( x, y, k );
		}
		k = 0;
		rep( i, 0, n ){
			rep( j, 0, n ){
				if( cnt[i][j] == m ) x = i, y = j, k++;
			}
		}
		if( k > 1 ) printf("-1 -1\n");
		else printf("%d %d\n", x, y );
	}
}

