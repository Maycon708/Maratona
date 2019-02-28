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

#define MAXV 100001
 
int pai[MAXV];

void init(int v){
    for( int i=1; i <= v; i++ )
        pai[i] = i;
}
 
int findset(int i){ 
    if( i != pai[i] ) 
        pai[i] = findset(pai[i]);
    return pai[i];
}
  
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa;
}
 
bool sameset(int a, int b){
    return findset(a) == findset(b); 
}

int main(){
	
	int n, m, u, v;
	char op;
	while( scanf("%d%d", &n, &m ) != EOF ){
		init(n);
		while(m--){
			scanf(" %c%d%d", &op, &u, &v );
			if( op == 'F' ) unionset(u,v);
			else printf("%s\n", sameset(u,v) ? "S" : "N" );		
		}
	}
}
