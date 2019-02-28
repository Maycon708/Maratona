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

int n, pd[2010][1010], v[2010], mat[2010][1010], cont;
vector < int > vec;
void back( int pos, int cap){
	if( pos == n ) return;
	if( mat[pos][cap] ){
		vec.pb( pos+1 );
		cont++;
		back( pos+1, cap - v[pos] );
	}
	else
		back( pos+1, cap );
}

int solve( int pos, int cap ){
	if( pos == n ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int a, b = 0;
	a = solve( pos+1, cap );
	if( cap >= v[pos] ) b = solve( pos+1, cap - v[pos] ) + v[pos];
	if( b > a ) mat[pos][cap] = 1;
	return pd[pos][cap] = max( a, b );
}

int main(){

	while( 1 ){
		cont = 0;
		int m = readInt();
		int l = readInt();
		if( !m && !l ) break;
		n = readInt();
		int sum = 0;
		rep( i, 0, n ){
			v[i] = readInt();
			sum += v[i];
		}
		if( sum > m + l ){
			printf("Impossible to distribute\n");
			continue;
		}
		rep( i, 0, n )
			rep( j, 0, m+1 )
				mat[i][j] = 0, pd[i][j] = -1;
		vec.clear();
		int ans = solve( 0, m );
		if( sum - ans > l ){
			printf("Impossible to distribute\n");
			continue;
		}
		back( 0, m );
		sort( all( vec ) );
		printf("%d", cont );
		rep( i, 0, vec.size() ){
			printf(" %d", vec[i] );
		}
		printf("\n");
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


