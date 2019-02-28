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
	int n, cnt[3];
	string name[3], aux;
	while( scanf("%d", &n ) != EOF ){
		name[0].clear();
		cnt[1] = cnt[0] = 0;
		rep( i, 0, n ){
			cin >> aux;
			if( name[0].empty() ) name[0] = aux;
			else if( aux != name[0] ) name[1] = aux;
			if( aux == name[0] ) cnt[0]++;
			else cnt[1]++;
		}
		if( cnt[0] > cnt[1] ) printf("%s\n", name[0].c_str() );
		else printf("%s\n", name[1].c_str() );
	}
}

