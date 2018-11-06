/*
1.求两个数的最大公约数
示例:
输入:24,18
输出:6
*/
#include<iostream>
using namespace std;
//辗转相除法求最大公约数
void division(){
	int a, b;
	char c;
	int t;
	while (true){
		cout << "输入:";
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
		cout << "输出:" << b << endl;
	}
}

//相减法 求最大公约数
void subtract(){
	int a, b;
	char c;
	int temp = 0;
	while (true){
		cout << "输入:";
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
		cout << "输出:" << b << endl;
	}
}

//最小公倍数
/*
定理:(a,b)[a,b]=ab (a,b为整数，其中(a,b)为a和b的最大公约数;[a,b]为a和b的最小公倍数)
*/
void leastCommonMultiple(){
	int a, b,a1,b1,temp;
	char c;
	while (true){
		cout << "输入:";
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
		cout << "输出:" << a1*b1 / b << endl;
	}
}
void main_beili_2013_1(){
	leastCommonMultiple();
	system("pause");
}