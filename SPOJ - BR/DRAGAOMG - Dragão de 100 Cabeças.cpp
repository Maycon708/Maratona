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

int n, a[20], b[20], c[20];

int bfs(){
	queue < ii > q;
	rep( i, 0, n ) q.push( ii( 100, 0 ) );
	int vis[1001];
	memset( vis, 0, sizeof vis );
	while( !q.empty() ){
		int u = q.front().F;
		int cc = q.front().S;
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, n ){
			int w = u - a[i];
			if( w < 0 ) continue;
			if( w == 0 ) return cc +1;
			w = w + b[i];
			if( w > 1000 ) continue;
			q.push( ii( w, cc+1 ) );
		}
	} 
	return -1;
}

int main(){
	
	while( 1 ){
		n = readInt();
		if( !n ) break;
		rep( i, 0, n ) a[i]	= readInt();
		rep( i, 0, n ) b[i] = readInt();
		int ans = bfs();
		if( ans == -1 ) printf("cavaleiro morreu\n");
		else printf("%d\n", ans );
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



