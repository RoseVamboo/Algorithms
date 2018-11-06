#include <iostream>
using namespace std;

void Merge(int s[], int low, int middle, int high){
	int *B = new int[high - low + 1];
	int i = low, j = middle+1,k=0;
	while (i<=middle&&j<=high){
		if (s[i] < s[j]){
			B[k++] = s[i++];
		}
		else{
			B[k++] = s[j++];
		}
	}
	while (i <= middle)B[k++] = s[i++];
	while (j <= high)B[k++] = s[j++];
	for (i = low, k = 0; i <= high; i++, k++){
		s[i] = B[k];
	}
}
void MergeSort(int low,int high,int s[]){
	if (low < high){
		int middle = (low + high) / 2;
		MergeSort(low, middle, s);
		MergeSort(middle + 1, high, s);
		Merge(s, low, middle, high);
	}
	
}
int main_chapter3_3(){
	int n, A[100];
	cout << "请输入数列中元素的个数n:" << endl;
	cin >> n;
	cout << "请依次输入数列中的元素:" << endl;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	MergeSort(0, n - 1, A);
	cout << "合并排序结果" << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}