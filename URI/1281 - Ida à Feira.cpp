#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<map>

using namespace std;

int main(){
	
	int n, m, p, q;
	double preco;
				 
	string pv, pc;
	
	map<string, double> mp;
	map<string, double> :: iterator it;
	

	cin >> n;
	
	while(n>0){
	
		double aux=0;	
		cin >> m;
		
		while(m>0){
			
			cin >> pv >> preco;
			
			mp[pv] = preco;
			
			m--;
		}
		
		cin >> p;
		
		while(p>0){
			cin >> pc >> q;
			
			for(it = mp.begin(); it != mp.end(); it++){
				if(it->first == pc) aux = aux + q * it->second;
			}
			
			
			p--;
		}
		cout << fixed << setprecision(2);
		cout << "R$ " << aux << endl;
		n--;
				
		mp.clear();		
		
	}
	
	 return(0);
}
