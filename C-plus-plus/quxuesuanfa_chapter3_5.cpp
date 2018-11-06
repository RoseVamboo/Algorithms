#include <cstring>
#include<iostream>

using namespace std;

#define M 100
char sa[1000];
char sb[1000];

typedef struct _Node{
	int s[M];
	int l; //代表字符串的长度
	int c;//代表整数的位数
}Node,*pNode;
//cp函数用于将一个n位的数分成两个n/2的数，并存储
//src表示带分解的数的节点，des表示分解后得到的数的节点
//st表示从src节点中数组取数的开始位置，l 表示取数的长度
void cp(pNode src, pNode des, int st, int l){
	int i, j;
	for (i = st, j = 0; i < st + 1;i++,j++){
		des->s[j] = src->s[i];
	}
	des->l = l;
	des->c = st + src->c;//des次幂等于开始取数的位置加上src次幂
}

void mul(pNode pa, pNode pb, pNode ans){
	int i;
	//if ()
}