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
	int v[] = { 1, 2, 4, 8, 16 }, mat[10][10], a, b, c, d, o;
	int t = readInt();
	rep( I, 0, t ){
		if( I ) printf("\n");
		int n = readInt();
		int one = 0, zero = 0;
		switch( n ){
			case 2:{
				rep( i, 0, v[n] ){
					scanf("%d %d - %d", &a, &b, &o );
					mat[b][a] = o;
					if( o ) one = 1;
					else zero = 1;
				}
				printf("Mapa de Karnaugh\n");
				printf("  0 1\n");
				rep( i, 0, 2 ){
					printf("%d|%d %d\n", i, mat[i][0], mat[i][1]);
				}
				if( one && zero ) printf("Contingencia\n");
				else if( one ) printf("Tautologia\n");
				else printf("Contradicao\n");
				break;
			}
			case 3:{
				rep( i, 0, v[n] ){
					scanf("%d %d %d - %d", &a, &b, &c, &o );
					int A = ( a << 1 ) + b;
					mat[c][A] = o;
					if( o ) one = 1;
					else zero = 1;
				}
				printf("Mapa de Karnaugh\n");
				printf("  00 01 11 10\n");
				rep( i, 0, 2 ){
					printf("%d|%d  %d  %d  %d\n", i, mat[i][0], mat[i][1], mat[i][3], mat[i][2]);
				}
				if( one && zero ) printf("Contingencia\n");
				else if( one ) printf("Tautologia\n");
				else printf("Contradicao\n");
				break;
			}
			case 4:{
				rep( i, 0, v[n] ){
					scanf("%d %d %d %d - %d", &a, &b, &c, &d, &o );
					int A = ( a << 1 ) + b;
					int B = ( c << 1 ) + d;
					mat[B][A] = o;
					if( o ) one = 1;
					else zero = 1;
				}
				printf("Mapa de Karnaugh\n");
				printf("   00 01 11 10\n");
				printf("00|%d  %d  %d  %d\n", mat[0][0], mat[0][1], mat[0][3], mat[0][2]);
				printf("01|%d  %d  %d  %d\n", mat[1][0], mat[1][1], mat[1][3], mat[1][2]);
				printf("11|%d  %d  %d  %d\n", mat[3][0], mat[3][1], mat[3][3], mat[3][2]);
				printf("10|%d  %d  %d  %d\n", mat[2][0], mat[2][1], mat[2][3], mat[2][2]);
				if( one && zero ) printf("Contingencia\n");
				else if( one ) printf("Tautologia\n");
				else printf("Contradicao\n");
				break;
			}
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



