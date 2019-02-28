	#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tc = 0; 
	cin >> n;
	while(n--){
		vector<char> ram(30000 + 100);
		int p = 0;
		string in, inst;
		cin >> in >> inst;
		vector<int> match(inst.size());
		stack<int> s;
		for(int i = 0; i < inst.size(); ++i){
			if (inst[i] == '[')
				s.push(i);
			else if (inst[i] == ']') {
				int m = s.top(); s.pop();
				match[i] = m;
				match[m] = i;
			}
		}
		cout << "Instancia " << ++tc << endl;
		int i = 0, j = 0; 
		while (i < inst.size()) {
			char c = inst[i];
			if (c == '>')
				p++;
			if (c == '<')
				p--;
			if (c == '+')
				ram[p]++;
			if (c == '-')
				ram[p]--;
			if (c == '.')
				cout << ram[p];
			if (c == ',') {
				if (j < in.size())
					ram[p] = in[j++];
				else
					ram[p] = 0;
			}
			if (c == '[') {
				if (ram[p] == 0) {
					i = match[i] + 1;
					continue;
				}
			}
			if (c == ']') {
				i = match[i];
				continue;
			}
			if (c == '#') {
				for (int k = 0; k < 10; ++k)
					cout << ram[k];
			}
			i++;
		}
		cout << endl << endl;
	}
	
	return 0;
}
