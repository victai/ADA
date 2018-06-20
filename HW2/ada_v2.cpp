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
	string ans (len, '4');
	if(len % 2 == 0){
		int flag = 0, tmp = -1;
		int pos_4 = -1, cnt_7 = 0, certain = 0, remain;
		if(n[0]-'0' > 7){
			printf("%s\n", ('4' + s1 + '7' + s2).c_str());
			return 0;
		}
		for(int i = 0; i < len; i++){
			if(flag == 1)	break;
			if(n[i]-'0' < 4){
				for(int j =	i; j >= 0; j--)
					if(ans[j] == '7')	certain++;
				remain = len/2 - certain;
				for(int j = len-1; j >= 0; j--){
					if(j > i){
						if(remain == 0){
							ans[j] = '4';
							continue;
						}
						ans[j] = '7';
						remain--;
					}
					else{
						if(remain <= 0)	break;
						if(ans[j] == '7')	continue;
						else{
							ans[j] = '7';
							remain--;
						}
					}
				}
				printf("%s\n", ans.c_str());
				return 0;
			}
			if(n[i]-'0' == 4)	pos_4 = i;
			if(n[i]-'0' > 4 && n[i]-'0' <= 7){
				if(cnt_7 >= len/2){
					if(pos_4 == -1){flag = 1; break;}
					int tmp = -1, x = 0;
					for(int j = i; j >= 0; j--){
						if(ans[j] == '7')	x = 1;
						if(x==1 && ans[j] == '4')	{tmp = j; break;}
					}
					if(tmp != -1){
						ans[tmp] = '7';
						ans[tmp+1] = '4';
						for(int j =	tmp; j >= 0; j--)
							if(ans[j] == '7')	certain++;
						remain = len/2 - certain;
						for(int j = len-1; j >= 0; j--){
							if(j > tmp){
								if(remain == 0){
									ans[j] = '4';
									continue;
								}
								ans[j] = '7';
								remain--;
							}
							else{
								if(remain <= 0)	break;
								if(ans[j] == '7')	continue;
								else{
									ans[j] = '7';
									remain--;
								}
							}
						}
						printf("%s\n", ans.c_str());
						return 0;
					}
					else{
						for(int j = i; j < len; j++)
							if(n[j] > 4){flag = 1; break;}
						if(flag == 1)	break;
					}
				}
				ans[i] = '7';
				cnt_7++;
				if(n[i]-'0' == 7){
					if(i == len-1 && cnt_7 == len/2){printf("%s\n", ans.c_str());	return 0;}	
					continue;
				}
				for(int j =	i; j >= 0; j--)
					if(ans[j] == '7')	certain++;
				remain = len/2 - certain;
				for(int j = len-1; j >= 0; j--){
					if(j > i){
						if(remain == 0){
							ans[j] = '4';
							continue;
						}
						ans[j] = '7';
						remain--;
					}
					else{
						if(remain <= 0)	break;
						if(ans[j] == '7')	continue;
						else{
							ans[j] = '7';
							remain--;
						}
					}
				}
				printf("%s\n", ans.c_str());
				return 0;
			}
			if(n[i]-'0' > 7){
				if(pos_4 == -1){flag = 1; break;}
				ans[pos_4] = '7';
				ans[pos_4+1] = '4';
				for(int j =	pos_4; j >= 0; j--)
					if(ans[j] == '7')	certain++;
				remain = len/2 - certain;
				for(int j = len-1; j >= 0; j--){
					if(j > pos_4){
						if(remain == 0){
							ans[j] = '4';
							continue;
						}
						ans[j] = '7';
						remain--;
					}
					else{
						if(remain <= 0)	break;
						if(ans[j] == '7')	continue;
						else{
							ans[j] = '7';
							remain--;
						}
					}
				}
				printf("%s\n", ans.c_str());
				return 0;
			}
		}
		if(flag == 1)	printf("%s\n", ('4' + s1 + '7' + s2).c_str());
		else{
			for(int j =	len-1; j >= 0; j--)
					if(ans[j] == '7')	certain++;
			remain = len/2 - certain;
			for(int j = len-1; j >= 0; j--){
				if(remain == 0) break;
				if(ans[j] == '7')	continue;
				ans[j] = '7';
				remain--;
			}
			printf("%s\n", ans.c_str());
		}
	}
	else	printf("%s\n", ('4' + s1 + '7' + s2).c_str());
	return 0;
}	