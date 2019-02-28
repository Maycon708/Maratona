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

int main(){
	int a[600], b[600], c[600], d[600], n, m;
	while( scanf("%d%d", &m, &n ) != EOF ){
		map < vector < int > , int > mp;
		map < vector < int > , int > :: iterator it;
		mp.clear();
		rep( i, 0, m ){
			a[i] = readInt();
			b[i] = readInt();
			c[i] = readInt();
			d[i] = readInt();
		}
		rep( i, 0, n ){
			int x = readInt();
			int y = readInt();
			int z = readInt();
			vector < int > v;
			v.clear();
			rep( j, 0, m ){
				int u = a[j] * x + b[j] * y + c[j] * z - d[j];
				if( u > 0 ) v.pb( 1 );
				else v.pb( -1 );
			}
			mp[v]++;
		}
		int ans = 0;
		for( it = mp.begin(); it != mp.end(); it++ ){
			ans = max( ans, it -> S );
		}
		printf("%d\n", ans );
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


