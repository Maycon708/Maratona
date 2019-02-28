#include<bits/stdc++.h>

using namespace std;

double B, b, a;
double pi = M_PI;

long double volume( double h ){
	return h*pi*b*b+b*h*h*pi*a+h*h*h*pi*a*a/3;
}

int main(){
	int t, n, l;
	double h;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &l );
		scanf("%lf%lf%lf", &b, &B, &h );
		a = ( B - b )/h;
		double lo = 0, hi = h, mid;
		for( int i = 0; i < 200; i++ ){
			double mid = ( lo+hi )/2;
			if( volume(mid) > (double)l/n ) hi = mid;
			else lo = mid;
		}
		printf("%.2f\n", lo );
	}
}
