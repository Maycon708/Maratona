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

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc(), aux = 0;
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) x *= -1;
}

typedef struct item * pitem;
struct item {
    int prior, cnt, qt[26];
    char value;
    bool rev;
    pitem l, r;
    item(){};
    item( char v ){
    	prior = rand();
    	value = v;
		rep( i, 0, 26 ) qt[i] = 0;
		qt[v-'a'] = 1;
    	rev = 0;
    	cnt = 1;
    	l = r = NULL;
	}
};

void reset(pitem t){
	rep( i, 0, 26 ) t->qt[i] = 0;
	t->qt[t->value-'a'] = 1;
}
 
void combine(pitem &t, pitem l, pitem r){
	if(!l || !r){
		t = l ? l : r;
		return;
	}
	rep( i, 0, 26 )
		t->qt[i] = l->qt[i] + r->qt[i];
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

void merge (pitem & t, pitem l, pitem r) {
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

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
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

void reverse (pitem t, int l, int r){
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push(t);
    output (t->l);
    printf ("%c", t->value);
    output (t->r);
}

int rangeQuery(pitem t, int l, int r, int v){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, r - l + 1 );
	int ans = t->qt[v];
	merge(mid, L, t);
	merge(t, mid, R);
	return ans;
}

void findL( pitem t, int &ans, int v, bool &find ){
	if( !t || !t->qt[v] ) return;
	push(t);
	if( t->l && t->l->qt[v] >= 1 ) findL( t->l, ans, v, find );
	else if( t->value -'a' == v ){
		find = true;
		ans += cnt(t->l);
	}
	else if( t->r && t->r->qt[v] >= 1 ){
		ans = ans + cnt(t->l) + 1;
		findL( t->r, ans, v, find );
	} 
}


void findR( pitem t, int &ans, int v ){
	if( !t || !t->qt[v] ) return;
	push(t);
	if( t->r && t->r->qt[v] >= 1 ){
		ans = ans + cnt(t->l) + 1;
		findR( t->r, ans, v );
	}	
	else if( t->value -'a' == v ){
		ans += cnt(t->l);
	}
	else if( t->l && t->l->qt[v] >= 1 ){
		findR( t->l, ans, v );
	} 
}

ii rangeQuery2( pitem t, int l, int r, int v ){
	ii ans;
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, r - l + 1 );
	bool find = 0;
	findL( t, ans.first, v, find );
	findR( t, ans.second, v );
	merge(mid, L, t);
	merge(t, mid, R);
	if( !find ) return ii(-1, -1);
	return ans;
}

void update(pitem t, int l, char val){
	pitem L, mid, R;
	split(t, L, mid, l );
	split(mid, t, R, 1 );
	t->value = val;
	merge(mid, L, t);
	merge(t, mid, R);
}

char v[1000100];

int main(){
	int n, q, op, a, b;
	char c;
	while(42){
		scan(n);
		if( !n ) break;
		scan(q);
		pitem Treap, T1, T2;
		
		gets(v);
				
		rep( i, 0, n ){
			if(i == 0)
				Treap = new item(v[i]);
			else
				merge(Treap, Treap, new item(v[i]));
		}
		ii ans;
		while(q--){
			scan(op);
			scan(a); a--;
			switch(op){
				case 1:
					scan(b); b--;
					if( a > b ) swap( a, b );
					scanf(" %c", &c ); 
					printf("%d\n", rangeQuery( Treap, a, b, c-'a' ) );
					break;
				case 2: 
					scan(b); b--;
					if( a > b ) swap( a, b );
					scanf(" %c", &c ); 
					ans = rangeQuery2( Treap, a, b, c-'a' );
					if( ans.first == -1 ) puts("-1");
					else printf("%d %d\n", a+ans.first+1, a+ans.second+1 );
					break;
				case 3: 
					scan(b); b--;
					if( a > b ) swap( a, b );
					reverse( Treap, a, b );
					break;
				case 4:
					scanf(" %c", &c );
					split( Treap, T1, T2, a );
					merge(T1, T1, new item(c) );
					merge( Treap, T1, T2 );
					break;
			}
		}
		output(Treap);
		printf("\n");
		return 0;
	}
}

