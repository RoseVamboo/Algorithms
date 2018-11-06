#include<iostream>
using namespace std;

void BubbleSort(int a[], int n, int i){
	int temp;
	bool exchange = false;
	if (i == n - 1){
		return;
	}
	else{
		exchange = false;
		for (int j = n - 1; j > i; j--){
			if (a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				exchange = true;
			}
		}
		if (exchange){
			BubbleSort(a, n, i + 1);
		}
		else{
			return;
		}
	}
}
void display_BubbleSort(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void main_BubbleSort(){
	int n = 10;
	int a[] = { 2, 5, 1, 6, 8, 3, 7, 9, 4, 10 };
	cout << "ÅÅÐòÇ°:" << endl;
	display_BubbleSort(a, n);
	BubbleSort(a, n, 0);
	cout << "ÅÅÐòºó:" << endl;
	display_BubbleSort(a, n);
	system("pause");
}