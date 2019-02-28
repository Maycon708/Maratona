#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

ll mat[20][20000], s[20][20];
int memo[20][1<<18], pd[20][1<<18], n, m, fim, K, cnt;

void pre(){
	rep( i, 0, n ){
		rep( j, 0, n ){
			s[i][j] = 1LL << 50;
			rep( k, 0, m ){
				s[i][j] = min( s[i][j], abs( mat[i][k] - mat[j][k] ) );
			}
		}
	}
}

int solve( int p, int mask, int ones ){
	if( p == fim ) return ones == n;
	int &ans = pd[p][mask];
	if( memo[p][mask] != cnt ){
		memo[p][mask] = cnt;
		ans = 0;
		rep( i, 0, n ){
			if( (!(mask&(1<<i))) && s[p][i] >= K ) ans |= solve( i, mask | (1<<i), ones+1 );
		}
	} 
	return ans;
}

bool check(){
	rep( i, 0, n ){
		rep( j, 0, n ){
			bool aux = 1;
			if( i == j && n > 1 ) aux = 0;
			rep( k, 0, m-1 ) if( abs( mat[i][k] - mat[j][k+1] ) < K ) aux = 0;
			if( aux ){
				cnt++; fim = j;
				aux = solve( i, 1<<i, 1 );
			}
			if( aux ) return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	rep( i, 0, n ) rep( j, 0, m ) cin >>mat[i][j];
	pre();
	ll lo = 0, hi = 1e9, mid, ans = 0;
	while( lo <= hi ){
		K = (lo+hi)/2;
		if( check() ){
			ans = K;
			lo = K+1;
		}
		else hi = K-1;
	}
	cout << ans << "\n";
}

