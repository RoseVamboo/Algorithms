#include <iostream>
#include<algorithm>

using namespace std;

const int M = 10000;
int x, n1, i;
int s[M];
int BinarySearch(int n, int s[], int x){

	int low = 0, high = n - 1;
	while (low <= high){
		int middle = (low + high) / 2;
		if (x== s[middle]){
			return middle;
		}else if (x < s[middle]){
			high = middle - 1;
		}
		else{
			low = middle + 1;
		}
	}
	return -1;
}

int BinarySearch_digui(int low,int high, int s[], int x){

	
		int middle = (low + high) / 2;
		if (x == s[middle]){
			return middle;
		}
		else if (x < s[middle]){
			return BinarySearch_digui(low,middle, s, x);
		}
		else{
			return BinarySearch_digui(middle+1, high, s, x);
		}
}

void main_chapter3_2(){
	cout << "请输入数列中的元素个数n为:";
	while (cin >> n1){
		cout << "请依次输入数列中的元素:";
		for (i = 0; i < n1; i++){
			cin >> s[i];
		}
		sort(s, s + n1);
		cout << "排序后的数组为:";
		for (i = 0; i < n1; i++){
			cout << s[i] << " ";
		}
		cout << endl;
		cout << "请输入要查找的元素:";
		cin >> x;
		i = BinarySearch_digui(0,n1-1, s, x);
		if (i == -1){
			cout << "该数列中没有要查找的元素" << endl;

		}
		else{
			cout << "要查找的元素位置为:" << i + 1 << endl;
		}
	}
	
}