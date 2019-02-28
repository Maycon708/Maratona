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
	int v;
	while( cin >> v ){
		map<int, int> mp;
		mp[v] = 1;
		rep( i, 0, 5 ) cin >> v, mp[v] = 1;
		int cnt = 0;
		rep( i, 0, 6 ) cin >> v, cnt += mp[v];
		if( cnt == 3 ) printf("terno\n");
		else if( cnt == 4 ) printf("quadra\n");
		else if( cnt == 5 ) printf("quina\n");
		else if( cnt == 6 ) printf("sena\n");
		else printf("azar\n");
	}
}

