/*
3.���������ȣ�ʵ�ʾ�������ƥ�䣩
ʾ����
����:(c,((d,e),f),h)
���:3
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
		cout << "����:";
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
			cout << "���:" << depth << endl;
		}
		else{
			cout << "�ù������ȷ" << endl;
		}
	}
	system("pause");
}