/*
1.ϵͳ����������ļ��ļ�¼������������ʾ�򿪵��ļ�����
��ֻ��ʾ����3���򿪵��ļ�������ļ�����
ʾ����
���룺1  �����1
���룺2  �����2��1
���룺3  �����3��2��1
���룺4  �����4��3��2
���룺1  �����1��4��3
���룺4  �����4��1��3
���룺3  �����3��4��1
*/
#include<iostream>
using namespace std;

void main_beili_2014_2(){
	int n,i=0,j=0,k=0;
	int data[3] = { 0, 0, 0 };
	bool flag = false;
	int index = 0;
	while (true){
		cout << "����:";
		cin >> n;

		for (i = 0; i < 3; i++){
			if (data[i] == n){
				flag = true;
				index = i;
				break;
			}
		}
		if (flag){
			for (j = index; j>0; j--){
				data[j] = data[j - 1];
			}
			data[0] = n;
		}
		else{
			for (j = 2; j>0; j--){
				data[j] = data[j - 1];
			}
			data[0] = n;
		}
		cout << "���:";
		for (k = 0; k < 3 && data[k]>0; k++){
			cout << data[k];
			if (k < 2 && data[k+1]>0){
				cout << ",";
			}
		}
		cout << endl;
	}
	system("pause");
}