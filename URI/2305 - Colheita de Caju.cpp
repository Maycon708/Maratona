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

int sum[1000][1000];

int main(){
	int n, m, l, c;
	while( scanf("%d%d%d%d", &n, &m, &l, &c ) != EOF ){
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf("%d", &sum[i][j] );
				if( i ) sum[i][j] += sum[i-1][j];
				if( j ) sum[i][j] += sum[i][j-1];
				if( i && j ) sum[i][j] -= sum[i-1][j-1];
			}
		}
		int ans = 0;
		rep( i, 0, n-l+1 ){
			rep( j, 0, m-c+1 ){
				int x = i + l -1;
				int y = j + c -1;
				int t = sum[x][y];
				if( i ) t -= sum[i-1][y];
				if( j ) t -= sum[x][j-1];
				if( i && j ) t += sum[i-1][j-1];
				ans = max( ans, t );
			}
		}
		printf("%d\n", ans );
	}
}

