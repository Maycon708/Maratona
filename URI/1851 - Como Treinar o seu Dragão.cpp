#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for ( i = int(a); i < int(b); i++)
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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef unsigned long long int ll;
typedef pair <ll, ll> ii;

ll readInt();


struct D{
	ll a, b, c;
	D( ll a = 0, ll b = 0, ll c = 0 ) : a(a), b(b), c(c) {}
	bool operator < ( D s ) const { if( a * s.b == b * s.a ) return c < s.c; else return a*s.b > b * s.a; };
};

int main(){
	ll t, f;
	vector < ii > v;
	while( cin >> t >> f ){
		if( !t && !f ) break;
		v.pb( ii( t, f ) );
	}
	priority_queue < D > pq; 
	pq.push( D( v[0].F, v[0].S, 0 ) );
	ll i = 0, total = 0, dia = 0, k = v.size();
	while( !pq.empty() ){
//		debug( total )
		ll d = pq.top().c;
//		debug( d )
		f = pq.top().b;
		t = pq.top().a;
		total += (( dia - d ) * f );
		dia += t;
		pq.pop();
		if( i < v.size() ){
			for( ; i < min( k, dia+1 ); i++ ){
				if( i ) pq.push( D( v[i].F, v[i].S, i ) );
			}
		}
	}
	cout << total << "\n";
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

