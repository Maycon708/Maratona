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
	string v[10];
	int a, b, aux[] = { 0, 8, 4, 2, 1 };
	v[0] = "ABCDEFGHIJKLMNOP";
	rep( k, 1, 5 ){
		rep( i, 0, aux[k] ){
			cin >> a >> b;
			if( a > b ) v[k] += v[k-1][i<<1];
			else v[k] += v[k-1][(i<<1)+1];
		}
	}
	cout << v[4] << "\n";
}

