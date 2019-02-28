#include <bits/stdc++.h>
#define MAXV 101000

using namespace std;

int n, bit[MAXV], vet[MAXV];

void update(int x, int v){
    while(x <= n){
        bit[x] = bit[x] + v;
        x = x + (x&-x);
    }
}

int query(int x){
    int ans = 0;
    while(x > 0){
        ans = ans + bit[x];
        x = x - (x&-x);
    }
    return ans;
}

int main() {
    int v;
    char letra;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &v);
        vet[i] = v;
        update(i,v);
    }
    while(scanf(" %c %d", &letra, &v) != EOF){
        if(letra == 'a'){
            update(v,-vet[v]);
        }
        else{
            if(v == 1){
                printf("0\n");
            }
            else{
                printf("%d\n", query(v-1));
            }
        }
    }
    return 0;
}
