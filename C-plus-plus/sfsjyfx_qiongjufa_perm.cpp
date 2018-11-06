/*
第三章 穷举法
全排列问题，对于给定的正整数n，求1~n的所有全排列
*/

//采用增量穷举法求解
#include<stdio.h>
#include<stdlib.h>
#define Maxn 10 //最大的n值
#define MaxSize 1000 //
//定义栈元素类型
typedef struct{
	struct{
		int a[Maxn];      //存放一个排列
		int m;            //存放该排列的元素个数
	}data[MaxSize];
	int top;              //栈顶指针
}StackType;

//在a[1..m]中a[j]处插入k值
void insert(int a[], int m, int j, int k){
	int i;
	for (i = m + 1; i > j; i--){
		a[i] = a[i - 1];
	}
	a[j] = k;
}

//输出a[1..m]中的元素
void disp(int a[], int m){
	for (int i = 1; i <= m; i++){
		printf(" %d", a[i]);
	}
	printf("\n");
}

//将a[1..m]复制到b[1..m]
void perm_copy(int a[], int b[], int m){
	for (int i = 1; i <= m; i++){
		b[i] = a[i];
	}
}

void perm(int n){
	int m,j;

	//定义一个顺序栈
	StackType st;
	st.top = -1;//初始化顺序栈
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
	printf("请输入n：");
	scanf("%d", &n);
	perm(n);

	system("pause");
}