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

struct T{
	int a, b, c, op;
};

int main(){
//	freopen( "out.txt", "w+", stdout );
	map < string, int > mp;
	vector < string > v;
	int mat[10][10];
	vector < T > resp;
	char s[10000], s1[10000];
	int test = 1;
	while( 1 ){
		int n = readInt();
		if( n == -1 ) break;
		if( test != 1 ) printf("\n");
		v.clear(); mp.clear(); resp.clear();
		memset( mat, 0, sizeof mat );
		rep( i, 0, 6 ){
			scanf("%s", s );
			v.pb( s );
		}
		sort( all( v ) );
		rep( i, 0, 6 ) mp[ v[i] ] = i;
		rep( i, 0, n ){
			scanf("%s %s", s, s1 );
			int u = mp[s], v = mp[s1];
			mat[u][v] = mat[v][u] = 1;
		}  
		rep( i, 0, 6 ){
			rep( j, i+1, 6 ){
				rep( k, j+1, 6 ){
					T aux;
					if( mat[i][j] && mat[i][k] && mat[j][k] ){
						aux.a = i, aux.b = j, aux.c = k, aux.op = 1;
						resp.pb( aux );
					}
					if( !mat[i][j] && !mat[i][k] && !mat[j][k] ){
						aux.a = i, aux.b = j, aux.c = k, aux.op = 0;
						resp.pb( aux );
					}
				}
			}
		}
		printf("Instancia %d\n", test++ );
		rep( i, 0, resp.size() ){
			if( resp[i].op )
				cout << v[ resp[i].a ] << " " << v[ resp[i].b ] << " " << v[ resp[i].c ] << " sao amigos\n";
			else
				cout << v[ resp[i].a ] << " " << v[ resp[i].b ] << " " << v[ resp[i].c ] << " sao inimigos\n";
		}
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


