#include<stdio.h>
#include<math.h>

double eleva( double b, int e ){
	double ans = 1;
	for( ; e; e >>= 1 ){
		if( e&1 ) ans *= b;
		b *= b;
	}
	return ans;
}

double P[30];

void elevaP( double a[], int n ){
	int i, j;
	for( i = 0; i <= 2*n; ++i ) P[i] = 0;
	for( i = 0; i <= n; ++i )
		for( j = 0; j <= n; ++j )
			P[i+j] += a[i] * a[j];
}

double volume( double xhigh, double xlow, int n ){
	double V = 0;
	int i;
	for( i = 0; i <= 2*n; ++i ){
		V += ( P[i] )/( i+1 ) * ( eleva( xhigh, i+1 ) - eleva( xlow, i+1 ) );
	} 
	return V * M_PI;
}

int main(){
	int n, inc, i, test = 1, cnt;
	double a[20], xlow, xhigh, V, lo, hi, mid, v, tg;
	while( scanf("%d", &n ) != EOF ){
		for( i = 0; i <= n; ++i )
			scanf("%lf", &a[i] );
		scanf("%lf%lf%d", &xlow, &xhigh, &inc );
		elevaP( a, n );
		V = volume( xhigh, xlow, n );
		printf("Case %d: %.2f\n", test++, V );
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
				printf("%.2f", mid-xlow );
				tg += inc; cnt++;
			}
			printf("\n");
		}
	}
}
