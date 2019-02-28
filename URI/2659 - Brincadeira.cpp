#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( int i = a; i < b; ++i )
#define N 5000000
int v[N+1];
int sum[N+1];
int last[N+1];

int main(){
	int n, t, ao, x, y, tt[33];
	while( scanf("%d%d%d%d%d", &n, &t, &ao, &x, &y ) != EOF ){
		rep( i, 0, t ){
			scanf("%d", &tt[i] );
		}
		rep( i, 0, x ) last[i] = -1;
		int l = x + y + 20;
		rep( i, 0, l ){
			if( i == 0 ) v[i] = ao, sum[i] = ao%x, last[sum[i]] = i;
			else{
				int xx = v[i-1];
				bool aux = 0;
				rep( j, 0, t ){
					aux ^= ( ( xx & ( 1 << tt[j] ) ) != 0 );
				}
				v[i] = ( xx >> 1 ) + ( aux << (n-1) );
				sum[i] = (sum[i-1]+v[i])%x;
			}
			if( sum[i] == 0 && i+1 >= y ){
				printf("0 %d\n", i );
				break;
			}
			if( v[i]%x == 0 && y == 1 ){
				printf("%d %d\n", i, i );
				break;
			}
			if( last[sum[i]] != -1 && i-last[sum[i]] >= y ){
				printf("%d %d\n", last[sum[i]]+1, i );
				break;
			}
			if( last[sum[i]] == -1 ) last[sum[i]] = i;
		}
	}
	
}
