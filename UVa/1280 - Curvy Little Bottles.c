#include<stdio.h>
#include<math.h>

typedef long double ld;

ld eleva( ld b, int e ){
	ld ans = 1;
	for( ; e; e >>= 1 ){
		if( e&1 ) ans *= b;
		b *= b;
	}
	return ans;
}

ld P[30];

void elevaP( ld a[], int n ){
	int i, j;
	for( i = 0; i <= 2*n; ++i ) P[i] = 0;
	for( i = 0; i <= n; ++i )
		for( j = 0; j <= n; ++j )
			P[i+j] += a[i] * a[j];
}

ld volume( ld xhigh, ld xlow, int n ){
	ld V = 0;
	int i;
	for( i = 0; i <= 2*n; ++i ){
		V += ( P[i] )/( i+1 ) * ( eleva( xhigh, i+1 ) - eleva( xlow, i+1 ) );
	} 
	return V * M_PI;
}

int main(){
	int n, inc, i, test = 1, cnt;
	ld a[20], xlow, xhigh, V, lo, hi, mid, v, tg;
	while( scanf("%d", &n ) != EOF ){
		for( i = 0; i <= n; ++i )
			scanf("%LF", &a[i] );
		scanf("%LF%LF%d", &xlow, &xhigh, &inc );
		elevaP( a, n );
		V = volume( xhigh, xlow, n );
		printf("Case %d: %.2LF\n", test++, V );
		if( V < inc ) puts("insufficient volume");
		else{
			tg = inc; cnt = 0;
			while( tg <= V && cnt < 8 ){
				lo = xlow, hi = xhigh;
				for( i = 2000; i > 0; --i ){
					mid = ( lo + hi )/2;
					v = volume( mid, xlow, n );
					if( v < tg ) lo = mid;
					else hi = mid;
				}	
				if( cnt ) printf(" ");
				printf("%.2LF", mid-xlow );
				tg += inc; cnt++;
			}
			printf("\n");
		}
	}
}
