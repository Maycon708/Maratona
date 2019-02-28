#include <bits/stdc++.h>

#define INF 1LL << 60;
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) if(1)cout << #x << " = " << x << endl;
#define debug2(x,y) if(1)cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define infinity 1111111111111111111ll

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll C[8011];
ll sums[8111];
ll F[811][8111];
int P[811][8111];

ll cost(int i, int j) {
    return i > j ? 0 : (sums[j] - sums[i-1]) * (j - i + 1);
}

void fill(int g, int l1, int l2, int p1, int p2) {
    if (l1 > l2) return;

    int lm = ( l1 + l2 ) >> 1;
    P[g][lm] = -1;
    F[g][lm] = infinity;
    for( int k = p1; k <= p2; k++ ){
        ll new_cost = F[g-1][k] + cost( k+1, lm );
        if (F[g][lm] > new_cost ){
            F[g][lm] = new_cost;
            P[g][lm] = k;
        }
    }

    fill(g, l1, lm-1, p1, P[g][lm]);
    fill(g, lm+1, l2, P[g][lm], p2);
}

int main() {
    int n, k;
    while( scanf("%d%d", &n, &k ) != EOF ){
	    sums[0] = 0;
	    for (int i = 1; i <= n; i++) {
	        scanf("%lld", &C[i] );
	        sums[i] = sums[i-1] + C[i];
	    }
	
	    for( int l = 0; l <= n; l++ ){
	        F[1][l] = cost(1,l);
	        P[1][l] = 0;
	    }
	
	    for( int g = 2; g <= k; g++ ){
	        fill(g, 0, n, 0, n);
	    }    
	    printf("%lld\n", F[k][n] );
	}
}
