/*
������ ��ٷ�
ȫ�������⣬���ڸ�����������n����1~n������ȫ����
*/

//����������ٷ����
#include<stdio.h>
#include<stdlib.h>
#define Maxn 10 //����nֵ
#define MaxSize 1000 //
//����ջԪ������
typedef struct{
	struct{
		int a[Maxn];      //���һ������
		int m;            //��Ÿ����е�Ԫ�ظ���
	}data[MaxSize];
	int top;              //ջ��ָ��
}StackType;

//��a[1..m]��a[j]������kֵ
void insert(int a[], int m, int j, int k){
	int i;
	for (i = m + 1; i > j; i--){
		a[i] = a[i - 1];
	}
	a[j] = k;
}

//���a[1..m]�е�Ԫ��
void disp(int a[], int m){
	for (int i = 1; i <= m; i++){
		printf(" %d", a[i]);
	}
	printf("\n");
}

//��a[1..m]���Ƶ�b[1..m]
void perm_copy(int a[], int b[], int m){
	for (int i = 1; i <= m; i++){
		b[i] = a[i];
	}
}

void perm(int n){
	int m,j;

	//����һ��˳��ջ
	StackType st;
	st.top = -1;//��ʼ��˳��ջ
	st.top++;
	st.data[st.top].a[1] = 1;
	st.data[st.top].m = 1;
	int c[Maxn], b[Maxn];
	while (st.top != -1){
		m = st.data[st.top].m;
		if (m == n){
			disp(st.data[st.top].a, n);
			st.top--;
		}
		else{
			perm_copy(st.data[st.top].a, c, m);
			st.top--;
			for (j = 1; j <= m + 1; j++){
				perm_copy(c, b, m);
				insert(b, m, j, m + 1);
				st.top++;
				perm_copy(b, st.data[st.top].a, m + 1);
				st.data[st.top].m = m + 1;
			}
		}
	}
	
}
void main_sfsjyfx_qiongjufa_perm(){
	int n;
	printf("������n��");
	scanf("%d", &n);
	perm(n);

	system("pause");
}