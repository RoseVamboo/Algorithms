#include<stdio.h>
#include<stdlib.h>

#define Maxn 10 //����nֵ
#define MaxSize 1000 //����Ӽ���

typedef struct PSetType{
	int data[MaxSize][Maxn];//data[i][0]��Ÿ��Ӽ��ĳ��ȣ�data[i][j>0]��Ÿ��Ӽ�������
	int n;//�Ӽ�����
};
void copy(int a[], int b[], int m){
	for (int i = 0; i <= m; i++){
		b[i] = a[i];
	}
}
void pset(int n, PSetType &p){
	int m,j;
	int temp[Maxn];
	p.data[0][0] = 0;
	p.n = 1;//�Ӽ�����
	for (int i = 1; i <= n; i++){
		m = p.n;
		for (j = 0; j < m; j++){
			copy(p.data[j], temp, p.data[j][0]);
			temp[0]++;
			temp[temp[0]] = i;
			copy(temp, p.data[p.n], temp[0]);
			p.n++;
		}
	}
}
void displayPest(PSetType p){
	int i = 0, j = 0;
	for ( i = 0; i < p.n; i++){
		printf("{");
		for (j = 1; j <=p.data[i][0]; j++){
			printf(" %d ", p.data[i][j]);
		}
		printf("}");
	}
}
void main_sfsjyfx_pset2(){
	int n=4;
	PSetType p;
	printf("������n��ֵ:");
	scanf("%d", &n);
	pset(n, p);
	printf("1-%d ���ݼ�����:", n);
	displayPest(p);
	system("pause");
}