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
	string s;
	while( cin >> s ){
		bool aux = 1;
		rep( i, 0, s.size()-6 ){
			bool a = 1;
			rep( j, i+1, i+7 ) a &= ( s[j] == s[i] );
			aux &= (!a);
		}
		if( aux ) puts("NO");
		else puts("YES");
	}
}

