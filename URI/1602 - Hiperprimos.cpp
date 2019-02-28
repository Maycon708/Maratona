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

ll _crivo_size;
bitset < 10000010 > bs;
vector <int> primes;

void crivo(ll upperbound)
{
	_crivo_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;	
	for(ll i = 2; i<= _crivo_size; i++)
	if(bs[i]){
		for(ll j = i*i; j<= _crivo_size; j+=i) bs[j] = 0;
		primes.pb((int) i);
	}
}

int fatora(long long int n){
	int i = 0;
	map < int, int > mp;
	map < int, int > :: iterator it;
	while( n != 1 ){
		if( n % primes[i] == 0 ){
			n/= primes[i];
			mp[ primes[i] ]++;
		}
		else i++;
	}
	int resp = 1;
	for( it = mp.begin(); it != mp.end(); it++ )
		resp *= ( 2*it -> S + 1);
	return resp;
}
const int MAX = 2*1e6+100;
int resp[MAX];

int main(){

	crivo(MAX);
	resp[1] = 0;
//	int a = readInt(), b = readInt();
//	rep( i, a, b){	
	rep( i, 2, MAX ){
//		debug( i )
		if( bs[i] ){
			resp[i] = resp[i-1] + 1;
			continue;
		}
		int u = sqrt( i );
		if( u != sqrt(i) ){
			resp[i] = resp[i-1];
			continue;
		}
		int d = fatora( u );
		if( d > MAX ) debug( d 	)
		if( bs[ d ] )  resp[i] = resp[i-1] + 1;
		else resp[i] = resp[i-1];
	}
	int n;
	while( scanf("%d", &n ) != EOF ){
		if( n < 2 ) break;
		printf("%d\n", resp[n] );
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

