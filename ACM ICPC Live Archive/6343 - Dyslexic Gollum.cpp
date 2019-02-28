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

typedef unsigned long long int ll;
typedef pair<int,int> ii;

const int mod = 1e9+7;

bool check( int mask, int k ){
	vector<int> v(k);
	rep( i, 0, k ){
		v[i] = ( (mask & ( 1 << i )) != 0 );
	}
	rep( i, 0, k/2 ) if( v[i] != v[k-i-1] ) return 0;
	return 1;
}

int memo[404][1<<10], pd[404][1<<10], cnt, n, k;
int st[12][1<<11];

bool C( int a, int p ){
	if( p+1 < k+1 ) return 1;
	return !st[k+1][a];
}

bool C1( int a, int p ){
	if( p+1 < k ) return 1;
	a &= ~(1<<k);
	return !st[k][a];
}

int solve( int p, int mask ){
	if( p == n ) return 1;
	if( memo[p][mask] == cnt ) return pd[p][mask];
	memo[p][mask] = cnt;
	int ans = 0;
	int m = mask*2;
	if( C(m, p) && C1(m, p) ) ans = ( ans + solve( p+1, m&~(1<<k) ) )%mod;
	m++;
	if( C(m, p) && C1(m, p) ) ans = ( ans + solve( p+1, m&~(1<<k) ) )%mod;
	return pd[p][mask] = ans;
}

int main(){
	
	int t;
	rep( i, 1, 12 ){
		rep( j, 0, 1 << i ){
			if( check( j, i ) ) st[i][j] = 1;
		}
	}
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &k );
		cnt++;
		printf("%d\n", solve( 0, 0 ) );
	}
	
	return 0;
}	
