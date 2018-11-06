#include<iostream>
#include<algorithm>
using namespace std;

struct Meet{
	int begin;//会议开始时间
	int end;//会议结束时间
	int num;//会议编号
}meet[1000];
int N;//会议总数
const int Last = 40;//人最晚结束时间
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
	cout << "请输入会议总数:" << endl;
	cin >> N;
	cout << "请输入会议开始时间、会议结束时间" << endl;
	for (int i = 0; i < N; i++){
		cin >> meet[i].begin >> meet[i].end;
		num++;
		meet[i].num=num;
	}
	sort(meet, meet + N, cmp);
}

void solve(){
	int num = 0;
	cout << "选择的会议有:";
	int current_begin=meet[0].begin, current_end=meet[0].end;
	int current_num = meet[0].num;
	cout << meet[0].num << "、";
	num++;
	for (int i = 1; i < N; i++){
		if (current_end <meet[i].begin){
			
			if (meet[i].end < Last){
				current_end = meet[i].end;
				num++;
				cout << meet[i].num << "、";
			}
			else
			{
				break;
			}
		}
	}
	cout << "选择会议的总数为:"<<num;
}

void main_chapter2_4(){
	initmeet();
	solve();
	system("pause");
}