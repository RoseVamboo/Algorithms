#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void display_bubblesort(int *data, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
void bubbleSort(int *data, int n){
	int temp;
	bool flag = false;
	for (int i = 0; i < n-1; i++){

		for (int j = n - 1; j>i; j--){
			if (data[j] < data[j - 1]){
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
				flag = true;
			}
		}
		if (flag == false){
			return;
		}
	}
}

void main_sfsjyfx_qiongjufa_bubblesort(){
	int n;
	int *data;
	printf("请输入数组元素个数:");
	scanf("%d", &n);
	data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}

	display_bubblesort(data, n);
	bubbleSort(data, n);
	display_bubblesort(data, n);
	system("pause");
}