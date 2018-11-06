#include<iostream>
#include<algorithm>
const int N = 1000;
using namespace std;
double baobei[N];

void main_chapter2_2(){
	double data;
	int n;
	double sum=0;
	cout << "输入容器最大负载和古董数量:" << endl;
	cin >> data >> n;
	cout << "请输入说有古董的质量:" << endl;
	for (int i = 0; i < n; i++){
		cin >> baobei[i];
	}
	sort(baobei, baobei+n);
	for (int i = 0; i < n; i++){
		sum+=baobei[i];
		if (sum<=data&&(sum+baobei[i+1])>data){
			cout << "能装入最大的古董数:" << i+1 << endl;
			break;
		}
	}
	system("pause");
}