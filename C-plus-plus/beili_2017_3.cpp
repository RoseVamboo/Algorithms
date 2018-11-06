/*
3、输入学生个数以及每个学生的姓名和3门课程成绩：输出不及格学生的信息；按平均成绩排序，从高到低输出学生信息。
输入示例：
5
zhaoyi   70 80 91
zhanger  68 40 90
zhangsan 60 70 80
lisi     70 80 90
wangwu   52 70 100
输出示例：
*name: zhanger   score:68 40 99
*name: wangwu    score:52 70 100
[1]  name:zhaoyi     70 80 91
[2]  name:lisi       70 80 90
[3]  name:wangwu     52 70 100
[4]  name:zhangsan   60 70 80
[5]  name:zhanger    68 40 99
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LEN sizeof(struct student)
struct student{
	char name[20];
	int  scores[3];
	int sum;
};
/**/
int campare_avg(const void *a, const void*b){
	struct student *aa = (struct student*)a;
	struct student *bb = (struct student*)b;
	return (aa->sum > bb->sum ? -1 : 1);
}

void avgscore_sort(int n, student * stud){
	student temp;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (stud[j].sum<stud[j + 1].sum){
				temp = stud[j + 1];
				stud[j + 1] = stud[j];
				stud[j] = temp;
			}
		}
	}
}
void input(int n, student*stud){
	for (int i = 0; i < n; i++){
		scanf("%s", &stud[i].name);
		for (int j = 0; j < 3; j++){
			scanf("%d",&stud[i].scores[j]);
		}
	}
}

void print(int n, student* stud){
	int sum = 0;
	float avg = 0;
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < 3; j++){
			if (stud[i].scores[j] < 60){

				printf("* name: s%    score:%d %d %d \n", stud[i].name, stud[i].scores[0], stud[i].scores[1], stud[i].scores[2]);
				break;
			}
		}

	}
	for (int i = 0; i < n; i++){
		for (int k = 0; k < 3; k++){
			sum = sum+stud[i].scores[k];
		}
		//avg = sum / 3;
		stud[i].sum = sum;
		sum = 0;
	}

	//qsort(stud, n, sizeof(stud[0]), campare_avg);
	avgscore_sort(n, stud);
	for (int i = 0; i < n; i++){
		printf("[%d] name:%s   %d %d %d\n", i+1, stud[i].name, stud[i].scores[0], stud[i].scores[1], stud[i].scores[2]);
	}
}

void main_beili_2017_3(){
	int n;
	printf("请输入学生个数:");
	scanf("%d", &n);
	struct student *stud;
	stud = (struct student*)malloc(n*LEN);
	input(n, stud);
	print(n, stud);
	system("pause");
}