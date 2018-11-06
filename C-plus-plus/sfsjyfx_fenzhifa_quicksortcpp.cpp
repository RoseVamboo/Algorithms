/*
快速排序，分治法
*/
#include<stdio.h>
#include<stdlib.h>
//划分算法
int Partition(int data[], int start, int end){
	int i = start, j = end;
	int temp = data[start];
	while (i != j){
		while (j > i&&data[j] >= temp){
			j--;
		}
		data[i] = data[j];
		while (i < j&&data[i] <= temp){
			i++;
		}
		data[j] = data[i];
	}
	data[i] = temp;
	return i;
}
void QuickSort(int data[], int start, int end){
	int i;
	if (start < end){
		i = Partition(data, start, end);
		QuickSort(data, start, i - 1);
		QuickSort(data, i + 1, end);
	}
}

void main_sfsjyfx_fenzhifa_quicksort(){
	int n = 10;
	int data[] = { 2, 5, 1, 7, 10, 6, 9, 4, 3, 8 };
	printf("排序前:");
	for (int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	QuickSort(data, 0, n - 1);
	printf("\n排序后:");
	for (int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	system("pause");
}