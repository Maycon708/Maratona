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
typedef vector< int > vec;

ll readInt();

vec v, u;
bool aux;

inline bool C( vec a ){
	if( a.size() != u.size() ) return 0;
	rep( i, 0, a.size() ){
		if( a[i] != u[i] ) return 0;
	}
	return 1;
}

vec dobra( vec a, int pos ){
	vec b;
	int k = a.size() - pos;
	if( pos > k ){
		rep( i, 0, pos ){
			b.pb( a[i] );
		}
		rep( j, 1, k+1 ){
			int u = b.size() - j;
			b[u] += a[pos+j-1]; 
		}
	}
	else{
		rep( i, pos, a.size() ) b.pb( a[i] );
		rep( i, 0, pos ){
			int u = pos - i - 1;
			b[i] += a[u];
		}
		reverse( all( b ) );
	}
	return b;
}

map< vec, bool > vis;
void D( vec c ){
	printf("////////////////");
	rep( i, 0, c.size() ) printf("%d ", c[i] );
	printf("\n");
}

void solve( vec a ){
	if( vis[a] || a.size() < u.size() ) return;
	vis[a] = 1;
	if( C( a ) || aux ){
		aux = 1;
		return;
	}
	rep( i, 0, a.size() ){
		vec b = dobra( a, i );
		solve( b );
	}
}


int main(){
	int n, m;
	while( cin >> n ){
		u.clear(), v.clear(), vis.clear();
		aux = 0;
		int a = 0, b = 0;
		rep( i, 0, n ){
			int k;
			scanf("%d", &k );
			v.pb( k );
			a += k;
		}
		
		scanf("%d", &m );
		rep( i, 0, m ){
			int k;
			scanf("%d", &k );
			u.pb( k );
			b += k;
		}	
			
		if( a != b ){
			puts("N");
			continue;
		}
		solve( v );
		if( aux ) puts("S");
		else puts("N");
		
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



