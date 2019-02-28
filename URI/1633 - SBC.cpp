#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

inline bool cmp( ii a, ii b ){
	if( a.F != b.F ) return a.F < b.F;
	return a.S < b.S;
}

int main(){
	int T;
	while( scanf("%d", &T ) != EOF ){
		vector < ii > v;
		rep( i, 0, T ){
			int u = readInt();
			int w = readInt();
			v.pb( ii( u, w ) );
		}
		sort( all(v), cmp );
		priority_queue < ii > pq;
		
		ll i = 1, t = v[0].F + v[0].S;
		while( i < T && v[i].F <= t ) pq.push( ii( -v[i].S, -v[i].F ) ), i++;		
		ll c = 0;
		while( !pq.empty() || i < T ){
			if( pq.empty() ){
				t = v[i].F + v[i].S; i++;
				while( i < T && v[i].F <= t ) pq.push( ii( -v[i].S, -v[i].F ) ), i++;
			}
			if( pq.empty() ) break;
			c += ( t + pq.top().S );
			t += -pq.top().F;
			pq.pop();
			while( i < T && v[i].F <= t ) pq.push( ii( -v[i].S, -v[i].F ) ), i++;		
		}
		printf("%lld\n", c );
	}

}



ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}

