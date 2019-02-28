#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	ll v[3];
	rep( i, 0, 3 ){
		scanf("%lld", &v[i] );
	}
	sort( v, v+3 );
	if( v[0] + v[1] <= v[2] ) printf("Invalido\n");
	else{
		if( v[0] == v[1] && v[1] == v[2] ) printf("Valido-Equilatero\n");
		else if( v[0] == v[1] || v[1] == v[2] ) printf("Valido-Isoceles\n");
		else printf("Valido-Escaleno\n");
		if( v[0]*v[0] + v[1]*v[1] == v[2]*v[2] ) printf("Retangulo: S\n");
		else printf("Retangulo: N\n");
	}
}

