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

ll readInt();

int p[30], w[30], b[30], mat[30][30], n, tam;
ii v[20];

void check(){
	rep( i, 0, n ){
		int pos = 0, pos2 = n+1;
		rep( j, 0, n ){
			if( p[i] >= p[j] ) pos2--;
			if( p[i] <= p[j] ) pos++;
		}
		b[i] = min( b[i], pos2 );
		w[i] = max( w[i], pos );
	}
}

void solve( int pos ){
	if( pos == tam ){
		check();
		return;
	}
	int i = v[pos].F, j = v[pos].S;
	p[i] += 3;
	solve( pos+1 );
	p[i] -= 3;
	p[i]++, p[j]++;
	solve( pos+1 );
	p[i]--, p[j]--;
	p[j] += 3;
	solve( pos+1 );
	p[j] -= 3;
}

void init(){
	rep( i, 0, n ){
		b[i] = n; w[i] = 1; p[i] = 0;
		rep( j, 0, n ) mat[i][j] = 0;
	}
}

int main(){

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
	int test = 1, g1, g2;
	char t1[100], t2[100], nome[30][100];
	map < string, int > mp;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		mp.clear();
		init();
		rep( i, 0, n ){
			scanf("%s", nome[i] );
			mp[ nome[i] ] = i;
		}
		int t = readInt();
		while( t-- ){
			scanf("%s %s %d %d", t1, t2, &g1, &g2 );
			int u = mp[t1], v = mp[t2];
			mat[u][v] = 1;
			if( g1 > g2 ) p[u] += 3;
			else if( g2 > g1 ) p[v] += 3;
			else p[u]++, p[v]++;
		}
		tam = 0;
		rep( i, 0, n ){
			rep( j, 0, n ){
				if( !mat[i][j] && i != j )
					v[tam++] = ii( i, j );
			}
		}
		solve( 0 );
		printf("Group #%d\n", test++ );
		rep( i, 0, n ){
			printf("%s %d-%d\n", nome[i], b[i], w[i] );
		}
		printf("\n");
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
