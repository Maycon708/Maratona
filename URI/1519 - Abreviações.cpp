#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> si;

char s[20010];
int size;
map<string, int> dici[30];
vector<si> vetor[30];

bool ordena(si a, si b) {
	return a.second > b.second;
}

int main() {
	string s_aux;
	
	while(1) {
		gets(s);
		if(s[0] == '.') break;
		size = strlen(s);
		if(size > 10000) printf("beep\n");
		
		for(int i=0; i<30; i++) {
			dici[i].clear();
		}
		s_aux = "";
		
		s[size++] = ' ';
		for(int i=0; i<size; i++) {
			if(s[i] == ' ') {
				if((int)s_aux.size() < 3) {
					s_aux = "";
					continue;
				}
				
				if(dici[(int)s_aux[0]-'a'].count(s_aux)) {
					dici[(int)s_aux[0]-'a'][s_aux] += (int)s_aux.size()-2;
				} else {
					dici[(int)s_aux[0]-'a'][s_aux] = (int)s_aux.size()-2;
				}
				
				s_aux = "";
			} else {
				s_aux += s[i];
			}
		}
		
		
		int cont = 0;
		for(int i=0; i<30; i++) {
			vetor[i].clear();
			
			if((int)dici[i].size()){
				for(map<string, int>::iterator it = dici[i].begin(); it != dici[i].end(); it++) {
					vetor[i].push_back(si(it -> first, it -> second));
				}
			
				sort(vetor[i].begin(), vetor[i].end(), ordena);
				if((int)vetor[i].size() > 1 && vetor[i][0].second == vetor[i][1].second) printf("Beep %d\n", i);
				cont++;
			}
		}
		
		bool first = true;
		s_aux = "";
		for(int i=0; i<size; i++) {
			if(s[i] == ' ') {
				if((int)s_aux.size() < 3) {
					if(!first) cout << " " << s_aux;
					else cout << s_aux;
					first = false;
					
					s_aux = "";
					continue;
				}
				
				if(vetor[(int)s_aux[0]-'a'][0].first == s_aux) {
					if(!first) cout << " " << s_aux[0] << ".";
					else cout << s_aux[0] << ".";
					first = false;
				} else {
					if(!first) cout << " " << s_aux;
					else cout << s_aux;
					first = false;
				}
				
				s_aux = "";
			} else {
				s_aux += s[i];
			}
		}
		
		printf("\n%d\n", cont);
		for(int i=0; i<30; i++) if((int)vetor[i].size()) {
			cout << vetor[i][0].first[0] << ". = " << vetor[i][0].first << endl;
		}
	}
}

