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
#define MAXN 100010
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

int n, s[10010], pd[10010], sum, pos;

inline bool solve( int x, int y ){
	int k = sum + x + y;
	if( k & 1 ) return 0;
	k/=2;
	int resp = k - x, ans = k - y;
	rep( i, 1, sum+1 ) pd[i] = 0;
	pd[0] = 1;
	vector < int > v, aux;
	v.pb( 0 );
	rep( i, 0, n ){
		int u = s[i];
		rep( j, 0, v.size() ){
			int w = v[j];
			if( pd[w+u] ) continue;
			if( w + u == resp || w + u == ans ) return 1;
			pd[w+u] = 1;
			aux.pb( w+u );
		}
		rep( j, 0, aux.size() ) v.pb( aux[j] );
		aux.clear();
	}
	return 0;
}


int main(){
	int test = 1, y, x;
	while( scanf("%d%d%d", &x, &y, &n) != EOF ){
		sum = 0;
		if( !n && !x && !y ) break;
		rep( i, 0, n ){
			s[i] = readInt();
			sum += s[i];
		}
		printf("Teste %d\n", test++ );
		if( solve( x, y ) ) printf("S\n");
		else printf("N\n");
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


