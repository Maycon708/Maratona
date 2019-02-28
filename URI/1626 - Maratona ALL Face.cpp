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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

const int MAX = 1e5 + 5, mod = 1e9 + 7;

ll _crivo_size;
bitset < 10000010 > bs;
vector <int> primes;
ll pd[1010][1010][6], m[1001][1001], l, c;

void crivo(ll upperbound){
	_crivo_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;	
	for(ll i = 2; i<= _crivo_size; i++)
	if(bs[i]){
		for(ll j = i*i; j<= _crivo_size; j+=i) bs[j] = 0;
		primes.pb((int) i);
	}
}

ll eleva( ll b, int p ){
	if( !p ) return 1;
	if( p == 1 ) return b;
	ll a = eleva( b, p / 2 );
	a = ( a * a )%mod;
	if( p & 1 )
		return ( b * a )%mod;
	return a;
}

int main(){
	crivo( MAX );
	ll fat[MAX], sum[MAX], n;
	fat[0] = 1;
	rep( i, 1, MAX ) fat[i] = ( fat[i-1] * i ) %mod;
	while( scanf("%lld", &n ) != EOF ){
		ll resp = 1;
		rep( i, 0, primes.size() ){
			if( primes[i] > n ) break;
			int total = 0, p = primes[i];
			while( p <= n ){
				total += n/p;
				p *= primes[i];
			}
			ll a = ( eleva( primes[i], total+1 ) - 1 + mod )%mod;
			ll inv = eleva( primes[i] - 1, mod-2 )%mod;
			resp = ( resp * ( ( a * inv )%mod ) )%mod;
		}
		printf("%lld %lld\n", ( resp - fat[n] + mod )%mod, fat[n] );
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

