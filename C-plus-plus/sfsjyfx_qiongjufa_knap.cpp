#include<stdio.h>
#include<stdlib.h>

#define Maxn1 10 //����nֵ
#define MaxSize1 1000 //�����Ӽ�����
typedef struct{
	int data[MaxSize1][Maxn1];
	int n;//�Ӽ�����
}PSetType1;
void copy_knap(int a[], int b[], int m){
	for (int i = 0; i <= m; i++){
		b[i] = a[i];
	}
}
void pset_knap(PSetType1 &p,int n){
	p.data[0][0] = 0;
	p.n = 1;
	int m, j;
	int a[Maxn1];
	for (int i = 1; i <= n; i++){
		m = p.n;
		for (j = 0; j < m; j++){
			copy_knap(p.data[j], a, p.data[j][0]);
			a[0]++;
			a[a[0]] = i;
			copy_knap(a, p.data[p.n], a[0]);
			p.n++;
		}
	}
}
void psets(int n, PSetType1 &p){
	int m, j;
	int temp[Maxn1];
	p.data[0][0] = 0;
	p.n = 1;//�Ӽ�����
	for (int i = 1; i <= n; i++){
		m = p.n;
		for (j = 0; j < m; j++){
			copy_knap(p.data[j], temp, p.data[j][0]);
			temp[0]++;
			temp[temp[0]] = i;
			copy_knap(temp, p.data[p.n], temp[0]);
			p.n++;
		}
	}
}
void knap(PSetType1 p, int w[], int v[], int W){
	int sumw, sumv;
	int j;
	int maxsumv = 0, maxsumw = 0, maxi;
	printf(" ���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");
	for (int i = 0; i < p.n; i++){
		printf(" %d\t", i + 1);
		sumw = sumv = 0;
		printf("{");
		for (j = 1; j <= p.data[i][0]; j++){
			printf("%d ", p.data[i][j]);
			sumw += w[p.data[i][j] - 1];
			sumv += v[p.data[i][j] - 1];
		}
		printf("}\t\t%d\t%d\t", sumw, sumv);
		if (sumw <= W){
			printf("��\n");
			if (sumv > maxsumv){
				maxsumv = sumv;
				maxsumw = sumw;
				maxi = i;
			}
		}
		else{
			printf("��\n");
		}
	}
	printf("��ѷ�����ѡ����ƷΪ:");
	printf("{");
	for (int j = 1; j <= p.data[maxi][0]; j++){
		printf(" %d ", p.data[maxi][j]);
	}
	printf("},");
	printf("������:%d,�ܼ�ֵ:%d\n", maxsumw, maxsumv);
}

void displayPest1(PSetType1 p){
	int i = 0, j = 0;
	for (i = 0; i < p.n; i++){
		printf("{");
		for (j = 1; j <= p.data[i][0]; j++){
			printf(" %d ", p.data[i][j]);
		}
		printf("}");
	}
}
void main_sfsjyfx_qiongjufa_knap(){
	int n = 4,W=7;
	PSetType1 p;
	psets( n,p);
	int w[] = { 5, 3, 2, 1 };
	int v[] = { 4, 4, 3, 1 };
	//displayPest1(p);
	knap(p, w, v, W);
	system("pause");
}