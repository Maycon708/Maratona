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
	int n, t;
	string s;
	while( scanf("%d%d", &n, &t ) != EOF ){
		cin >> s;
		string aux = s;
		rep( i, 0, t ){
			for( int j = n-2; j >= 0; j-- ){
				if( s[j] == 'B' && s[j+1] == 'G' ) swap( aux[j], aux[j+1] );
			}
			s = aux;
		}
		cout << s << "\n";
	}
}

