#include<bits/stdc++.h>

using namespace std;

int vet[50001];
int SEG[4*50001];

const int INF = 0x3f3f3f;

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

    SEG[node] = max(SEG[left],SEG[right]); 
}

void update(int node, int i, int j, int a, int valor) 
{
    if (i > a || j < a || i > j) return;

    if (i == a && j == a)  
    {
        SEG[node] = valor;  
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;

    update(left, i, (i + j)/2, a, valor);
    update(right, (i + j)/2 + 1, j, a, valor);

    SEG[node] = SEG[left] + SEG[right];  
}

int query(int node, int i, int j, int a, int b)
{
    if (i > b || j < a || i > j) return -INF;

    if (i >= a && j <= b) return SEG[node];

    int left = 2 * node;
    int right = 2 * node + 1;

    int q1 = query(left, i, (i + j)/2, a, b);
    int q2 = query(right, (i + j)/2 + 1, j, a, b);

    return max(q1,q2);
}

int main(){
	
	int n, m, x, y, cont = 0;
	
	cin >> n >> m;
	
	for( int i = 0; i < n; i++ ) cin >> vet[i];
	
	build_tree(1, 0, n);
	
	while(m--){
		cin >> x >> y;
		int aux = query(1, 0, n, x-1, y-2);
		if( aux <= vet[x-1] ){
			cont++;
		}
		cout << aux << endl;
	}
	
	cout << cont << endl;
	
	return 0;
}
