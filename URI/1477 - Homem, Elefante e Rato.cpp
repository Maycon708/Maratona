#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 100005
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

struct node{
    int h, e, r;
};
 
int N;
int lazy[MAXV*4];
node tree[MAXV*4];
node zero, ans;
 
void build(int no, int i, int j){
 
    int left = 2*no, right = 2*no+1;
    int mid = (i+j)/2;
 
    if(i == j){
        tree[no].h = 1;
        tree[no].e = 0;
        tree[no].r = 0;
        return;
    }
 
    build(left, i, mid);
    build(right, mid+1, j);
 
    tree[no].h = tree[left].h + tree[right].h;
    tree[no].e = tree[left].e + tree[right].e;
    tree[no].r = tree[left].r + tree[right].r;
}
 
node query(int no, int i, int j, int a, int b){
 
    int left = 2*no, right = 2*no+1;
    int mid = (i+j)/2;
 
    if(j < a || i > b) return zero;
 
    if(lazy[no] != 0){
 
        int qq = lazy[no]%3;
        if(qq == 1){
            swap(tree[no].h, tree[no].e);
            swap(tree[no].h, tree[no].r);
        }
        else if(qq == 2){
            swap(tree[no].h, tree[no].e);
            swap(tree[no].e, tree[no].r);
        }
 
        if(i != j){
            lazy[left] += lazy[no];
            lazy[right] += lazy[no];
        }
 
        lazy[no] = 0;
    }
 
    if(i >= a && j <= b) return tree[no];
 
    node q1 = query(left, i, mid, a, b);
    node q2 = query(right, mid+1, j, a, b);
 
    ans.h = q1.h + q2.h;
    ans.e = q1.e + q2.e;
    ans.r = q1.r + q2.r;
 
    return ans;
}
 
void update(int no, int i, int j, int a, int b){
 
    int left = 2*no, right = 2*no+1;
    int mid = (i+j)/2;
 
    if(lazy[no] != 0){
 
        int qq = lazy[no]%3;
        if(qq == 1){
            swap(tree[no].h, tree[no].e);
            swap(tree[no].h, tree[no].r);
        }
        else if(qq == 2){
            swap(tree[no].h, tree[no].e);
            swap(tree[no].e, tree[no].r);
        }
 
        if(i != j){
            lazy[left] += lazy[no];
            lazy[right] += lazy[no];
        }
 
        lazy[no] = 0;
    }
 
    if(j < a || i > b) return;
 
    if(i >= a && j <= b){
        swap(tree[no].h, tree[no].e);
        swap(tree[no].h, tree[no].r);
        if(i != j){
            lazy[left]++;
            lazy[right]++;
        }
        return;
    }
 
    update(left, i, mid, a, b);
    update(right, mid+1, j, a, b);
 
    tree[no].h = tree[left].h + tree[right].h;
    tree[no].e = tree[left].e + tree[right].e;
    tree[no].r = tree[left].r + tree[right].r;
}
 
int main(){
 
    int q, x, y;
    char op;
    node ans;
 
    while(cin >> N >> q){
 
        zero.h = zero.e = zero.r = 0;
 
        rep(i,0,4*N)
            lazy[i] = 0;
 
        build(1, 0, N);
 
        while(q--){
            scanf(" %c%d%d",&op,&x,&y);
            --x; --y;
            if(op == 'C'){
                ans = query(1,0,N,x,y);
                printf("%d %d %d\n",ans.h, ans.e, ans.r);
            }
            else{
                update(1,0,N,x,y);
            }
        }
 
        cout << endl;
    }
 
    return 0;
}
