#include<bits/stdc++.h>

#define rep(i, a, b) for( int i = a; i < b; i++ )
#define debug2(a, b) cout << #a << " = " << a << " -- " << #b << " = " << b << endl;
#define pb push_back
#define N 100010

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int v[10], n;

ll eleva( ll b, ll e ){
    ll ans = 1;
    for( ; e; e >>= 1 ){
        if( e&1 ) ans *= b;
        b *= b;
    }
    return ans;
}

void C( int p, ll rest ){
    if( !p ) return;
    ll tmp = eleva( n, p-1 );
    rep( i, 1, n+1 ){
        ll a = i * tmp;
        if( a >= rest ){
            printf("%d", v[i-1] );
            C(p-1, rest - (i-1) * tmp);
            break;
        }
    }
}

int main(){
    int t, i;
    ll m;
    scanf("%d", &t );
    while( t-- ){
        scanf("%d", &n );
        rep( j, 0, n ) scanf("%d", &v[j] );
        sort(v, v+n );
        scanf("%lld", &m );
        ll sum = 0;
        for( i = 1; sum < m; i++) sum += eleva(n, i);
        i--; sum -= eleva(n,i);
        C(i, m-sum);
        printf("\n");
    }
}
