#include <bits/stdc++.h>
     
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 110015
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
     
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
     
using namespace std;
     
typedef pair <int, int> ii;
typedef long long int ll;

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

priority_queue< pair< int, ii > > pq;

int S = 0;
int pai[MAXV];

void init(int v){
	S = 0;
    for (int i=0; i <= v; i++)
        pai[i] = i; // inicialmente cada vertice esta no seu proprio conjunto
}

int findset(int i){ // retorna o conjunto que o elemento i pertence
    if (i != pai[i]) 
        pai[i] = findset( pai[i] ); // i esta no mesmo conjunto de pai[i]
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
    int t, n, m, a ,b;
    map < ii, int > mp;
    
    t = readInt();
    while( t-- ){
    	mp.clear();
    	n = readInt();
    	m = readInt();
    	init( n );	
    	rep( i, 0, m ){
    		a = readInt();
    		b = readInt();
    		pq.push( mk( -1, ii( a, b ) ) );
    		mp[ ii( a, b ) ] = mp[ ii( b, a ) ] = 1;
    	}
    	rep( i, 0, n ){
    		rep( j, i+1, n ){
    			if( !mp[ ii( i, j ) ] ){
    				pq.push( mk( 0 , ii( i, j ) ) );
    			}
    		}
    	}
    	 while( !pq.empty() ){
	    	a = pq.top().S.F, b = pq.top().S.S;
		  
		    if(!sameset( a, b )){
		         S += -pq.top().F;
		        
		        unionset( a, b );  
		        
		    }
		    pq.pop();
		}
		printf("%d\n", S );
    }
}
