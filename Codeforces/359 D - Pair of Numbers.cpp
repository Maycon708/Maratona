#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int menor[300100][22];
int mdc[300100][22], n, v[300100];

void build(){
	rep( i, 0, n ) menor[i][0] = mdc[i][0] = v[i];
	for( int i = 1, k = 1; i < 22; i++, k*=2 ){
		for( int j = 0; j + 2*k-1 < n; j++ ){
			menor[j][i] = min( menor[j][i-1], menor[j+k][i-1] );
			mdc[j][i] = __gcd( mdc[j][i-1], mdc[j+k][i-1] );
		}
	}
}

bool query( int p, int k ){
	int mn = v[p], g = v[p];
	for( int i = 22; i >= 0; i-- ){
		if( k&(1<<i) ){
			if( p >= n ) debug("Deu merda")
			mn = min( mn, menor[p][i] );
			g = __gcd( g, mdc[p][i] );
			p += (1 << i);
		}
	}
	return mn == g;
} 

bool ok( int k ){
	rep( i, 0, n-k+1 ){
		if( query( i, k ) ) return 1;
	}
	return 0;
}


int main(){
	scanf("%d", &n );
	rep( i, 0, n ) scanf("%d", &v[i] );
	build();
	int lo = 1, hi = n, mid, ans = 1;
	while( lo <= hi ){
		mid = (lo+hi)/2;
		if( ok(mid) ){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}
	vector<int> v;
	rep( i, 0, n-ans+1 ){
		if( query( i, ans ) ) v.pb(i);
	}
	cout << v.size() << " " << ans-1 << "\n";
	for( auto x : v ) printf("%d ", x+1 );
}

