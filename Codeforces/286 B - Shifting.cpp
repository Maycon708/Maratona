#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int v[2002002], n;

int main(){
	scanf("%d", &n );
	rep( i, 0, n ) v[i] = i+1;
	int aux;
	rep( i, 0, n-1 ){
		aux = -1;
		for( int j = i; j < n+i; j += i+2 ){
			swap( v[j], aux );
		}
		v[n+i] = aux;
	}
	rep( i, 0, 2*n-1 ) if( v[i] != -1 ) printf("%d ", v[i] );
}

