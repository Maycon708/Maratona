#include<iostream>
#include<map>

using namespace std;

int main(){
	
	string p;
	bool aux;
	
	map<string, int> mp;
	map<string, int> :: iterator it;
	
	map<int, string> mp2;
	map<int, string> :: iterator it2;
	
	mp["brasil"] = 1;
	mp["alemanha"] = 2;
	mp["austria"] = 3;
	mp["coreia"] = 4;
	mp["espanha"] = 5;
	mp["grecia"] = 6;
	mp["estados-unidos"] = 7;
	mp["inglaterra"] = 8;
	mp["australia"] = 9;
	mp["portugal"] = 10;
	mp["suecia"] = 11;
	mp["turquia"] = 12;
	mp["argentina"] = 13;
	mp["chile"] = 14;
	mp["mexico"] = 15;
	mp["antardida"] = 16;
	mp["canada"] = 17;
	mp["irlanda"] = 18;
	mp["belgica"] = 19;
	mp["italia"] = 20;
	mp["libia"] = 21;
	mp["siria"] = 22;
	mp["marrocos"] = 23;
	mp["japao"] = 24; 
	
	mp2[1] = "Feliz Natal!";
	mp2[2] = "Frohliche Weihnachten!";
	mp2[3] = "Frohe Weihnacht!";
	mp2[4] = "Chuk Sung Tan!";
	mp2[5] = "Feliz Navidad!";
	mp2[6] = "Kala Christougena!";
	mp2[7] = "Merry Christmas!";
	mp2[8] = "Merry Christmas!";
	mp2[9] = "Merry Christmas!";
	mp2[10] = "Feliz Natal!";
	mp2[11] = "God Jul!";
	mp2[12] = "Mutlu Noeller";
	mp2[13] = "Feliz Navidad!";
	mp2[14] = "Feliz Navidad!";
	mp2[15] = "Feliz Navidad!";
	mp2[16] = "Merry Christmas!";
	mp2[17] = "Merry Christmas!";
	mp2[18] = "Nollaig Shona Dhuit!";
	mp2[19] = "Zalig Kerstfeest!";
	mp2[20] = "Buon Natale!";
	mp2[21] = "Buon Natale!";
	mp2[22] = "Milad Mubarak!";
	mp2[23] = "Milad Mubarak!";
	mp2[24] = "Merii Kurisumasu!"; 
	
	while(cin >> p){
		if(mp[p]!=0){	
			cout << mp2[mp[p]] << endl;
			aux = true;
		}
		else cout << "--- NOT FOUND ---" << endl;
	}
	 
	return(0);
}
