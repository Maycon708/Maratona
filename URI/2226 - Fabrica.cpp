#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

const int N = 110000;
const int cc = 10;

ll pd[18][N][2][2];
bool aux[18][N][2][2];
int sig[N][10];
int T[N], cnt;
int term[N];

inline int C( char s ){
    return s - '0';
}

void add( string s ){
    int x = 0;
    rep( i, 0, s.size() ){
        int c = C( s[i] );
        if( !sig[x][c] ){
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    term[x] = 1;
}

void aho(){
    
    queue<int> q;
    
    rep( i, 0, cc ){
        int x = sig[0][i];
        if( !x ) continue;
        q.push( x );
        T[x] = 0;
    }
    
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        rep( i, 0, cc ){
            int v = sig[u][i];
            if( !v ) continue;
            int w = T[u];
            while( w && !sig[w][i] ) w = T[w];
            w = sig[w][i];
            T[v] = w;
            term[v] |= term[w];
            q.push( v );
        }
    }
}

int tam;
char s[20];

ll solve( int pos, int no, int prefix, int z = 1 ){
    
    if( pos == tam ) return 1;
    if( aux[pos][no][prefix][z] ) return pd[pos][no][prefix][z];
    aux[pos][no][prefix][z] = 1;
    
    ll ans = 0;
    if( prefix ){
        int u = C( s[pos] ), x;
        rep( i, 0, u ){
            if( !z && !i ) continue;
            x = no;
            while( x && !sig[x][i] ) x = T[x];
            x = sig[x][i];
            if( !term[x] ) ans += solve( pos+1, x, 0 );
        }
        x = no;
        while( x && !sig[x][u] ) x = T[x];
        x = sig[x][u];
        if( !term[x] ) ans += solve( pos+1, x, 1 );
    }
    else{
        rep( i, 0, 10 ){
            if( !z && !i ) continue;
            int x = no;
            while( x && !sig[x][i] ) x = T[x];
            x = sig[x][i];
            if( !term[x] ) ans += solve( pos+1, x, 0 );
        }
    }
    return pd[pos][no][prefix][z] = ans;
}

inline ll SS(){
    ll resp = 0;
    tam = strlen(s);
    rep( i, 0, tam ){
        resp *= 10;
        resp += C( s[i] );
    }
    return resp;
}

void init(){
    cnt = 1;
    memset( sig, 0, sizeof sig );
    memset( aux, 0, sizeof aux );
}

int main(){
    int n;
    char pattern[20];
    while( scanf("%s", s ) != EOF ){
        ll aux = SS();
        if( !aux ) break;
        init();
        scanf("%d", &n );
        bool zero = false;
        while( n-- ){
            scanf("%s", pattern );
            if (strcmp(pattern, "0") == 0) zero = true;
            add( pattern );
        }
        aho();
        ll ans = 0;
        for( int i = tam-1; i > 0; i-- ) ans += solve( i, 0, 0, 0 );
        ans += solve( 0, 0, 1, 0 );
        printf("%llu\n", aux - ans + zero );
    }
}
