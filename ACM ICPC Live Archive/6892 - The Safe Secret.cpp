#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 450

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll v[N], memo[N][N], cnt;
char op[N];
ii pd[N][N];

inline ll maxSum( ii a, ii b ){
	return max( a.F + b.F, max( a.F + b.S, max( a.S + b.F, a.S + b.S ) ) );
}
inline ll minSum( ii a, ii b ){
	return min( a.F + b.F, min( a.F + b.S, min( a.S + b.F, a.S + b.S ) ) );
}
inline ll maxSub( ii a, ii b ){
	return max( a.F - b.F, max( a.F - b.S, max( a.S - b.F, a.S - b.S ) ) );
}
inline ll minSub( ii a, ii b ){
	return min( a.F - b.F, min( a.F - b.S, min( a.S - b.F, a.S - b.S ) ) );
}
inline ll maxMul( ii a, ii b ){
	return max( a.F * b.F, max( a.F * b.S, max( a.S * b.F, a.S * b.S ) ) );
}
inline ll minMul( ii a, ii b ){
	return min( a.F * b.F, min( a.F * b.S, min( a.S * b.F, a.S * b.S ) ) );
}
inline ll maxQtn( ii a, ii b ){
	return max( maxSum( a, b ), max( maxSub( a, b ), maxMul( a, b ) ) );
}
inline ll minQtn( ii a, ii b ){
	return min( minSum( a, b ), min( minSub( a, b ), minMul( a, b ) ) );
}
int n;
ii solve( int i, int j ){
	if( i == j ) return ii( v[i], v[i] );
	if( memo[i][j] == cnt ) return pd[i][j];
	memo[i][j] = cnt;
	ii ans = ii( INF, -INF );
	rep( k, i, j ){	
		ii a = solve( i, k ), b = solve( k+1, j );
		if( op[k] == '+' ) ans = ii( min( ans.F, minSum(a,b) ), max( ans.S, maxSum(a,b) ) );
		if( op[k] == '-' ) ans = ii( min( ans.F, minSub(a,b) ), max( ans.S, maxSub(a,b) ) );
		if( op[k] == '*' ) ans = ii( min( ans.F, minMul(a,b) ), max( ans.S, maxMul(a,b) ) );
		if( op[k] == '?' ) ans = ii( min( ans.F, minQtn(a,b) ), max( ans.S, maxQtn(a,b) ) );
	}
	return pd[i][j] = ans;
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			cin >> v[i] >> op[i];
			v[n+i] = v[i];
			op[n+i] = op[i];
		}
		cnt++;
		rep( i, 0, n ){
			ii aux = solve( i, i+n-1 );
			printf("%lld%lld", abs(aux.F), abs(aux.S) );
		}
		printf("\n");
	}
}
