/*
1.系统中有最近打开文件的记录，现用整数表示打开的文件名，
且只显示最新3个打开的文件，输出文件序列
示例：
输入：1  输出：1
输入：2  输出：2，1
输入：3  输出：3，2，1
输入：4  输出：4，3，2
输入：1  输出：1，4，3
输入：4  输出：4，1，3
输入：3  输出：3，4，1
*/
#include<iostream>
using namespace std;

void main_beili_2014_2(){
	int n,i=0,j=0,k=0;
	int data[3] = { 0, 0, 0 };
	bool flag = false;
	int index = 0;
	while (true){
		cout << "输入:";
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
		cout << "输出:";
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