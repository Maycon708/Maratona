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
	int n, m, a, v[10010];
	while( scanf("%d%d", &n, &m ) != EOF ){
		unordered_map<int, int> mp;
		rep( i, 0, n ){
			scanf("%d", &a );
			mp[a] = 1;
		}
		int aux = -1;
		rep( i, 0, m ){
			scanf("%d", &v[i] );
			if( aux != -1 ) continue;
			if( mp.count( v[i] ) ) continue;
			int sem_criatividade_para_nome_de_variavel = i;
			rep( j, 0, i ){
				a = v[i] - v[j];
				if(mp.count(a)){
					sem_criatividade_para_nome_de_variavel = -1;
					break;
				}
			}
			aux = sem_criatividade_para_nome_de_variavel;
			mp[v[i]] = 1;
		}
		if( aux != -1 ) printf("%d\n", v[aux] );
		else printf("sim\n");
	}
}

