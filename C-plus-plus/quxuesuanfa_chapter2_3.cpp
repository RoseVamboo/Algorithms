#include<iostream>
#include<algorithm>
using namespace std;

/*
Ȥѧ�㷨2.3 ����Ͱ�����ʮ���
*/
/*
//����һ���ṹ�壬����Ϊstruct Student
2 	struct  Student
3 	{
4 	    string name;
5 	    double eng;
6 	    double ch;
7 	};
8
9 	//������һ���ṹ�壬����Ϊstruct Student���Ҷ�����һ���ṹ��ʵ��������Stu
10 	struct  Student
11 	{
12 	    string name;
13 	    double eng;
14 	    double ch;
15 	}Stu;
16
17 	//�����������Ľṹ�壬�Ҷ�����һ���ṹ��ʵ��������Stu
18 	struct
19 	{
20 	    string name;
21 	    double eng;
22 	    double ch;
23 	}Stu;
24
25 	//�ض���ṹ�壬����Ϊstruct Student ������Stu
26 	typedef struct  Student
27 	{
28 	    string name;
29 	    double eng;
30 	    double ch;
31 	}Stu;
32
33 	//�ض���ṹ�壬����ΪStu
34 	typedef struct
35 	{
36 	    string name;
37 	    double eng;
38 	    double ch;
39 	}Stu;
*/
const int M = 1000;
struct baowu{
	double w;//����
	double v;//��ֵ
	double p;//�Լ۱�
}s[M];
bool cmp(baowu a, baowu b){
	return a.p > b.p;
}
void main_chapter2_3(){
	double data;
	int n;
	cout << "������������������Լ���������:" << endl;
	cin >> n >> data;
	cout << "���뱦��������ͼ�ֵ:" << endl;
	for (int i = 0; i < n; i++){
		cin >> s[i].w >> s[i].v;
		s[i].p = s[i].v / s[i].w;
	}
	sort(s, s + n,cmp);
	double sum = 0;
	double p_sum = 0;
	for (int i = 0; i < n; i++){
		sum += s[i].w;
		p_sum += s[i].v;
		if (sum == data){
			break;
		}
		else if (sum<data && (sum + s[i + 1].w)>data){
			p_sum += (data - sum)*s[i + 1].p;
			//cout << "��ֵ���Ϊ:" << p_sum;
			break;
		}
	}
	cout << "��ֵ���Ϊ:" << p_sum<<endl;
	system("pause");
}