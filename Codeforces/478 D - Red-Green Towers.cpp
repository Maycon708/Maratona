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
typedef pair <ll,ll> ii;

ll pd[2][200010];
ll sum[1000], r, g, maxH, mod = 1e9+7;

ll solve(){       
	rep( i, 1, 200010) pd[1][i] = 0;
	pd[1][0] = 1;
    ll ans = r + g;
    for( maxH = 1; ans - sum[maxH] >= 0; maxH++ );
    maxH--;
    for( int at = 1; at <= maxH; at++ ){
		for( int red = 0; red <= r; red++ ){
            pd[0][red] = 0;
            int green = sum[at-1] + at - red;
            if( red >= at ){
                pd[0][red] = pd[1][red-at];
            }
            if( green >= 0 && green <= g ){
                pd[0][red] = ( pd[0][red] + pd[1][red] )%mod;
            }
        }
		swap( pd[0], pd[1] );
    }
    ans = 0;
    rep( i, 0, r+1 ){
    	ans = ( ans + pd[1][i] )%mod;
	}
    
    return ans;
}

int main(){
    rep( i, 1, 1000 ){
        sum[i] = sum[i-1] + i;
    }
    while( scanf("%lld%lld", &r, &g ) != EOF ){
       printf("%lld\n", solve());
    }
}
