#include<iostream>
#include<algorithm>
const int N = 1000;
using namespace std;
double baobei[N];

void main_chapter2_2(){
	double data;
	int n;
	double sum=0;
	cout << "������������غ͹Ŷ�����:" << endl;
	cin >> data >> n;
	cout << "������˵�йŶ�������:" << endl;
	for (int i = 0; i < n; i++){
		cin >> baobei[i];
	}
	sort(baobei, baobei+n);
	for (int i = 0; i < n; i++){
		sum+=baobei[i];
		if (sum<=data&&(sum+baobei[i+1])>data){
			cout << "��װ�����ĹŶ���:" << i+1 << endl;
			break;
		}
	}
	system("pause");
}