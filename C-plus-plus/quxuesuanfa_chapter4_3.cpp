#include <iostream>
#include <cstring>
using namespace std;

const int N = 1002;
int c[N][N], b[N][N];
char s1[N], s2[N];
int len1, len2;

void LCSL(){
	int i, j;
	for (i = 1; i <= len1; i++){//控制s1序列
		for (j = 1; j <= len2; j++){//控制s2序列
			if(s1[i-1]==s2[j-1]){
				///如果当前字符相同，则公共子序列的长度为该字符前的最长公共子序列+1
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else{
				if (c[i][j - 1] >= c[i - 1][j]){
					c[i][j] = c[i][j - 1];
					b[i][j] = 2;
				}
				else{
					c[i][j] = c[i - 1][j];
					b[i][j] = 3;
				}
			}
		}
	}
	for (i = 1; i <= len1; i++){//控制s1序列
		for (j = 1; j <= len2; j++){//控制s2序列
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << "b" << endl;
	for (i = 1; i <= len1; i++){//控制s1序列
		for (j = 1; j <= len2; j++){//控制s2序列
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

//根据记录的信息构造最长公共子序列（从b[i][j]开始递推
void print(int i, int j){
	if (i == 0 || j == 0)return;
	if (b[i][j] == 1){
		print(i - 1, j - 1);
		cout << s1[i - 1];
	}
	else if (b[i][j] == 2){
		print(i, j - 1);
	}
	else{
		print(i - 1, j);
	}
}
int main_chapter4_3(){
	int i, j;
	cout << "输入字符串s1:" << endl;
	cin >> s1;
	cout << "输入字符串s2:" << endl;
	cin >> s2;
	len1 = strlen(s1);//计算字符串的长度
	len2 = strlen(s2);
	for (i = 0; i <= len1; i++){
		c[i][0] = 0;//第一列初始化为0
	}
	for (j = 0; j <= len2; j++){
		c[0][j] = 0;//初始化第一行为0
	}
	LCSL();//求解最长公共子序列
	cout << "s1和s2的最长公共子序列长度是:" << c[len1][len2] << endl;
	cout << "s1和s2的最长公共子序列是:";
	print(len1, len2);//递归构造最长公共子序列
	system("pause");
	return 0;
}