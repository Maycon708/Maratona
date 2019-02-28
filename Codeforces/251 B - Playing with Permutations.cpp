#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int n;
vector<int> p;

void permutate( vector<int> &v ){
	vector<int> aux(n);
	for( int i = 0; i < n; i++ ){
		aux[p[i]] = v[i];
	}
	v = aux;
}

void invPermutate( vector<int> &v ){
	vector<int> aux(n);
	for( int i = 0; i < n; i++ ){
		aux[i] = v[p[i]];
	}
	v = aux;
}

int main(){
	vector<int> v, aux, ini;
	int k;
	
	scanf("%d%d", &n, &k );
	
	v.resize(n);
	p.resize(n);
	aux.resize(n);
	
	rep( i, 0, n ) scanf("%d", &p[i] ), p[i]--;
	rep( i, 0, n ) scanf("%d", &v[i] ), v[i]--;
	rep( i, 0, n ) aux[i] = i;
	ini = aux;
	
	bool aa = 0, bb = 0;
	
	if( v == aux ){
		puts("NO");
		return 0;
	}
	
	int a = 0, b = 0;
	rep( i, 0, k ){
		a++;
		permutate(aux);
		if( v == aux ){
			aa = 1;
			break;
		}
	}
	aux = ini;
	rep( i, 0, k ){
		b++;
		invPermutate(aux);
		if( v == aux ){
			bb = 1;
			break;
		}
	}
	if( a == 1 && b == 1 ) puts( k == 1 && ( aa || bb ) ? "YES" : "NO" );
	else if( aa && ( k == a  || ( (k-a)%2 == 0 ) ) ) puts("YES");
	else if( bb && ( k == b  || ( (k-b)%2 == 0 ) ) ) puts("YES");
	else puts("NO");
}
