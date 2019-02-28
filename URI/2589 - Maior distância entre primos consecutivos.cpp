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

	map<int, int> v;
	map<int, int> :: iterator it;
	v[2] = 0;
	v[3] = 1;
	v[5] = 2;
	v[11] = 4;
	v[29] = 6;
	v[97] = 8;
	v[127] = 14;
	v[541] = 18;
	v[907] = 20;
	v[1151] = 22;
	v[1361] = 34;
	v[9587] = 36;
	v[15727] = 44;
	v[19661] = 52;
	v[31469] = 72;
	v[156007] = 86;
	v[360749] = 96;
	v[370373] = 112;
	v[492227] = 114;
	v[1349651] = 118;
	v[1357333] = 132;
	v[2010881] = 148;
	v[4652507] = 154;
	v[17051887] = 180;
	v[20831533] = 210;
	v[47326913] = 220;
	v[122164969] = 222;
	v[189695893] = 234;
	v[191913031] = 248;
	v[387096383] = 250;
	v[436273291] = 282;
	int n, ans = 0;
	while( scanf("%d", &n ) != EOF ){
		for( it = v.begin(); it != v.end(); it++ ){
			if( it -> F > n ) break;
			ans = it -> S;
		}
		printf("%d\n", ans );
	}
	
	
}
