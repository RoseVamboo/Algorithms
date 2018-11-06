/*
3.求广义表的深度（实际就是括号匹配）
示例：
输入:(c,((d,e),f),h)
输出:3
*/
#include<iostream>
#include<string.h>
using namespace std;
#define Maxn 100
void main_beili_2014_3(){
	char data[Maxn];
	int count = 0,depth=0;
	int i = 0;
	while (true){
		cout << "输入:";
		gets(data);
		count = 0;
		depth = 0;
		for (i = 0; i < strlen(data); i++){
			if (data[i] == '('){
				count++;
				if (count>depth){
					depth = count;
				}
			}
			else if (data[i] == ')'){
				count--;
			}
		}
		cout << "count=" << count << endl;
		if (count == 0){
			cout << "输出:" << depth << endl;
		}
		else{
			cout << "该广义表不正确" << endl;
		}
	}
	system("pause");
}