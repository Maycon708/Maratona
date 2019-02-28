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

int cont[30], p[30], f[30], resp;

char ans[] = {"abcdefghijklmnopqrstuvwxyz"};

void init(){
	resp = 0;
	rep( i, 0, 26 ){
		cont[i] = 0;
		p[i] = i;
		f[i] = 0;
	}
}

void solve( char a, char b ){
	int u = a - 'a', v = b - 'a';
	swap( cont[u], cont[v] );
	rep( i, 0, 26 ){
		if( p[i] == v ) p[i] = u;
		else if( p[i] == u ) p[i] = v;
	}
	int C = 0;
	rep( i, 0, 26 ){
		if( !f[i] ) continue;
		C += cont[i];
	}
	if( C > resp ){
		resp = C;
		rep( i, 0, 26 ){
			ans[i] = char( 'a' + p[i] ); 
		}
		ans[26] = '\0';
	}
}

int main(){
	char s1[30], s2[100100];
	int n, t, tam;
	while( cin >> t >> tam >> n ){
		init();
		scanf("%s", s1 );
		rep( i, 0, t ){
			int u = s1[i] - 'a';
			f[u] = 1;
		}
		scanf("%s", s2 );
		rep( i, 0, tam ){
			int u = s2[i] - 'a';
			cont[u]++;
			resp += f[u];
		}
		rep( i, 0, n ){
			char a, b;
			scanf(" %c %c", &a, &b );
			if( resp == tam || a == b ) continue;
			solve( a, b );
		}
		printf("%d\n", resp );
		rep( i, 0, tam ){
			int u = s2[i] - 'a';
			printf("%c", ans[u] );
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



