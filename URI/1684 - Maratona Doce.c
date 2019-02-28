#include<stdlib.h>
#include<stdio.h>

#define rep(i, a, b) for ( i = a; i < b; i++)

int readInt () {
    int minus = 0;
    int result = 0; char ch;
  
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


int main(){
	int n, m, g[10011], i, u, v, aux, t;
	
	t = readInt();
	while( t-- ){ 
		n = readInt();
		m = readInt();
		rep( i, 0, n+1 ) g[i] = 0;
		aux = 1;
		while( m-- ){
			u = readInt();
			v = readInt();
			g[u]++, g[v]++;
		}
		rep( i, 0, n ){
			if( g[i]&1 ){
				aux = 0;
				break;
			}
		}
		if( aux ) printf("Yes\n");
		else printf("No\n");
	}
}
