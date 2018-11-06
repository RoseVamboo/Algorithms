#include<iostream>
using namespace std;

void SelectSort(int a[], int n, int i){
	int k, temp;
	if (i == n - 1){
		return;
	}
	else{
		k = i;
		for (int j = i+1; j < n; j++){
			if (a[j]<a[k]){
				k = j;
			}
		}
		if (k != i){
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
		SelectSort(a, n, i + 1);
	}
}

void display(int a[], int n){
	int i;
	for (i = 0; i < n; i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}
void main_SelectSort(){
	int n = 10;
	int a[] = { 2, 5, 1, 6, 8, 7, 3, 9, 4, 10 };
	cout << "ÅÅÐòÇ°:" << endl;
	display(a, n);
	SelectSort(a, n, 0);
	cout << "ÅÅÐòºó:" << endl;
	display(a, n);
	system("pause");
}