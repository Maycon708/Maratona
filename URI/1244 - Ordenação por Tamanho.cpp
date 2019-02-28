#include<bits/stdc++.h>

using namespace std;

struct A{
	string n;
	int t;
	int indice;
};


bool cmp(A a, A b){
	if(a.t > b.t) return true;
	else{
		if(a.t < b.t) return false;
		else{
			if(a.indice < b.indice) return true;
			else return false;
		}
	}
}

A aux[60];

int main(){
	
	
	int n, k;
	char c[10000];
	string s;
	
	cin >> n;
	cin.ignore();
	
	while(n--){
		
		s = "";
		k = 0;
		
		gets(c);
		
		int tam = strlen(c);
		
		for(int i=0; i<tam; i++){
			if(c[i]!=' ') s+=c[i];
			else{
				aux[k].n = s;
				aux[k].t = s.size();
				aux[k].indice = k;
				k++; 
				s="";
			}
		}
		aux[k].n = s;
		aux[k].t = s.size();
		aux[k].indice = k;
		k++; 
		s="";
		
		sort(aux, aux+k, cmp);
		
		for(int i=0; i<k; i++){
			if(i!=0) cout << " ";
			cout << aux[i].n;
		}
		cout << endl;
		
	}
	
	return 0;
}
