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

bool check( int x, int y ){
	int bx[] = { 1, 2, 2, 5 }, by[] = { 3, 3, 5, 4 };
	rep( i, 0, 4 ) if( x == bx[i] && y == by[i] ) return 1;
	return 0;
}

int main(){
	int n, u;
	while( cin >> n ){
		int cnt = 0;
		int x = 4, y = 3;
		int dx[] = { 0, 1, 2,  2,  1, -1, -2, -2, -1 };
		int dy[] = { 0, 2, 1, -1, -2, -2, -1,  1,  2 };
		rep( i, 0, n ){
			cin >> u;
			x += dx[u], y += dy[u], cnt++;
			if( check( x, y ) ) break;
		}
		rep( i, cnt, n ) cin >> u;
		printf("%d\n", cnt );
	}
}

