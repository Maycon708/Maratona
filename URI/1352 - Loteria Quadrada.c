#include <stdlib.h>
#include <stdio.h>

#define rep( i, a, b ) for( i = a; i < b; i++ )

typedef long long int ll;

int main(){
	int  resp[111], n;
	double p;
	resp[2] = 1; resp[3] = 21; resp[4] = 91; resp[5] = 253; resp[6] = 561; resp[7] = 1081; resp[8] = 1891; resp[9] = 3081; resp[10] = 4753; resp[11] = 7021; resp[12] = 10011; resp[13] = 13861; resp[14] = 18721; resp[15] = 24753; resp[16] = 32131; resp[17] = 41041; resp[18] = 51681; resp[19] = 64261; resp[20] = 79003; resp[21] = 96141; resp[22] = 115921; resp[23] = 138601; resp[24] = 164451; resp[25] = 193753; resp[26] = 226801; resp[27] = 263901; resp[28] = 305371; resp[29] = 351541; resp[30] = 402753; resp[31] = 459361; resp[32] = 521731; resp[33] = 590241; resp[34] = 665281; resp[35] = 747253; resp[36] = 836571; resp[37] = 933661; resp[38] = 1038961; resp[39] = 1152921; resp[40] = 1276003; resp[41] = 1408681; resp[42] = 1551441; resp[43] = 1704781; resp[44] = 1869211; resp[45] = 2045253; resp[46] = 2233441; resp[47] = 2434321; resp[48] = 2648451; resp[49] = 2876401; resp[50] = 3118753; resp[51] = 3376101; resp[52] = 3649051; resp[53] = 3938221; resp[54] = 4244241; resp[55] = 4567753; resp[56] = 4909411; resp[57] = 5269881; resp[58] = 5649841; resp[59] = 6049981; resp[60] = 6471003; resp[61] = 6913621; resp[62] = 7378561; resp[63] = 7866561; resp[64] = 8378371; resp[65] = 8914753; resp[66] = 9476481; resp[67] = 10064341; resp[68] = 10679131; resp[69] = 11321661; resp[70] = 11992753; resp[71] = 12693241; resp[72] = 13423971; resp[73] = 14185801; resp[74] = 14979601; resp[75] = 15806253; resp[76] = 16666651; resp[77] = 17561701; resp[78] = 18492321; resp[79] = 19459441; resp[80] = 20464003; resp[81] = 21506961; resp[82] = 22589281; resp[83] = 23711941; resp[84] = 24875931; resp[85] = 26082253; resp[86] = 27331921; resp[87] = 28625961; resp[88] = 29965411; resp[89] = 31351321; resp[90] = 32784753; resp[91] = 34266781; resp[92] = 35798491; resp[93] = 37380981; resp[94] = 39015361; resp[95] = 40702753; resp[96] = 42444291; resp[97] = 44241121; resp[98] = 46094401; resp[99] = 48005301; resp[100] = 49975003; 
	/*
	ll result;
	int sqr[111], i, j, k, u, s, v;

	rep( i, 2, 101 ){
		sqr[i] = 0;
		rep( j, 2, i+1 ){
			u = i - j + 1;
			sqr[i] += u * u;
			rep( k, 2, u+1 ){
				s = k + j - 1;
				if( s <= i ){
					v = ( i - s + 1 );
					sqr[i] += v*v;
				}
			}
		}
		u = i * i + 1;
		ll result = 1;
		rep( j, u - 4, u )
			result *= j;
		resp[i] = result/( 24 * sqr[i] );
	}
	*/
	while( scanf("%d%lf", &n, &p ) && n ){
		printf("%.2f\n", resp[n] * p/100 );
	}

}

