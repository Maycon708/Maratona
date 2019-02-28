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

typedef struct item * pitem;
struct item {
    int prior, cnt, value, menor, maior;
    bool rev, asc, desc, eq;
    pitem l, r;
    item(){};
    item( int v ){
    	prior = rand();
    	maior = menor = value = v;
    	asc = desc = eq = 1;
		rev = 0;
    	cnt = 1;
    	l = r = NULL;
	}
};

void reset(pitem t){
	t->maior = t->menor = t->value;
	t->asc = t->desc = t->eq = 1;
}
 
void combine(pitem &t, pitem l, pitem r){
	if(!l || !r){
		t = l ? l : r;
		return;
	}
	if( l->eq && r->eq && l->value == t->value && r->value == t->value ) t->eq = 1;
	else t->eq = 0;
	if( l->asc && r->asc && l->maior <= t->value && t->value <= r->menor ) t->asc = 1;
	else t->asc = 0;
	if( l->desc && r->desc && l->menor >= t->value && t->value >= r->maior ) t->desc = 1;
	else t->desc = 0;
	t->menor = min( t->value, min( l->menor, r->menor ) );
	t->maior = max( t->value, max( l->maior, r->maior ) );
}
 
void operation(pitem t){
	if(!t)
		return;
	reset(t);
	combine(t, t->l, t);
	combine(t, t, t->r);
}

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem &t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
	operation(t);
}

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
	operation(t);
}

void reverse(pitem &t, int l, int r){
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output(pitem t) {
    if (!t)  return;
    push(t);
    output (t->l);
    printf ("%d ", t->value);
    output (t->r);
}

void rangeQuery(pitem &t, int l, int r ){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, r - l + 1 );
	
	if(t->eq) puts("ALL EQUAL");
	else if(t->asc) puts("NON DECREASING");
	else if(t->desc) puts("NON INCREASING");
	else puts("NONE");
	
	merge(mid, L, t);
	merge(t, mid, R);
}

void update(pitem &t, int l, int val){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, 1 );
	t->value = val;
	merge(mid, L, t);
	merge(t, mid, R);
}

void insert(pitem &t, int l, int val ){
	pitem T1, T2;
	split(t, T1, T2, l );
	merge(T1, T1, new item(val) );
	merge(t, T1, T2);
}

void erase( pitem &t, int l ){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, 1 );
	merge(t, L, R);
}

int query( pitem &t, int l ){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, 1 );
	
	int ans = t->value;
	
	merge(mid, L, t);
	merge(t, mid, R);
	
	return ans;
}

int main(){
	int n, v, q, op, a, b;
	while( scanf("%d", &n ) != EOF ){
		pitem Treap = NULL;
		rep( i, 0, n ){
			scanf("%d", &v );
			if( !i ) 
				Treap = new item(v);
			else
				merge(Treap, Treap, new item(v)); 
		}
//		output(Treap);
//		printf("\n");
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &op, &a );
			a--;
			if( op == 3 ){
				erase(Treap, a);
				continue;
			}
			scanf("%d", &b );
			if( op == 0 ){
				b--;
				int va = query(Treap, a);
				int vb = query(Treap, b);
				update(Treap, a, vb);
				update(Treap, b, va);
			}
			else if( op == 1 ){
				update( Treap, a, b );
			}
			else if( op == 2 ){
				insert(Treap, a, b );
			}
			else{
				b--;
				rangeQuery(Treap, a, b);
			}
//			output(Treap);
//			printf("\n");
		}
	}
}

