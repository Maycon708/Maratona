#include <bits/stdc++.h>
      
#define INF 1e+12
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 2110
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

int n, m;
vector < pair < int, pair < double, double > > > adj[1111];
  
int readInt () {
    bool minus = false;
    int result = 0; char ch;
        
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

double dijkstra( double t ){
    priority_queue < pair < double, int > > pq;
    double dist[1111]; 
    bool vis[1111];
    rep( i, 0, n+1 ){
        dist[i] = INF;
        vis[i] = 0;
    }
    dist[1] = 0;
    pq.push( mk( 0, 1 ) );
    while( !pq.empty() ){
        int u = pq.top().S;
        double c = -pq.top().F;
        pq.pop();
        if( vis[u] ) continue;
        if( u == n ) return dist[u];
        vis[u] = 1;
        rep( i, 0, adj[u].size() ){
            int v = adj[u][i].F;
            double d_u_v = adj[u][i].S.F * t + adj[u][i].S.S;
            if( dist[v] > dist[u] + d_u_v ){
                dist[v] = dist[u] + d_u_v;
                pq.push( mk( -dist[v], v ) );
            }
        }
    }
}

double tern(double lo, double hi){
    
    rep(i, 0, 100){
        double midL = (2*lo+hi)/3;
        double midR = (lo+2*hi)/3;
        if( dijkstra(midL) < dijkstra(midR) )
            lo = midL;
        else
            hi = midR;    
    }
    
    return dijkstra( lo );
}

double bt(){
    double low = 0, hi = 24 * 60, a, b;
    rep( k, 0, 200 ){
        double mid1 = low + ( hi - low )/3;
        double mid2 = hi - ( hi - low )/3;
        a = dijkstra( mid1 );
        b = dijkstra( mid2 );
        if( a < b ) low = mid1;
        if( b < a ) hi = mid2;
    }
    return max( a, b );
}

int main(){
    int i, j;
    double a, b;
    while( scanf("%d%d", &n, &m ) != EOF ){
        rep( i, 0, 1111 ) adj[i].clear();
		while( m-- ){
            i = readInt();
            j = readInt();
            a = readInt();
            b = readInt();
            adj[i].pb( mk(j, mk( a, b ) ) );
            adj[j].pb( mk(i, mk( a, b ) ) ); 
        }
        printf("%.5f\n", bt() );
    }
}

