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

struct caixa{
    int x, y, z, v;
	caixa( int x = 0, int y = 0, int z = 0, int v = 0 ) : x(x), y(y), z(z), v(v) {}
	bool operator < ( caixa s ) const { 
		if( v != s.v )return v < s.v; 
		else if( x != s.x ) return x < s.x;
		else if( y != s.y ) return y < s.y;
		else return z < s.z;
	};

};

inline int C( caixa a, caixa b ){
    if( a.v > b.v ) return 0;
    if( a.x <= b.x && a.y <= b.y && a.z <= b.z ) return 1;
    if( a.x <= b.y && a.y <= b.z && a.z <= b.x ) return 1;
    if( a.x <= b.z && a.y <= b.x && a.z <= b.y ) return 1;
    if( a.x <= b.x && a.z <= b.y && a.y <= b.z ) return 1;
    if( a.x <= b.y && a.z <= b.z && a.y <= b.x ) return 1;
    if( a.x <= b.z && a.z <= b.x && a.y <= b.y ) return 1;
    if( a.y <= b.x && a.x <= b.y && a.z <= b.z ) return 1;
    if( a.y <= b.y && a.x <= b.z && a.z <= b.x ) return 1;
    if( a.y <= b.z && a.x <= b.x && a.z <= b.y ) return 1;
    return 0;
}
       
int main(){

//	freopen("in.txt", "r", stdin);    
//	freopen("out.txt", "w", stdout);
    while( 1 ){
        int n = readInt();
        int m = readInt();
        if( !n && !m ) break;
        caixa a, aux;
        map < caixa, int > mp;
        map < caixa, int > :: iterator it;
        mp.clear();
        a.x = readInt();
        a.y = readInt();
        a.z = readInt();
        a.v = a.x * a.y * a.z;
        while( m-- ){
        	set < caixa > s;
        	set < caixa > :: iterator it2;
            int x = readInt();
            int y = readInt();
            int z = readInt();
            aux.v = x * y * z;
            s.clear();
            aux.x = x; aux.y = y; aux.z = z;
            s.insert(aux);
			aux.x = x; aux.y = z; aux.z = y;
            s.insert(aux);
			aux.x = y; aux.y = z; aux.z = x;
            s.insert(aux);
			aux.x = y; aux.y = x; aux.z = z;
            s.insert(aux);
			aux.x = z; aux.y = y; aux.z = x;
            s.insert(aux);
			aux.x = z; aux.y = x; aux.z = y;
            s.insert(aux);
            for( it2 = s.begin(); it2 != s.end(); it2++ ){
            	caixa k = *it2;
            	mp[k]++;
			}
        }
        int cont = 0, total = INF;
        for( it = mp.begin(); it != mp.end(); it++ ){
        	aux = it -> first;
        	int u = it -> second;
			if( C( a, aux ) && u >= n ){
				cont = 1;
				total = min( total, aux.v - a.v );
			} 
		}
        if( cont ) printf("%d\n", total);
		else printf("impossible\n");
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
