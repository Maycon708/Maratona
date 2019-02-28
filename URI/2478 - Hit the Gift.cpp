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
	int n;
	string s, aux, a, b;
	while( scanf("%d", &n ) != EOF ){
		map<string, set<string> > mp;
		while( n-- ){
			cin >> s;
			rep( i, 0, 3 ){
				cin >> aux;
				mp[s].insert(aux);
			}
		}
		while( cin >> a >> b ){
			if( mp[a].count(b) ) 
				puts("Uhul! Seu amigo secreto vai adorar o/");
			else 
				puts("Tente Novamente!"); 
		}
	}
}

