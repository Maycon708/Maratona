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

int n, k, sum[10010][51];
vector < ll > m;

inline bool C(){
	if( n <= k ) return 1;
	rep( i, 0, k ){
		ll aux = 1;
		bool check = 1;
		rep( j, i, m.size() ){
			if( m[j] & ( aux << i ) ){
				check = 0;
				swap( m[i], m[j] );
				break;
			}
		}
		if( check ) return 1;
		rep( j, i+1, m.size() ){
			if( m[j] & ( aux << i ) )m[j] ^= m[i];
		}
	}	
	return 0;
}

int main(){
	
	while( scanf("%d", &n ) != EOF ){
		k = readInt();
		rep( i, 0, n ){
			rep( j, 0, k){
				sum[i][j] = readInt()&1;
				if( j ) sum[i][j] = ( sum[i][j] + sum[i][j-1] )&1;
			}
		}
		rep( i, 0, n ){
			ll a = 0;
			rep( j, 0, k ){
				a <<= 1;
				a += sum[i][j];
			}
			m.pb( a );
		}
		if( C() ) printf("S\n");
		else printf("N\n");
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


