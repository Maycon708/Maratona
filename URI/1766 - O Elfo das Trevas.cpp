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
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

struct rena{
	
	char nome[110];
	int p, i;
	double h;
	
};

rena v[1111];

int n, m;

bool cmp(rena a, rena b){
	
	if(a.p>b.p) return true;
	if(a.p<b.p) return false;
	if(a.i<b.i) return true;
	if(a.i>b.i) return false;
	if(a.h<b.h) return true;
	if(a.h>b.h) return false;
	if(strcmp(a.nome, b.nome)<0) return true;
	return false;
	
}

int main(){
//	freopen("code.in", "r", stdin);
// 	freopen("out_maycon.txt", "w", stdout);
	
	int t;
	
	scanf("%d", &t);
	
	rep(k,1,t+1){
		
		scanf("%d%d", &n, &m);
		
		rep(i,0,n){
			
			scanf(" %s %d %d %lf", v[i].nome, &v[i].p, &v[i].i, &v[i].h);	
	
		}
		
		sort(v, v+n, cmp);
		
		printf("CENARIO {%d}\n", k);
		rep(i,0,m){
			printf("%d - %s\n", i+1, v[i].nome);
		}
		
	}
	
	return 0;
}


