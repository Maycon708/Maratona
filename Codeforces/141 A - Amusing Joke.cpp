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

	string a, b, c;
	while( cin >> a >> b >> c ){
		vector<int> cnt(26, 0);
		rep( i, 0, a.size() ) cnt[ a[i] - 'A' ]++;
		rep( i, 0, b.size() ) cnt[ b[i] - 'A' ]++;
		rep( i, 0, c.size() ) cnt[ c[i] - 'A' ]--;
		bool aux = 1;
		rep( i, 0, 26 ) if( cnt[i] != 0 ) aux = 0;
		if(aux) puts("YES");
		else puts("NO"); 
	}
}

