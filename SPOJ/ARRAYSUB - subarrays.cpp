#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int vet[500001];
int SEG[4*500001];

void build_tree(int node, int i, int j) 
{                                       
    if (i == j)                         
    {                                  
        SEG[node] = vet [i];  
        return;
    }

    int left = 2 * node; 
    int right = 2 * node + 1;

    build_tree(left, i, (i + j)/2);  
    build_tree(right, 1 + (i + j)/2, j); 

    SEG[node] = max( SEG[left], SEG[right] ); 
}

int query(int node, int i, int j, int a, int b)
{
    if (i > b || j < a || i > j) return -INF;

    if (i >= a && j <= b) return SEG[node];

    int left = 2 * node;
    int right = 2 * node + 1;

    int q1 = query(left, i, (i + j)/2, a, b);
    int q2 = query(right, (i + j)/2 + 1, j, a, b);

    return max( q1, q2 );
}

int main(){
	
	int n, k;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d", &vet[i] );
		build_tree( 1, 0, n );
		scanf("%d", &k );
		rep( i, 0, n-k ){
			printf("%d ", query( 1, 0, n, i, i+k-1 ));
		}
		printf("%d\n", query( 1, 0, n, n-k, n-1 ));
	}

}

