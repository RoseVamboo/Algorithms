/*
2.输入一组英文单词，按字典顺序（大写与小写具有相同大小写)排序输出。
示例：
输入:Information Info Inform info Suite suite suit
输出:Info info Inform Information suit Suite suite
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct node{
	string a, b;
};
bool cmp(node x, node y){
	return x.a < y.a;
}
node nodeStr[100];
void main_beili_2013_2(){
	string str;
	int i, n = 0;
	while (cin >> str){
		nodeStr[n++].a = str;
	}
	for (i = 0; i < n; i++){
		cout << nodeStr[i].a << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++){
		cout << nodeStr[i].b << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++){
		nodeStr[i].b = nodeStr[i].a;
		for (int j = 0; j < nodeStr[i].a.length(); j++){
			if (nodeStr[i].a[j] >= 'A'&&nodeStr[i].a[j] <= 'Z'){
				nodeStr[i].a[j] += 'a' - 'A';
			}
		}
	}
	
	for (i = 0; i < n; i++){
		cout << nodeStr[i].a << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++){
		cout << nodeStr[i].b << " ";
	}
	cout << endl;
	sort(nodeStr, nodeStr + n, cmp);
	for (i = 0; i < n; i++){
		cout << nodeStr[i].b << " ";
	}
	cout << endl;
	system("pause");
}