#include<stdio.h>
#include<stdlib.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for ( i = a; i < b; i++)
#define MAXN 100010

typedef long long int ll;

ll readInt();

const int max( int a, int b ){
	if( a > b ) return a;
	return b;
}

int main(){

	int n, s[MAXN], pd[2][MAXN], sum, pos, dif, i;
	while( 1 ){
		sum = 0;
		n = readInt();
		if( !n ) break;
		rep( i, 0, n ){
			s[i] = readInt();
			sum += s[i];
		}
		pos = n-1;
	
		rep( i, 0, MAXN ) pd[0][i] = pd[1][i] = -INF;
		pd[1][0] = 0;
		while( pos >= 0 ){
			rep( dif, 0, sum+1 ){
				int u = abs( s[pos] - dif );
				int v = dif + s[pos];
				pd[0][dif] = max( pd[0][dif], pd[1][u] + s[pos] );
				if( v <= sum )pd[0][dif] = max( pd[0][dif], pd[1][v] + s[pos] );
				pd[0][dif] = max( pd[0][dif], pd[1][dif] );
			}
			rep( i, 0, sum+1 ) pd[1][i] = pd[0][i];
			pos--;
		}
		
		printf("%d\n", pd[0][0]/2 );
	}

}

ll readInt () {
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while (1) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = 1;
    else result = ch-'0';
    while (1) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}


