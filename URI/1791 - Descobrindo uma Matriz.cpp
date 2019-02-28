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
typedef vector< ll > vec;

ll readInt();

int cont_mat = 1;
void debug_mat( vec m[10], int l, int c ){
	int i, j;
	printf("Matriz %d:\n", cont_mat++);
	rep( i, 0, l ){
		rep( j, 0, c ){
			printf("%d ", m[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

inline bool cmp( vec a, vec b ){
	int sum1 = 0, sum2 = 0, n = a.size();
	rep( i, 0, n ){
		sum1 += a[i];
		sum2 += b[i];
	}
	if( sum1 == n ) return 1;
	if( sum2 == n ) return 0;
	rep( i, 0, n )
		if( abs( a[i] ) != abs( b[i] )){
			if( abs( a[i] ) != 1 )
				return abs( a[i] ) < abs( b[i] );
		}
}

inline bool check( vec *a, int n ){
	rep( i, 0, n ){
		if( a[0][i] != 1 ) return 0;
	}
	rep( j, 0, n ){
		int t = a[1][j], tt = a[1][j];
		rep( i, 1, n ){
			if( t != a[i][j] ) return 0;
			t *= tt;
		}
	}
	return 1;
}

inline int check_one( vec *a, int n ){
	vector< vec > V;
	rep( i, 0, n ){
		int sum = 0;
		rep( j, 0, n ){
			sum += a[i][j];
		}
		if( sum != n ) V.pb( a[i] );
	}
	int tam = V.size();
	if( tam != n/2 ) return 0;
	rep( i, 1, tam ){
		rep( j, 0, n ){
			if( V[i][j] != V[i-1][j] ) return 0;
		}
	}
	return 	1;
}

int main(){
	vec l[10], c[10];
	int t = readInt();
	
	while( t-- ){
		bool zero = 0, one = 1;
		int sum = 0;
		int n = readInt();
		rep( i, 0, n ) c[i].clear(), l[i].clear();
		rep( i, 0, n ){
			rep( j, 0, n ){
				int u = readInt();
				sum += u;
				if( !u ) zero = 1;
				if( abs(u) != 1 ) one = 0;
				l[i].pb( u );
				c[j].pb( u );
			}
		}
		if( zero ){
			printf("Nao Potencia\n");
			continue;
		}
		if( one ){
			if( check_one( l, n ) || check_one( c, n ) ) printf("Potencia\n");
			else printf("Nao Potencia\n");
			continue;
		}
		sort( l, l+n, cmp );
		sort( c, c+n, cmp );
		if( check( l, n ) || check( c, n ) ) printf("Potencia\n");
		else printf("Nao Potencia\n");
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

