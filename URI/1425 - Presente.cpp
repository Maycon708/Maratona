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

const int N = 40, cc = 30;
bool vis[N][cc];
int dist[N];

void bfs(){
    queue< pair<ii,int> > q;
    q.push( mk( ii( 1, 2 ), 1 ) );
    while( !q.empty() ){
        int u = q.front().F.F;
        int k = q.front().F.S;
        int mx = q.front().S;
        q.pop();
        if( k >= cc || vis[u][k] ) continue;
        dist[u] = min( dist[u], mx );
        vis[u][k] = 1;
        int aux = 2*k-1;
        if( u + aux <= N ) q.push( mk( ii( u + aux, k + 1 ), max( mx, u ) ));
        if( u - aux > 0  ) q.push( mk( ii( u - aux, k + 1 ), max( mx, u ) ));
    }
}
 
int main(){
 
    int n, m;
    rep( i, 0, N ){
    	dist[i] = INF;
	}
 	bfs();
    while(42){
        n = readInt();
        m = readInt();
        if( !n && !m ) break; 
        if( m > N || dist[m] <= n ) printf("Let me try!\n");
        else printf("Don't make fun of me!\n");
         
    }
    return 0;
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

