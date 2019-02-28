#include<bits/stdc++.h>

# define rep( i, a, b ) for( int i = a; i < b; i++ )

using namespace std;

int n, p[110], v[110], pd[110][55], mat[110][55];

int solve( int pos, int cap ){
    if( pos == n ) return 0;
    if( pd[pos][cap] != -1 ) return pd[pos][cap];
    int a, b = 0;
    a = solve( pos+1, cap );
    if( cap >= p[pos] ) b = solve( pos+1, cap - p[pos] ) + v[pos];
    if( b > a ) mat[pos][cap] = 1;
    else mat[pos][cap] = 0;
    return pd[pos][cap] = max( a, b );
}

int peso, cnt;

void back( int pos, int cap ){
    if( pos == n ) return;
    if( mat[pos][cap] ){
        peso += p[pos];
        back( pos+1, cap - p[pos] );
    }
    else{
        cnt++;
        back( pos+1, cap );
    }
}

int main(){
    
    int t;
    scanf("%d", &t );
    while(  t-- ){
        scanf("%d", &n );
        peso = 0, cnt = 0;
        rep( i, 0, n ){
            scanf("%d%d", &v[i], &p[i] );
        }
        memset( pd, -1, sizeof pd );
        printf("%d brinquedos\n", solve( 0, 50 ) );
        back( 0, 50 );
        printf("Peso: %d kg\n", peso );
        printf("sobra(m) %d pacote(s)\n", cnt );
        printf("\n");
    }
    return 0;
}
