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

const int MAX = 101010;

int v[MAX], id[MAX], sum[MAX]; 

inline bool cmp( int a, int b ){
	return sum[a] <= sum[b];
}

int main(){
	while( 1 ){
		int n = readInt();
		int k = readInt();
		if( !n && !k ) break;
		rep( i, 0, n ){
			v[i] = readInt();
		}
		sum[0] = 0;
		rep( i, 0, n ){
			sum[i+1] = sum[i] + v[i]; 
		}
		n++;
		rep( i, 0, n ) id[i] = i;
		sort( id, id+n, cmp );
		rep( i, 0, n ){
			rep( j, i+1, n ){
				debug( sum[id[i]] - sum[id[j]] );
			}
		}
		while( k-- ){
			int m = readInt();
			int lo = id[0], hi = id[1], best = sum[hi] - sum[lo];
			int i = 0, j = 1;
			while( j < n ){
				int aux = sum[ id[j] ] - sum[ id[i] ];
				if( abs( aux - m ) < abs( best - m ) ){
					best = aux;
					lo = id[i];
					hi = id[j];
				}
				if( i+1 == j || aux < m ) j++;
				else i++;
			}  
			if( lo > hi ) swap( lo, hi );
			printf("%d %d %d\n", best, lo+1, hi );
		}		
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



