#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//�򵥿������򷽷�1.תΪλ�ã�2.ֱ��ת��ֵ
void selectSort(int *data, int n){
	int k,temp;
	for (int i = 0; i < n; i++){
		k = i;
		for (int j = i+1; j < n; j++){
			if (data[j] < data[k]){
				k = j;
			}
		}
		if (k != i){
			temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}
	}
}
void display(int *data, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
void main_sfsjyfx_qujufa_selectsort(){
	int n;
	int *data;//��̬��������
	printf("����������Ԫ�ظ���:");
	scanf("%d",&n);
	printf("��������������:\n");
	data = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}

	display(data, n);
	selectSort(data, n);
	display(data, n);
	system("pause");
}