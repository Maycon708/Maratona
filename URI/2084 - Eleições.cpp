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

int main(){

	int n;
	while( scanf("%d", &n ) != EOF ){
		int v[1000], m = 0, sm = 0, sum = 0;
		rep( i, 0, n ){
			v[i] = readInt(), sum += v[i];
			if( v[i] > m ){
				sm = max( m, sm );
				m = v[i];
			}
			else if( v[i] > sm ) sm = v[i];
		}
//		debug2( m, sm + ( sum * 0.1 ) )
		if( m >= floor( sum * 0.45 ) || ( m >= floor( sum * 0.4 ) && m >= sm + floor( sum * 0.1 ) ) )
			puts("1");
		else 
			puts("2");
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



