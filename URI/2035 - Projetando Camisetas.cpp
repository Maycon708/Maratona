#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXL 200000
#define cc 26
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
typedef vector<int> vi;

ll readInt();

int sig[MAXL][cc], cnt, total;
vi W[MAXL];

void add( string s, int id ){
	int x = 1;
	rep( i, 0, s.size() ){
		int u = s[i] - 'A';
		if( !sig[x][u] ){
			sig[x][u] = cnt++;
		}
		x = sig[x][u];
	}
	W[x].pb( id );
}

vi merge( vi a, vi b ){
	if( a.size() > b.size() ) swap( a, b );
	rep( i, 0, a.size() ){
		b.pb( a[i] );
	}
	return b;
}

vi dfs( int v, int h ){
	vi w, b;
	rep( i, 0, W[v].size() ){
		int x = W[v][i];
		if( x ) w.pb( x );
		else b.pb( x );
	}
	rep( i, 0, cc ){
		if( sig[v][i] ){
			vi aux = dfs( sig[v][i], h+1 );
			if( !aux.empty() ){
				if( aux[0] ) w = merge( w, aux );
				else b = merge( b, aux );
			}
		}
	}
	int tam = min( b.size(), w.size() );
	rep( i, 0, tam ){
		total += h;
		b.pop_back();
		w.pop_back();
	}
	if( b.empty() ) return w;
	else return b;
}

int main(){
	char nome[1000];
	while( 1 ){
		cnt = 2;
		total = 0;
		int n = readInt();
		if( n == -1 ) break;
		rep( i, 0, 150000 ){
			W[i].clear();
			rep( j, 0, 26 ) sig[i][j] = 0;
		}
		rep( j, 0, 2 ){
			rep( i, 0, n ){
				scanf("%s", nome );
				add( nome, j );
			}
		}
		dfs( 1, 0 );
		printf("%d\n", total );
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


