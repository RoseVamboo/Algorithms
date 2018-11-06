#include<stdio.h>
#include<stdlib.h>

#include<math.h>
void change(int *b, int n){
	for (int i = 0; i < n; i++){
		if (b[i] == 0){
			b[i] = 1;
			break;
		}
		else{
			b[i] = 0;
		}
	}
}
void pset(int *a, int *b,int n){
	int pown =pow((double)2,n);
	printf("子集为:");
	for (int i = 0; i < pown; i++){
		printf("{");
		for (int j = 0; j < n; j++){
			if (b[j] == 1){
				printf(" %d ", a[j]);
			}
		}
		printf("}");
		change(b, n);
	}
}

void main_sfsjyfx_pest1(){
	int n;//1-n的幂集
	printf("请输入n的值:");
	scanf("%d", &n);
	int *a;
	int *b;
	a = (int*)malloc(sizeof(int)*n);
	b = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i <n; i++){
		a[i] = i + 1;
		b[i] = 0;
	}
	pset(a, b, n);
	system("pause");
}