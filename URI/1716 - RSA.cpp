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
#define NEGPOW(e) ((e) % 2 ? -1 : 1)
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

void factorize( ll n, vector <ll> &v ){
    int sq = ll (sqrt((double)n));     
	for( ll i = 2; i <= sq; ++i ){         
		if (n % i)             
			continue;         
		v.push_back (i);         
		n /= i--;         
		sq = ll (sqrt((double) n));     
	}     
	if (n > 1) v.push_back(n);  
} 
ll phi( ll n ){     
	vector <ll> p;  
    factorize (n, p);  
    for( int i = 0; i < p.size(); ++i ){         
		if (i && p[i] == p[i - 1])             
			continue;         
		n /= p[i];         
		n *= p[i] - 1;     
	}  
    return n; 
} 
 

ll extgcd( ll a, ll b, ll &x, ll &y ){     
	ll g = a;     x = 1;     y = 0;     
	if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;     
	return g; 
} 

ll jacobi(ll a, ll m){     
	if(a==0) return m == 1 ? 1 : 0;     
	if(a%2) return NEGPOW((a-1)*(m-1)/4)*jacobi(m%a, a);     
	else return NEGPOW((m*m-1)/8)*jacobi(a/2, m); 
}    
ll invMod(ll a, ll m) {     
	ll x, y;     
	if (extgcd(a, m, x, y) == 1) return (x + m) % m;     
	else return 0; //Nao Resolvivel 
}
ll powMod(ll x, ll k, ll m){     
	if(k==0) return 1;     
	if(k%2==0) return powMod(x*x%m,k/2,m);     
	else return x*powMod(x,k-1,m)%m; 
}  

int main(){
	ll n, e, c;
	while( scanf("%lld%lld%lld", &n, &e, &c ) != EOF ){
		int p = phi( n );
		int d = invMod( e, p );
		printf("%lld\n", powMod( c, d, n ) );
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


