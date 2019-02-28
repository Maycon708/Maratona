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

int mat[1001][1001], sum, n, cnt = 0;

bool check(){
	vector<int> check( n*n+2, 0 ), sl( n, 0 ), sc(n, 0);
	rep( i, 0, n ){
		rep( j, 0, n ){
			int u = mat[i][j];
			if( u > n*n || check[u] == 1 || u < 1 ) return 0;
			check[u] = 1;
			sl[i] += u;
			sc[j] += u;
		}
	}
	int cnt = mat[n-1][0]; sum = mat[n-1][n-1];
	rep( i, 0, n-1 ){
		if( sl[i] != sl[i+1] || sc[i] != sc[i+1] ) return 0;
		sum += mat[i][i];
		cnt += mat[i][n-i-1];
	}
	return cnt == sum && sum == sl[0] && sl[0] == sc[0];
}

int main(){
	while( cin >> n ){
		rep( i, 0, n )
			rep( j, 0, n )
				cin >> mat[i][j];
		if( check() ) printf("%d\n", sum );
		else printf("0\n");
	}
}

