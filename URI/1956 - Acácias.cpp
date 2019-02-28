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
int pai[MAXV];
 
priority_queue< pair< ll, ii > > pq;
 
ll S = 0;
 
void init(int v){
    for (int i=0; i <= v; i++)
        pai[i] = i; // inicialmente cada vertice esta no seu proprio conjunto
}
 
int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != pai[i]) 
        pai[i] = findset(pai[i]); // i esta no mesmo conjunto de pai[i]
    return pai[i];
}
  
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa; // aa se torna o pai do conjunto bb
 
}
 
bool sameset(int a, int b){
    return findset(a) == findset(b); // retorna true se os conjuntos que contem os elementos A e B é o mesmo
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		init( n );
		S = 0;
		rep( i, 1, n ){
			int k = readInt();
			rep( j, 0, k ){
				int v = readInt();
				int c = readInt(); 
				pq.push( mk( -c, ii( i, v ) ) );
			}
		}
		while( !pq.empty() ){
	    	ii a = pq.top().S;
	    	ll c = -pq.top().F;
	    	pq.pop();
	        if( !sameset( a.F, a.S ) ){
				S += c;
	            unionset( a.F, a.S);  
	        }
	    }
	    set < int > vec;
	    vec.clear();
	    rep( i, 1, n+1 ){
	    	int u = findset(i);
	    	vec.insert(u);
		}
	    printf("%d %lld\n", vec.size(), S );
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

