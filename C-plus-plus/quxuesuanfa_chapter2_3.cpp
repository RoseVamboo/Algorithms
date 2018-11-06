#include<iostream>
#include<algorithm>
using namespace std;

/*
趣学算法2.3 阿里巴巴与四十大盗
*/
/*
//定义一个结构体，类型为struct Student
2 	struct  Student
3 	{
4 	    string name;
5 	    double eng;
6 	    double ch;
7 	};
8
9 	//定义了一个结构体，类型为struct Student；且定义了一个结构体实例，名叫Stu
10 	struct  Student
11 	{
12 	    string name;
13 	    double eng;
14 	    double ch;
15 	}Stu;
16
17 	//定义了无名的结构体，且定义了一个结构体实例，名叫Stu
18 	struct
19 	{
20 	    string name;
21 	    double eng;
22 	    double ch;
23 	}Stu;
24
25 	//重定义结构体，类型为struct Student 或者是Stu
26 	typedef struct  Student
27 	{
28 	    string name;
29 	    double eng;
30 	    double ch;
31 	}Stu;
32
33 	//重定义结构体，类型为Stu
34 	typedef struct
35 	{
36 	    string name;
37 	    double eng;
38 	    double ch;
39 	}Stu;
*/
const int M = 1000;
struct baowu{
	double w;//重量
	double v;//价值
	double p;//性价比
}s[M];
bool cmp(baowu a, baowu b){
	return a.p > b.p;
}
void main_chapter2_3(){
	double data;
	int n;
	cout << "请输入容器最大容量以及宝贝数量:" << endl;
	cin >> n >> data;
	cout << "输入宝物的重量和价值:" << endl;
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
			//cout << "价值最大为:" << p_sum;
			break;
		}
	}
	cout << "价值最大为:" << p_sum<<endl;
	system("pause");
}