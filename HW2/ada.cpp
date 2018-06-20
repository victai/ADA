#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
	string n;
	cin >> n;
	int len = n.size();
	string s1 (len/2, '4');
	string s2 (len/2, '7');
	string ans = s1+s2;
	// for(int i = 0; i < len; i++)	printf("%d\n", n[i]-'0');
	if(len % 2 == 0){
		int flag = 0;
		int pos_7 = len/2, pos_4 = -1, cnt_7 = 0;
		if(n[0]-'0' > 7){
			printf("%s\n", ('4'+ans+'7').c_str());
			return 0;
		}
		for(int i = 0; i < len; i++){
			// printf("%d\n", pos_4);
			// printf("cnt_7:%d\n", cnt_7);
			if(cnt_7 >= len/2){
				if(n[i] > 4){
					flag = 1;
					break;
				}
				else{
					ans[i] = '4';
					continue;
				}
			}
			// printf("%d %d\n", len-i, len/2-cnt_7);
			if(len-i <= len/2-cnt_7){
				ans[i] = '7';
				if(n[i]-'0' > 7){
				// printf("%s\n", ans.c_str());
					if(pos_4 == -1){
						flag = 1;
						break;
					}
					// printf("dkjaflj\n");
					ans[pos_4] = '7';
					ans[i] = '4';
					// printf("%s\n", ans.c_str());
					pos_4++;
					cnt_7++;
					for(int j = i+1;j < len; j++){
						if(j + len/2 - cnt_7 >= len)	ans[j] = '7';
						else	ans[j] = '4';
					}
					break;
				}	
				continue;
			}
			if(n[i]-'0' == 4){
				pos_4 = i;
				ans[i] = '4';
			}
			if(n[i]-'0' == 7){
				ans[i] = '7';
				if(i >= len/2){
					pos_7++;
					cnt_7++;
					continue;
				}
				ans[pos_7] = '4';
			}
			if(n[i]-'0' < 7 && n[i]-'0' > 4){
				ans[i] = '7';
				// printf("1---%s\n", ans.c_str());
				cnt_7++;
				// printf("%d\n", cnt_7);
				for(int j = i+1;j < len; j++){
					if(j + len/2 - cnt_7 >= len)	ans[j] = '7';
					else	ans[j] = '4';
				}
				printf("%s\n", ans.c_str());
				return 0;
			}
			if(n[i]-'0' < 4){
				ans[i] = '4';
				for(int j = i+1;j < len; j++){
					if(j + len/2 - cnt_7 >= len)	ans[j] = '7';
					else	ans[j] = '4';
				}
				printf("%s\n", ans.c_str());
				return 0;
			}
			// printf("---%d\n", n[i]-'0');
			if(n[i]-'0' > 7){
				// printf("%s\n", ans.c_str());
				if(pos_4 == -1){
					flag = 1;
					break;
				}
				// printf("dkjaflj\n");
				ans[pos_4] = '7';
				ans[i] = '4';
				// printf("%s\n", ans.c_str());
				pos_4++;
				cnt_7++;
				for(int j = i+1;j < len; j++){
					if(j + len/2 - cnt_7 >= len)	ans[j] = '7';
					else	ans[j] = '4';
				}
				break;
			}	
		}
		if(flag)	printf("%s\n", ('4' + s1 + '7' + s2).c_str());
		else	printf("%s\n", ans.c_str());
	}
	else	printf("%s\n", ('4' + s1 + '7' + s2).c_str());
	return 0;
}	