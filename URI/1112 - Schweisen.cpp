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

#define N 1010

int bit[N][N], n, m;

void update( int x, int y, int v ){
	for( int i = x; i <= n; i += ( i&-i ))
		for( int j = y; j <= m; j += (j&-j )) 
			bit[i][j] += v;
}

int query( int x, int y ){
	int sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		for( int j = y; j > 0; j -= (j&-j )) 
			sum += bit[i][j];
	return sum;
}

int main(){
     
    int cont, p, q, valor, x, y, x1, y1, x2, y2;
    char op;
    
    while( scanf("%d%d%d", &n, &m, &p ) != EOF && n ){
        
		for(int i = 0;i <= n; i++ ) for(int j = 0; j <= m; j++ ) bit[i][j] = 0;
        
        scanf("%d", &q);
        
        while(q--){
            cin >> op;
            
            if(op=='A'){
                scanf("%d%d%d", &valor, &x, &y);
                update(x+1,y+1,valor);
            }
            else{
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                if(x2<x1) swap(x1, x2);
                if(y2<y1) swap(y1, y2);
                cont = query(x2+1,y2+1) - query(x1,y2+1) - query(x2+1,y1) + query(x1,y1);
                printf("%d\n", cont*p);
            }
        }
        cout << endl;
    }
        
    return 0;
}
