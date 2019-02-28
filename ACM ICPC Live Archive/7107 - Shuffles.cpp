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
	
	int n;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			p[v[i]] = i;
			vis[i] = 0;
		}
		int cnt = 0;
		rep( i, 0, n ){
			if( !vis[i] ){
				cnt++;
				int x = v[i];
				vis[i] = 1;
				while( x < n && p[x] < p[x+1] ){
					x++, vis[p[x]] = 1;
				}
			}
		}
		printf("%.0f\n", ceil(log(cnt)/log(2)) );
	}
	
	return 0;
}
