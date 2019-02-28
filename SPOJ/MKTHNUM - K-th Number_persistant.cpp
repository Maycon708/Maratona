#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const int N = 100001;

int L[N*100], R[N*100], root[N*100];
int tr[N*100], cnt;

void build(int no, int l, int r){
	L[no] = cnt++;
	R[no] = cnt++;
	if(l == r) return;
	int mid = (l+r)/2;
	build(L[no], l, mid);
	build(R[no], mid+1, r);
}

int update(int no, int l, int r, int p){
	int nxt = (cnt++);
	L[nxt] = L[no];
	R[nxt] = R[no];
	
	if(l == r){
		tr[nxt] = 1;
		return nxt;
	}
	int mid = (l+r)/2;
	
	if(p <= mid) L[nxt] = update(L[no], l, mid, p);
	else R[nxt] = update(R[no], mid+1, r, p);
	
	tr[nxt] = tr[L[nxt]] + tr[R[nxt]];
	
	return nxt;
}

int query(int no1, int no2, int l, int r, int k){
	if(l == r){
		if(k) return -1;
		return l;
	}
	int mid = (l+r)/2;
	int qtd = tr[L[no2]] - tr[L[no1]];
	if(qtd > k)
		return query(L[no1], L[no2], l, mid, k);
	else
		return query(R[no1], R[no2], mid+1, r, k-qtd);
}

int v[N], aux[N];

int main(){

	int n, m, x, y, k;
	while( scanf("%d%d", &n, &m ) != EOF ){
		cnt = 1;
		map<int, int> mp;
		build(root[0], 0, n-1);	
		for( int i = 1; i <= n; i++ ){
			scanf("%d", &v[i] );
			aux[i-1] = v[i];
		}
		sort( aux, aux+n );
		rep( i, 0, n ){
			mp[aux[i]] = i;
		}
		for( int i = 1; i <= n; i++ ){
			root[i] = update(root[i-1], 0, n-1, mp[v[i]]);			
		}
		while( m-- ){ 
			scanf("%d%d%d", &x, &y, &k ); // késimo elemento(ordenado) no intervalo [x, y]
			int ans = query(root[x-1], root[y], 0, n-1, k-1);
			printf("%d\n", aux[ans] );
		}
	}
	return 0;
}
