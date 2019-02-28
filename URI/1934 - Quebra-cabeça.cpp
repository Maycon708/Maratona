#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 21005
#define F first
#define S second
#define EPS 1e-9
#define maior(a, b) (a.first>b.first) ? a : (a.first<b.first) ? b : (a.second>b.second) ? a : b

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int c, l, tl[110], tc[110];
string aux[110][110];

map < string, int > mp;
map < string, int > :: iterator it;

set<string> linha[110];
set<string> coluna[110];
		

void resolve_linha(int i){
	
	int cont = 0;
	
	string s;
	
	rep(j,0,c){
		if(!mp.count(aux[i][j])){
			s = aux[i][j];
			cont++;		
		} 
		else tl[i] -= mp[aux[i][j]];
	}
	
	mp[s] = tl[i]/cont;
	
	rep(i,0,l) 
		if(linha[i].find(s)!=linha[i].end()){
			linha[i].erase(linha[i].find(s));
		}
	
	rep(i,0,c) 
		if(coluna[i].find(s)!=coluna[i].end()){
			coluna[i].erase(coluna[i].find(s));
		}
	
}
void resolve_coluna(int j){
	
	int cont = 0;
	
	string s;
	
	rep(i,0,l){
		if(!mp.count(aux[i][j])){
			s = aux[i][j];
			cont++;		
		} 
		else tc[j] -= mp[aux[i][j]];
	}
	
	mp[s] = tc[j]/cont;
	
	rep(i,0,l) 
		if(linha[i].find(s)!=linha[i].end()){
			linha[i].erase(linha[i].find(s));
		}
	
	rep(i,0,c) 
		if(coluna[i].find(s)!=coluna[i].end()){
			coluna[i].erase(coluna[i].find(s));
		}
	
	
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);
	
	while(scanf("%d%d", &l, &c) != EOF){
		
		rep(i, 0, l){
			rep(j,0,c){
				cin >> aux[i][j];
				linha[i].insert(aux[i][j]);
				coluna[j].insert(aux[i][j]);
			}
			scanf("%d", &tl[i]);
		}
		
		rep(i,0,c) scanf("%d", &tc[i]);

		while(1){
			bool aux = true;
			rep(i, 0, l)
				if(linha[i].size() == 1){
					resolve_linha(i);
					aux = false;
				}
			rep(i,0,c)
				if(coluna[i].size() == 1){
					resolve_coluna(i);
					aux = false;
				}
			if(aux) break; 
			
		}
		
		for(it = mp.begin(); it != mp.end(); it++)
			cout << it -> first << " " << it -> second << endl;
		
		mp.clear();
		
	}
	
	
	return 0;
}


