/*
1.�������������Լ��
ʾ��:
����:24,18
���:6
*/
#include<iostream>
using namespace std;
//շת����������Լ��
void division(){
	int a, b;
	char c;
	int t;
	while (true){
		cout << "����:";
		cin >> a >> c >> b;

		if (a < b){
			t = a;
			a = b;
			b = t;
		}
		while (t = a%b){
			a = b;
			b = t;
		}
		cout << "���:" << b << endl;
	}
}

//����� �����Լ��
void subtract(){
	int a, b;
	char c;
	int temp = 0;
	while (true){
		cout << "����:";
		cin >> a >> c >> b;
		if (a < b){
			temp = a;
			a = b;
			b = temp;
		}
		while ((a - b)!=0){
			if (a < b){
				temp = a;
				a = b;
				b = temp;
			}
			temp = a - b;
			a = b;
			b = temp;
		}
		cout << "���:" << b << endl;
	}
}

//��С������
/*
����:(a,b)[a,b]=ab (a,bΪ����������(a,b)Ϊa��b�����Լ��;[a,b]Ϊa��b����С������)
*/
void leastCommonMultiple(){
	int a, b,a1,b1,temp;
	char c;
	while (true){
		cout << "����:";
		cin >> a >> c >> b;
		if (a < b){
			temp = a;
			a = b;
			b = temp;
		}
		a1 = a;
		b1 = b;
		while (temp = a%b){
			a = b;
			b = temp;
		}
		cout << "���:" << a1*b1 / b << endl;
	}
}
void main_beili_2013_1(){
	leastCommonMultiple();
	system("pause");
}