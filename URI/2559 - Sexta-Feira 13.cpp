#include<bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (int)b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) if(0)cout << #a << " = " << a << " ---- " << #b << " = " << b << endl;
#define F first
#define S second
#define pb push_back
#define N 200020
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct node{
    int valor, sete, treze;
    vector<ii> lazy;
    node(){};
    node( int v, int s, int t ){
        vector<ii> aux;
        swap( lazy, aux );
        valor = v, sete = s, treze = t;
//        aux.clear();
    }
    node operator + ( node q ){
        return node( valor + q.valor, sete + q.sete, treze + q.treze );
    }
        
};

node tree[4*N];
int v[N];

void build( int no, int i , int j );
void update( int no, int i, int j, int a, int b, int z, int v );
void update2( int no, int i, int j, int a, int v );
int query( int no, int i, int j, int a, int b );
void propagate( int no, int i, int j );

int main(){
    int n, q, op, a, b, z, val;
    
    while( scanf("%d", &n ) != EOF ){
        rep( i, 1, n+1 ) scanf("%d", &v[i] );
        build( 1, 1, n );
        scanf("%d", &q );
        while( q-- ){
            scanf("%d", &op );
            switch(op){
                case 1:
                    scanf("%d%d", &a, &val );
                    update2( 1, 1, n, a, val );
                    break;
                case 2:
                    scanf("%d%d%d%d", &a, &b, &z, &val );
                    if( a > b ) swap( a, b );
                    update( 1, 1, n, a, b, z, val );
                    break;
                case 3:
                    scanf("%d%d", &a, &b );
                    if( a > b ) swap( a, b );
                    int ans = query(1, 1, n, a, b );
                    printf("%d\n", ans );
                    break;
            }
        }
    }
    
}

void build( int no, int i, int j ){
    if( i == j ){
        tree[no] = node( v[i], v[i] == 7, v[i] == 13 );
        return;
    }
    int mid = (i+j)/2, L = 2*no, R = L+1;
    build( L, i, mid );
    build( R, mid+1, j );
    tree[no] = tree[L] + tree[R];    
}

void update( int no, int i, int j, int a, int b, int z, int val ){
    propagate( no, i, j );
    if( a > j || b < i || i > j  ) return;
    if( i >= a && j <= b ){
        if( z == 7 && tree[no].sete || z == 13 && tree[no].treze ){
			tree[no].lazy.pb(ii( z, val ));
	    }
	    propagate( no, i, j );
        return;
    }
    int mid = (i+j)/2, L = 2*no, R = L+1;
    update( L, i,   mid, a, b, z, val );
    update( R, mid+1, j, a, b, z, val );
    tree[no] = tree[L] + tree[R];
}

void update2( int no, int i, int j, int a, int val ){
    propagate( no, i, j );
    if( a > j || a < i || i > j ) return;
    if( i == j ){
        tree[no] = node(val, val == 7, val == 13);
        return;
    }
    int mid = (i+j)/2, L = 2*no, R = L+1;
    update2( L, i,   mid, a, val );
    update2( R, mid+1, j, a, val );
    tree[no] = tree[L] + tree[R];
}

void propagate( int no, int aa, int bb ){
    if( tree[no].lazy.empty() ) return;
    int sete = 7, treze = 13;
    vector<ii> v;
    rep( i, 0, tree[no].lazy.size() ){
        ii a = tree[no].lazy[i];
        if( a.F == a.S || (a.F == 7 && !tree[no].sete) || (a.F == 13 && !tree[no].treze) ) continue;
        
		if( a.F == sete && a.S != 7 && a.S != 13 ) v.pb( ii( 7, a.S ) );
        if( a.F == treze && a.S != 7 && a.S != 13 ) v.pb( ii( 13, a.S ) );
        if( a.F == sete ) sete = a.S;
        if( a.F == treze ) treze = a.S;
        
		int qtd , &valor = tree[no].valor, dif = a.S - a.F;
        
		if( a.F == 7 ) qtd = tree[no].sete, tree[no].sete = 0;
        else qtd = tree[no].treze, tree[no].treze = 0;
        
		valor += dif * qtd;
        
		if( a.S == 7 ) tree[no].sete += qtd;
        if( a.S == 13 ) tree[no].treze += qtd;    
    }
    if( aa != bb ){
	    int L = 2*no, R = L+1, vs, vt;
	    vs = vt = 0;
	    rep( i, 0, v.size() ){
	    	if( v[i].F ==  7 ) vs = 1;
	    	if( v[i].F == 13 ) vt = 1;
	        tree[L].lazy.pb(v[i]);
	        tree[R].lazy.pb(v[i]);
	    }
	    
	    if( 7 != sete && !vs ){
	        tree[L].lazy.pb( ii( 7, sete ) );
	        tree[R].lazy.pb( ii( 7, sete ) );
	    }
	    if( 13 != treze && !vt ){
	        tree[L].lazy.pb( ii( 13, treze ) );
	        tree[R].lazy.pb( ii( 13, treze ) );
	    }
	}
    vector<ii> aux;
    swap( aux, tree[no].lazy );
    aux.clear();
}

int query( int no, int i, int j, int a, int b ){
    propagate( no, i, j );
    if( a > j || b < i || i > j ) return 0;
	if( i >= a && j <= b ){
        return tree[no].valor;
    }
    int mid = (i+j)/2, L = 2*no, R = L+1;
    int aa = query( L, i,   mid, a, b );
    int bb = query( R, mid+1, j, a, b );
    return aa + bb;
}
