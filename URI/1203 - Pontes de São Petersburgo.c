#include<stdio.h>

#define rep( i, a, b ) for( i = a; i < b; i++ )

int main(){
	int n, m, pd[10500], g[110], u, v, i, j; 
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) g[i] = 0;
		rep( i, 0, m+1 ) pd[i] = 0;
		pd[0] = 1;
		rep( i, 0, m ){
			scanf("%d%d", &u, &v );
			g[u]++, g[v]++;
		}
		rep( j, 1, n+1 ){
			for( i = m; i >= 0; i-- ){
				int u = i + g[j];
				if( !pd[i] || u > m ) continue;
				pd[u] = 1; 
			}
		}
		if( pd[m] ) printf("S\n");
		else printf("N\n");
	}
}
