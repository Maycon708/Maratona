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

ll resp[20], n;

inline ll C( int n ){
	ll resp = 0;
	rep( i, 2, n/2+1 ){
		resp += 9 * 45 * pow( 10, i-2 ) * pow( 10, n - 2 * i );	
	}
	return resp;
}

void pre_comp(){
	rep( i, 2, 19 ){
		if( i & 1 ) resp[i] = resp[i-1] * 10;
		else{
			resp[i] = 36 * pow( 10, ( i-2 ) ) + C( i ); 	
		} 
	}
}

int main(){
	pre_comp();
	while( cin >> n ){
		cout << resp[n] << endl;
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



