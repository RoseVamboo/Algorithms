#include<iostream>
#include<algorithm>
using namespace std;

struct Meet{
	int begin;//���鿪ʼʱ��
	int end;//�������ʱ��
	int num;//������
}meet[1000];
int N;//��������
const int Last = 40;//���������ʱ��
bool cmp(Meet a,Meet b){
	if (a.end == b.end){
		return a.begin > b.begin;
	}
	else{
		return a.end < b.end;
	}
}
void initmeet(){
	int num = 0;
	cout << "�������������:" << endl;
	cin >> N;
	cout << "��������鿪ʼʱ�䡢�������ʱ��" << endl;
	for (int i = 0; i < N; i++){
		cin >> meet[i].begin >> meet[i].end;
		num++;
		meet[i].num=num;
	}
	sort(meet, meet + N, cmp);
}

void solve(){
	int num = 0;
	cout << "ѡ��Ļ�����:";
	int current_begin=meet[0].begin, current_end=meet[0].end;
	int current_num = meet[0].num;
	cout << meet[0].num << "��";
	num++;
	for (int i = 1; i < N; i++){
		if (current_end <meet[i].begin){
			
			if (meet[i].end < Last){
				current_end = meet[i].end;
				num++;
				cout << meet[i].num << "��";
			}
			else
			{
				break;
			}
		}
	}
	cout << "ѡ����������Ϊ:"<<num;
}

void main_chapter2_4(){
	initmeet();
	solve();
	system("pause");
}