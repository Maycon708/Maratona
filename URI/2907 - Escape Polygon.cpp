#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct ponto{
	ll x, y;
	ponto(){};
	ponto( int a, int b ){
		x = a, y = b;
	}
	ponto operator - (ponto q){
		return ponto( x-q.x, y-q.y );
	}
};

ponto get( ponto a ){
	return ponto( -a.y, a.x );
}

int cmp( ponto a, ponto b ){
	a = get(a);
	ll aux = a.x*b.x + a.y*b.y;
	return aux ? ( aux > 0 ? 1 : -1 ) : 0;
}

int n;
ponto p[100100], a[100100];
int b[100100], c[100100];
bool check[100100];

int main(){
	
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf("%lld%lld", &p[i].x, &p[i].y );
	}
	p[n] = p[0];
	rep( i, 0, n ){
		a[i] = get( p[i+1] - p[i] );
		b[i] = n; c[i] = -1; check[i] = 0;
	}
	int lt = 0;
	rep( i, 0, n ){
		for( ; lt < n; lt++ ){
			int aux = cmp( a[i], a[lt] );
			if( !aux && lt != i ) check[i] = 1;
			if( aux < 0 ){
				b[i] = lt;
				break;
			}
		}
	}
	lt = 0;
	rep( i, 0, n ){
		for( ; lt < i; lt++ ){
			int aux = cmp( a[lt], a[i] );
			if( aux > 0 ){
				c[i] = lt;
				break;
			}
		}
	}
	c[n] = 0;
	for( int i = n-1; i >= 0; i-- ) c[i] += c[i+1];
	ll total = 0;
	rep( i, 0, n ){
		total += ( b[i]-check[i] )*(n-b[i]) - c[b[i]];
	}
	cout << total << "\n";
}

