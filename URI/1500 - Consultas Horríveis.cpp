#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 100005
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define LSOne(S) (S & (-S))
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

ll B1[MAXV], B2[MAXV], vet[MAXV];
int N;

void update( ll* ft, int x, ll v ){
    for( ; x <= N; x += LSOne(x) ) ft[x] += v;
}
ll query( ll* ft, int x ){
    ll ans = 0;
    for( ; x; x -= LSOne(x) ) ans += ft[x];
    return ans;
}

ll _query( ll x ){
    return query( B1, x ) * x - query(B2, x );
}

void range_update(int i, int j, ll v)	{
	update( B1, 	i, 	v );
	update( B1, j + 1, -v );
	update( B2, 	i, 	v * ( i - 1 ));
	update( B2, j + 1, -v * j );
}
ll range_query(int i, int j)    {
    return _query(j) - _query(i - 1);
}

int main(){
    int t, op, c, p, q;
	ll v;
    scanf("%d", &t );
    while( t-- ){
		scanf("%d%d", &N, &c );
		memset( B1, 0, (N+1) * sizeof(ll) );
		memset( B2, 0, (N+1) * sizeof(ll) );
		
        while( c-- ){
            scanf("%d%d%d", &op, &p, &q );
            if( op == 0 ){
				scanf("%lld", &v );
                range_update( p, q, v );
            }
            else{
				printf("%lld\n", range_query( p, q ));
            }
        }
    }	
}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

