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

struct aluno{
	string nome;
	int p;
};

bool cmp( aluno a, aluno b ){
	return a.p > b.p;
}

int main(){
	int n, m;
	aluno v[100010];
	while( cin >> n >> m ){
		rep( i, 0, n ){
			cin >> v[i].nome >> v[i].p;
		}
		sort( v, v+n, cmp );
		vector<string> t[1010];
		int id = 0;
		rep( i, 0, n ){
			t[id].pb( v[i].nome );
			id = ( id+1 )%m;
		}
		rep( i, 0, m ){
			printf("Time %d\n", i+1 );
			sort( all( t[i] ) );
			rep( j, 0, t[i].size() ) cout << t[i][j] << "\n";
			printf("\n");
		}
	}
}

