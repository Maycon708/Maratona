#include<bits/stdc++.h>

using namespace std;

struct camiseta{
	
	char cor[100];
	char tamanho[10];
	char nome[1000];
};

camiseta c[100];

bool cmp(camiseta a, camiseta b){
	
	if(strcmp(a.cor, b.cor) < 0) return true;
	else{
		if(strcmp(a.cor,b.cor) > 0) return false;
		else{
			
			if(strcmp(a.tamanho,b.tamanho)>0) return true;
			else{
				if(strcmp(a.tamanho,b.tamanho) < 0) return false;
				else{
					if(strcmp(a.nome, b.nome) < 0) return true;
					else return false;
				}
			}
			
		}   
	}
}

int main(){
	
	int n;
	bool aux = false;
	
	while(cin >> n && n){
		
		if(aux) cout << endl;
		aux = true;
	
		
		
		for(int i=0; i<n; i++){
		
			cin.ignore();
			gets(c[i].nome);
			
			cin >> c[i].cor >> c[i].tamanho;	
			
		}
		
		sort(c, c+n, cmp);
		
		for(int i=0; i<n; i++){
	
			cout << c[i].cor << " " << c[i].tamanho << " " << c[i].nome << endl;
						
   		}
		
  	}
	
	
}
