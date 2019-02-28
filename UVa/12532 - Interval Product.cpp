#include<bits/stdc++.h>

using namespace std;

long long int vet[2000000];
long long int SEG[4*100000];
const int mod = 101;

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

    SEG[node] = SEG[left] * SEG[right];
}

void update(int node, int i, int j, int a, int valor)
{
    if (i > a || j < a || i > j) return;

    if (i == a && j == a)  
    {
        SEG[node] = valor;  
        return;
    }

    long long int left = 2 * node;
    long long int right = 2 * node + 1;

    update(left, i, (i + j)/2, a, valor);
    update(right, (i + j)/2 + 1, j, a, valor);

    SEG[node] = SEG[left] * SEG[right];
}

long long int query(int node, int i, int j, int a, int b)
{
    if (i > b || j < a || i > j) return 1;

    if (i >= a && j <= b) return SEG[node];

    long long int left = 2 * node;
    long long int right = 2 * node + 1;

    long long int q1 = query(left, i, (i + j)/2, a, b);
    long long int q2 = query(right, (i + j)/2 + 1, j, a, b);

    return q1 * q2;
}

int main()
{

	int n, k, i, v, j;
	char op;
	string s;
	
	while(cin >> n >> k){
		s="";
		for(i=0; i<n; i++) {
			cin >> vet[i];
			if(vet[i]>0) vet[i]=1;
			else{
				if(vet[i]<0) vet[i]=-1;
			}
		}
		
		build_tree(1, 0, n);
				
		while(k--){
			cin >> op;
			
			if(op=='C'){
				cin >> i >> v;
				if(v>0) v=1;
				else{
					if(v<0) v=-1;
				}
				update(1, 0, n, i-1, v);
			}
			else{
				cin >> i >> j;
				
				long long int aux = query(1, 0, n, i-1, j-1);
				if(aux>0) s+="+";
				else{
					if(aux==0) s+= "0";
					else s+= "-";
				}
			}
		}
		cout << s << endl;
	}
	
    return 0;
}
