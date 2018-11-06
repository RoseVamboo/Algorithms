#include <iostream>
#include<string>
#include<algorithm>

#define M1 105
using namespace std;

int  n, W;//n��ʾn����Ʒ��W��ʾ���ﳵ������  i, j,
double w[M1], v[M1];//W[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
bool x[M1];//x[i]��ʾ��i����Ʒ�Ƿ���빺�ﳵ
double cw;//��ǰ����
double cp;//��ǰ��ֵ
double bestp;//��ʾ��ǰ���ż�ֵ
bool bestx[M1];//��ǰ���Ž�

//�����Ͻ磨ʣ����Ʒ���ܼ�ֵ��
double Bound(int i)
{
	//ʣ����ƷΪ��i~n����Ʒ
	int rp = 0;
	while (i <= n){
		rp += v[i];
		i++;
	}
	return cp + rp;
}

//���������ռ���,t��ʾ��ǰ��չ�ڵ��ڵ�t��
void Backtrack(int t){
	if (t > n)//�Ѿ�����Ҷ�ӽڵ�
	{
		for (int j = 1; j <= n; j++){
			bestx[j] = x[j];//���浱ǰ���Ž�
		}
		bestp = cp;//���浱ǰ����ֵ
		return;
	}
	if (cw + w[t] <= W)//���������������������������
	{
		x[t] = 1;
		cw += w[t];
		cp += v[t];
		Backtrack(t + 1);
		cw -= w[t];
		cp -= v[t];
	}
	if (Bound(t + 1) > bestp)//��������޽�����������������
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void Knapsack(double W, int n){
	//��ʼ��
	cw = 0;//��ʼ����ǰ���빺�ﳵ����Ʒ����Ϊ0
	cp = 0;//��ʼ����ǰ���빺�ﳵ����Ʒ�ܼ�ֵΪ0
	bestp = 0;//��ʼ����ǰ����ֵΪ0
	double sumw = 0.0;//����ͳ��������Ʒ��������
	double sumv = 0.0;//����ͳ��������Ʒ���ܼ�ֵ
	for (int i = 1; i <= n; i++){
		sumw += w[i];
		sumv += v[i];
	}

	if (sumw <= W){
		bestp = sumv;
		cout << "���빺�ﳵ����Ʒ����ֵΪ:" << bestp << endl;
		cout << "������Ʒ�����빺�ﳵ����.";
		return;
	}
	Backtrack(1);
	cout << "���빺�ﳵ����Ʒ����ֵΪ:" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ���Ϊ:";
	for (int i = 1; i <= n; i++){
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}
int main_chapter5_2(){
	cout << "��������Ʒ�ĸ���n��";
	cin >> n;
	cout << "�����빺�ﳵ������W��";
	cin >> W;
	cout << "����������ÿ����Ʒ������W�ͼ�ֵv,�ÿո�ֿ�:";
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];

	}
	Knapsack(W, n);
	system("pause");
	return 0;
}

