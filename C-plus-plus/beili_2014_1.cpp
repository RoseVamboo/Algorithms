/*
1.ϵͳ����������ļ��ļ�¼������������ʾ�򿪵��ļ�����
��ֻ��ʾ���3���򿪵��ļ�������ļ�����
ʾ����
���룺1  �����1
���룺2  �����2��1
���룺3  �����3��2��1
���룺4  �����4��3��2
���룺1  �����1��4��3
���룺4  �����1��4��3
���룺3  �����1��4��3
*/
#include<iostream>
using namespace std;
//����1
void solution1(){
	int n,i,j,k;
	int data[3] = {0,0,0};
	int index = 0;
	bool flag = false;
	while (true){
		flag = false;
		cout << "����:";
		cin >> n;
		for (i = 0; i<3; i++){
			if (data[i] == n){
				flag = true;
			}
		}
		if (flag){
			
		}
		else{
			for (j = 2; j > 0; j--){
				data[j] = data[j - 1];
			}
			data[0] = n;
		}
		cout << "���:";
		for (k = 0; k < 3&&data[k]>0; k++){
			cout << data[k];
			if (data[k+ 1]>0&&k<2){
				cout << ",";
			}
		}
		cout << endl;
	}
}
void main_beili_2014_1(){
	solution1();
	system("pause");
}