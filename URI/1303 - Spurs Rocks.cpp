#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

struct team{
	ll vitorias, pontos,  cestas_sof, indice;
	double media_cestas,cestas_mar;
};

team tim[110];

	bool cmp (team a, team b){
	if(a.pontos>b.pontos) return true;
	else{
		if(a.pontos<b.pontos) return false;
		else{
			if(a.media_cestas>b.media_cestas) return true;
			else{
				if(a.media_cestas<b.media_cestas) return false;
				else{
					if(a.cestas_mar>b.cestas_mar) return true;
					else{
						if(a.cestas_mar<b.cestas_mar) return false;
						else{
							if(a.indice<b.indice) return true;
							else return false;
						}
					}
				}
			}			
		}
	}
}

int main(){
	
	int n, x, y, z, w, k=1;
	
	bool aux = 0;
	
	while(scanf("%d", &n) && n){
		
		if(aux) cout << endl;
		aux = 1;
		
		rep(i, 0, n){
			tim[i].cestas_mar = 0;
			tim[i].cestas_sof = 0;
			tim[i].pontos = 0;
			tim[i].indice = i +1;
		}
			
		
		rep(i,0,n*(n-1)/2){
			
			scanf("%d%d%d%d", &x, &y, &z, &w);
			
			tim[x-1].cestas_mar += y;
			tim[x-1].cestas_sof += w;
			tim[z-1].cestas_mar += w;
			tim[z-1].cestas_sof += y;
			
			if(y>w){
				tim[x-1].pontos += 2;
				tim[z-1].pontos++;
			}
			else{
				tim[z-1].pontos += 2;
				tim[x-1].pontos++;	
			}
		}
		
		rep(i,0,n){
			if(tim[i].cestas_sof==0) tim[i].media_cestas = tim[i].cestas_mar;
			else{
				tim[i].media_cestas = tim[i].cestas_mar / tim[i].cestas_sof;
			}
		}
		
		
		sort(tim, tim+n, cmp);
		
		printf("Instancia %d\n", k++);
		rep(i,0,n){
			if(i!=0) printf(" ");
			printf("%d", tim[i].indice);
		}
		printf("\n");
	}

	return 0;
}

