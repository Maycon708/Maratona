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
	
	int t;
	scanf("%d", &t );
	while( t-- ){
		string a, b, c;
		cin >> a >> b >> c;
		char aa[2], bb[2];
		rep( i, 0, c.size() ){
			if( c[i] == '_' ) aa[0] = aa[1], bb[0] = bb[1], aa[1] = a[i], bb[1] = b[i];
		}
		if( aa[0] != bb[0] && aa[1] != bb[1] && ( aa[0] == bb[1] || aa[1] == bb[0] ) ) puts("Y");
		else puts("N");
	}
	
}
