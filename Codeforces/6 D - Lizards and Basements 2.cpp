#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int n, a, b, hp[111], ans, pd[30][30][30], memo[30][30][30];
vector<int> aux;

int solve( int p, int l, int h ){
	l = max( l, 0 );
	if( p == n-1 ) return l? 1 << 30 : 0;
	int &ans = pd[p][l][h];
	if( ans == -1 ){
		ans = 1 << 30;
		int x = (l+b-1)/b;
		rep( i, x, 16 ){
			int aux = solve( p+1, hp[p]-h*b-a*i, i ) + i;
			if( aux < ans ){
				ans = aux;
				memo[p][l][h] = i;
			}
		}
		
	}
	return ans;
}

void reconstruct( int p, int l, int h ){
	l = max( l, 0 );
	if( p == n-1 ) return;
	int x = memo[p][l][h];
	rep( i, 0, x ) aux.pb(p);
	reconstruct( p+1, hp[p]-h*b-x*a, x );
}

int main(){
	
	memset( pd, -1, sizeof pd );
	scanf("%d%d%d", &n, &a, &b );
	rep( i, 0, n ){
		scanf("%d", &hp[i] ); hp[i]++;
	}
	while( hp[0] > 0 ){
		hp[1] -= a;
		hp[0] -= b;
		hp[2] -= b;
		ans++;
		aux.pb(1);
	}
	while( hp[n-1] > 0 ){
		hp[n-2] -= a;
		hp[n-1] -= b;
		hp[n-3] -= b;
		ans++;
		aux.pb(n-2);
	}
	cout << ans + solve(1, 0, 0)  << "\n";
	reconstruct(1, 0, 0);
	for( auto x : aux ) printf("%d ", x+1 );
}

