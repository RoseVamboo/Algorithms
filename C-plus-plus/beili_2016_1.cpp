/*

1������ѧ����Ϣ������ �ɼ����ɼ�����Ŀ��һ����
���ÿ��ѧ����ѧ�ź�ƽ���ɼ����Լ�������γ�������2��ѧ������������γ����Ӵ�С�ź������
*/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	string no;//ѧ��
	string name;//ѧ������
	int scores[105];//ÿ�Ƴɼ�
	int scoreNum;//�ɼ���Ŀ
	int below60num;//������ɼ���Ŀ
};
bool cmp(Student a, Student b){
	return a.below60num > b.below60num;
}
void main_beili_2016_1(){

	Student stud[105];
	string ss[105], str;
	int m = 0;
	int index = 0;//ѧ����Ŀ
	//��ȡ�ַ���
	while (getline(cin, ss[m])){
		m++;
	}
	for (int l = 0; l < m; l++){
		str = ss[l];
		int start = -1;
		int end = -1;
		int flag = 0;//��ʾ�Ƿ��ҵ�����
		int num = 0;//�ɼ�����

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
	//ͳ�Ʋ�������Ŀ
	string aa[105];
	int tt = 0;//�������Ŀ������2������
	for (int i = 0; i < index; i++){
		stud[i].below60num = 0;
		for (int j = 0; j < stud[j].scoreNum; j++){
			if (stud[i].scores[j] < 60){
				stud[i].below60num++;
			}
		}
		//���Ҳ������Ŀ������2��ѧ��
		if (stud[i].below60num>2){
			aa[tt++] = stud[i].name;
		}
	}

	if (tt > 0){
		cout << "�������Ŀ������2��ѧ��Ϊ:";
		for (int i = 0; i < tt; i++){
			cout << aa[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "û�в������ѧ��" << endl;
	}

	//�Բ������Ŀ���Ӵ�С��������
	sort(stud, stud + index, cmp);
	for (int i = 0; i < index; i++){
		cout << stud[i].name << " �������Ŀ�� " << stud[i].below60num << endl;
	}

	system("pause");
}