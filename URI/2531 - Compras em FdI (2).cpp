#include <bits/stdc++.h>
using namespace std;

int tree_menor[4*100010];
int tree_maior[4*100010];
int N;
int op;
int v[100010];

void build(int no, int a, int b){
    
    if(a>b)
        return;// na duvida se um intervalo vai ser maior que o outro
    
    if(a == b){
        tree_menor[no] = v[a]; 
        tree_maior[no] = v[a];
        return; 
    }
    int e = 2*no;
    int d = e+1;
    int mid = (a+b)/2;
    
    build(e, a, mid); // para a esquerda ate o meio
    build(d, mid+1, b); // para a direita ate o fim
   
    tree_maior[no] = max(tree_maior[e], tree_maior[d]);  
    tree_menor[no] = min(tree_menor[e], tree_menor[d]); 
}

int maior, menor;

void query(int no, int a, int b, int x, int y){
    if(y < a || x > b)
        return;
    if(x <= a && y >= b){
        menor = min( menor, tree_menor[no] );
        maior = max( maior, tree_maior[no] );
        return;
    }
    
    int e = 2*no;
    int d = e+1;
    int mid = (a+b)/2;
    
    query(e, a, mid, x, y); // para a esquerda ate o meio
    query(d, mid+1, b, x, y); // para a direita ate o fim

    return; 
}

void update(int no, int a, int b, int i, int V){
    if(i < a || i > b)
        return;
    if(a == i && a == b){
        tree_menor[no] = V;
        tree_maior[no] = V;
        return;
    }
    
    int e = 2*no;
    int d = e+1;
    int mid = (a+b)/2;
    
    update(e, a, mid, i, V); // para a esquerda ate o meio
    update(d, mid+1, b, i, V); // para a direita ate o fim

    tree_maior[no] = max(tree_maior[e], tree_maior[d]); 
    tree_menor[no] = min(tree_menor[e], tree_menor[d]); 
}

int main(){
    int Q, op;
    
    while(cin >> N){
        for(int h=0; h<N; h++){
            scanf("%d", &v[h]);
        }
        
        build(1,0, N-1);
    
        scanf("%d", &Q);
        int p, lj, ljf, x, y, res;
        
        while(Q--){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %d", &lj, &p);
                update(1, 0, N-1, lj-1, p);   
            }
            if (op == 2){
                scanf("%d %d", &lj, &ljf);
                maior = -99999999;
                menor = +99999999;
                query( 1, 0, N-1, lj-1, ljf-1 );
                res = maior - menor;
                printf("%d\n", res );
            }
        }
    }
    
    
    return 0;
}
