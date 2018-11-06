/*

1、输入学生信息，姓名 成绩（成绩的数目不一定）
输出每个学生的学号和平均成绩，以及不及格课程数超过2的学生，按不及格课程数从大到小排好序输出
*/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	string no;//学号
	string name;//学生姓名
	int scores[105];//每科成绩
	int scoreNum;//成绩数目
	int below60num;//不及格成绩数目
};
bool cmp(Student a, Student b){
	return a.below60num > b.below60num;
}
void main_beili_2016_1(){

	Student stud[105];
	string ss[105], str;
	int m = 0;
	int index = 0;//学生数目
	//读取字符串
	while (getline(cin, ss[m])){
		m++;
	}
	for (int l = 0; l < m; l++){
		str = ss[l];
		int start = -1;
		int end = -1;
		int flag = 0;//表示是否找到名字
		int num = 0;//成绩个数

		for (int i = 0; i < str.length(); i++){
			if (flag == 0){
				if (str[i] != ' '){
					start = i;
					flag = 1;
				}
			}
			else if (flag == 1){
				if (str[i] == ' '){
					end = i;
					break;
				}
			}
		}
		flag = 0;
		stud[index].name = str.substr(start, end - start);
		str[str.length()] = 'A';
		for (int j = end + 1; j < str.length() + 1; j++){
			if (flag == 0){
				if (str[j] >= '0'&&str[j] <= '9'){
					start = j;
					flag = 1;
				}
			}
			else if (flag == 1){
				if (str[j] == ' ' || str[j] == 'A'){
					end = j;
					int sum = 0;
					string t = str.substr(start, end - start);
					for (int k = 0; k < t.length(); k++){
						sum = sum * 10 + (t[k] - '0');
					}
					stud[index].scores[num++] = sum;
					flag = 0;
					start = -1;
					end = -1;
				}
			}
		}
		stud[index].scoreNum = num;
		index++;

	}
	//统计不及格数目
	string aa[105];
	int tt = 0;//不及格科目数超过2的人数
	for (int i = 0; i < index; i++){
		stud[i].below60num = 0;
		for (int j = 0; j < stud[j].scoreNum; j++){
			if (stud[i].scores[j] < 60){
				stud[i].below60num++;
			}
		}
		//查找不及格科目数超过2的学生
		if (stud[i].below60num>2){
			aa[tt++] = stud[i].name;
		}
	}

	if (tt > 0){
		cout << "不及格科目数超过2的学生为:";
		for (int i = 0; i < tt; i++){
			cout << aa[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "没有不及格的学生" << endl;
	}

	//对不及格科目数从大到小进行排序
	sort(stud, stud + index, cmp);
	for (int i = 0; i < index; i++){
		cout << stud[i].name << " 不及格科目数 " << stud[i].below60num << endl;
	}

	system("pause");
}