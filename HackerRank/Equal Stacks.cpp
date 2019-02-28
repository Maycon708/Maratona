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
#define MAX  110000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int main(){

	int a[MAX], b[MAX], c[MAX];

	int n1 = readInt();
	int n2 = readInt();
	int n3 = readInt();
	
	rep( i, 0, n1 ) a[i] = readInt();
	rep( i, 0, n2 ) b[i] = readInt();
	rep( i, 0, n3 ) c[i] = readInt();
	
	map < int, int > m1, m2;
	int sum = 0, ans = 0;
	
	for( int i = n1-1; i >= 0; i-- ){
		sum += a[i];
		m1[sum] = 1;
	}
	sum = 0;
	for( int i = n2-1; i >= 0; i-- ){
		sum += b[i];
		m2[sum] = 1;
	}
	sum = 0;
	for( int i = n3-1; i >= 0; i-- ){
		sum += c[i];
		if( m1.count( sum ) && m2.count( sum ) ) ans = max( ans, sum );
	}
	printf("%d\n", ans );
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



