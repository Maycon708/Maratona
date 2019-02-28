#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

#define N 1000100

int v[N], p[N], vis[N];

int main(){
	
	int n, m, a, b, t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		rep( i, 1, n+1 ) v[i] = i-1;
		while( m-- ){
			scanf("%d%d", &a, &b );
			if( a > b ) swap( a, b );
			v[a]++, v[b]--;
		}
		int id = -1;
		rep( i, 1, n+1 ) if( v[i] == n-1 ) id = i;
		if( id != -1 ) printf("2 %d\n", id );
		else puts("1");
	}
	
	return 0;
}
