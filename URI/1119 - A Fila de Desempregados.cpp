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
	deque < int > q1, q2;
	int vis[30];
	while( 1 ){
		memset( vis, 0, sizeof vis );
		int n = readInt();
		int k = readInt();
		int m = readInt();
		if( !n && !m && !k ) break;
		rep( i, 1, n+1 ){
			q1.pb(i);
		}
		for( int i = n; i > 0; i-- ){
			q2.pb(i);
		}
		int aux = 0;
		while(1){
			int cont = 0, cnt = 0, u, v;
			if( q1.empty() || q2.empty() ) break;
			while( cont < k ){
				u = q1.front();
				q1.pop_front();
				if( vis[u] ) continue;
				q1.pb( u );
				cont++;
			}
			while( cnt < m ){
				v = q2.front();
				q2.pop_front();
				if( vis[v] ) continue;
				q2.pb( v );
				cnt++;
			}
			
			vis[u] = vis[v] = 1;
			for( int i = q1.size()-1; i >= 0; i-- ){
				if( vis[ q1[i] ] ){
					q1.erase( q1.begin() + i );
				}
			}
			for( int i = q2.size()-1; i >= 0; i-- ){
				if( vis[ q2[i] ] ){
					q2.erase( q2.begin() + i );
				}
			}
			if( aux ) printf(",");
			aux = 1;
			if( u == v ) printf("%3d", u );
			else printf("%3d%3d", u, v );
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

