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

int vis[MAXV], adj[MAXV];

int bfs( int ini ){
	queue < int > q;
	int cont = 0;
	q.push( ini );
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		cont++;
		q.push( adj[u] );
	}
	return cont;
}

int mdc(int a, int b){
    if(b==0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b){
    return (a/mdc(a,b) * b);
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			adj[i] = readInt() - 1;
			vis[i] = 0;
		}
		int ans = 1;
		rep( i, 0, n ){
			if( !vis[i] ) ans = mmc( ans, bfs( i ) );
		}
		printf("%d\n", ans );
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



