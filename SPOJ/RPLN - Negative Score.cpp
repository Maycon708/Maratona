#include<bits/stdc++.h>

using namespace std;

int vet[500001];
int SEG[4*500001];

const int INF = 0x3f3f3f3f;

void build_tree(int node, int i, int j) 
{                                       
    if (i == j)                         
    {                                  
        SEG[node] = vet [i];  
        return;
    }

    int left = 2 * node; 
    int right = 2 * node + 1;

    build_tree(left, i, (i + j)/2);  
    build_tree(right, 1 + (i + j)/2, j); 

    SEG[node] = min(SEG[left],SEG[right]); 
}

int query(int node, int i, int j, int a, int b)
{
    if (i > b || j < a || i > j) return INF;

    if (i >= a && j <= b) return SEG[node];

    int left = 2 * node;
    int right = 2 * node + 1;

    int q1 = query(left, i, (i + j)/2, a, b);
    int q2 = query(right, (i + j)/2 + 1, j, a, b);

    return min(q1,q2);
}

vector < int > v;

int main(){
    
    int n, m, x, y, cont=0, t;
    
    cin >> t;
    
    for(int k=1; k<=t; k++){
        
        //if(k!=1) cout << endl;
        cin >> n >> m;
    
        for(int i=0; i<n; i++) cin >> vet[i];
        
        build_tree(1, 0, n);
        
        
        
        while(m--){
            cin >> x >> y;
            int aux = query(1, 0, n, x-1, y-1);
            v.push_back(aux);
        }
        
        printf("Scenario #%d:\n\n", k);
        
        int mm = v.size();
        
        for(int i=0; i<mm; i++){
            printf("%d\n", v[i]);
        }
        v.clear();
    }
    
    return 0;
}
