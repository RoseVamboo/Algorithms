#include <cstring>
#include<iostream>

using namespace std;

#define M 100
char sa[1000];
char sb[1000];

typedef struct _Node{
	int s[M];
	int l; //�����ַ����ĳ���
	int c;//����������λ��
}Node,*pNode;
//cp�������ڽ�һ��nλ�����ֳ�����n/2���������洢
//src��ʾ���ֽ�����Ľڵ㣬des��ʾ�ֽ��õ������Ľڵ�
//st��ʾ��src�ڵ�������ȡ���Ŀ�ʼλ�ã�l ��ʾȡ���ĳ���
void cp(pNode src, pNode des, int st, int l){
	int i, j;
	for (i = st, j = 0; i < st + 1;i++,j++){
		des->s[j] = src->s[i];
	}
	des->l = l;
	des->c = st + src->c;//des���ݵ��ڿ�ʼȡ����λ�ü���src����
}

void mul(pNode pa, pNode pb, pNode ans){
	int i;
	//if ()
}