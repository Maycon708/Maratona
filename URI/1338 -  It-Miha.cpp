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
#define MAX 20000000000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef unsigned long long int ll;
typedef pair <ll, int> ii;

ll readInt();

ll _crivo_size;
bitset < 10000010 > bs;
vector <int> primes;

void crivo(){
	_crivo_size = 2 * 1e5;
	bs.set();
	bs[0] = bs[1] = 0;	
	for(ll i = 2; i <= sqrt(_crivo_size); i++)
	if(bs[i]){
		for(ll j = i*i; j<= _crivo_size; j+=i) bs[j] = 0;
	}
}

set < ii > term;
set < ii > :: iterator it;
	
void pre_comp(){
	term.insert( ii( 1, +1 ) ); 
	rep( i, 2, 200000 ){
		if( !bs[i] ) continue;
		set < ii > aux;
		aux.clear();
		for( it = term.begin(); it != term.end(); it++ ){
			ii a = *it;
			ll I = i;
			if( I*I <= 2 * ( MAX/ a.F ) ){
				aux.insert( ii(  a.F * i * i, -a.S ) );
			}
			else break;
		}
		for( it = aux.begin(); it != aux.end(); it++ )
			term.insert( *it );
	}
}

ll check( ll a ){
	ll resp = 0;
	for( it = term.begin(); it != term.end(); it++ ){
		ii b = *it;
		ll c = a/b.F;
		if( !c ) break;
		if( b.S == 1 )
			resp += c;
		else resp -= c;
//		debug2( a, b.F )	
//		debug( resp )
//		getchar();
	}
	return resp;
}

ll bb( ll k ){
	ll ini = 0, fim = 2 * MAX;
	while( ini < fim ){
		ll mid = ini + ( fim - ini ) / 2;
		if( check( mid ) >= k ){
			fim = mid;
		}
		else ini = mid+1;
	}
	return fim;
}

int main(){
	
	crivo();
	pre_comp();
	
	int t = readInt();
	while( t-- ){
		ll n = readInt();
		printf("%llu\n", bb( n ) );	
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


