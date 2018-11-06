//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//面试题12:矩阵中的路径
//题目描述:请设计一个函数，用来判断在一个矩阵中是否存在一条包含某
//字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在
//矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，
//那么该路径不能再吃进入该格子。例如，在下面的3x4的矩阵中包含一条
//字符串"bfce"的路径,因为字符串的第一个字符b占据了矩阵中的第一行
//第二个格子之后，路径不能再次进入这个格子。
//--------------------------------------------------------------

#include<cstdio>
#include<string>
#include<stack>
using namespace std;
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str){
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr){
		return false;
	}

	bool* visited = new bool[rows*cols];
	/*
	memset()函数原型是extern void *memset(void *buffer,int c,int count)
	buffer：为指针或是数组
	c:是赋给buffer的值
	count:是buffer的长度
	该函数在socket中多用于清空数组。或是用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化' '或'/0'
	*/
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++){
		for (int col = 0; col < cols; col++){
			if (hasPathCore(matrix, rows, cols, row, col, str,
				pathLength, visited)){
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited){
	if (str[pathLength] == '\0'){
		return true;
	}
	bool hasPath = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&
		matrix[row*cols + col] == str[pathLength]
		&& !visited[row*cols + col]){
		pathLength++;
		visited[row*cols + col] = true;
		
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
		if (!hasPath){
			pathLength--;
			visited[row*cols + col] = false;
		}
	}
	return hasPath;
}
//-----------开始测试-------------
void TestDisplay(const char* testName, const char* matrix, 
	int rows, int cols,
	const char* str, bool expected){
	if (testName != nullptr){
		printf("函数 %s 开始测试 \n", testName);
	}

	if (hasPath(matrix, rows, cols, str) == expected){
		printf("测试通过!\n");
	}
	else{
		printf("测试未通过!\n");
	}
}


//ABTG
//CFCS
//JDEH

//BFCE
void test_offer_12_1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";

	TestDisplay("Test1", (const char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void test_offer_12_2()
{
	const char* matrix = "ABCESFCSADEE";
	const char* str = "SEE";

	TestDisplay("Test2", (const char*)matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void test_offer_12_3()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	TestDisplay("Test3", (const char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void test_offer_12_4()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SLHECCEIDEJFGGFIE";

	TestDisplay("Test4", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void test_offer_12_5()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEM";

	TestDisplay("Test5", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void test_offer_12_6()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEEJIGOEM";

	TestDisplay("Test6", (const char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void test_offer_12_7()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEMS";

	TestDisplay("Test7", (const char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void test_offer_12_8()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAA";

	TestDisplay("Test8", (const char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void test_offer_12_9()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAAA";

	TestDisplay("Test9", (const char*)matrix, 3, 4, str, false);
}

//A

//A
void test_offer_12_10()
{
	const char* matrix = "A";
	const char* str = "A";

	TestDisplay("Test10", (const char*)matrix, 1, 1, str, true);

}
//A

//B
void test_offer_12_11()
{
	const char* matrix = "A";
	const char* str = "B";

	TestDisplay("Test11", (const char*)matrix, 1, 1, str, false);
}

void test_offer_12_12()
{
	TestDisplay("Test12", nullptr, 0, 0, nullptr, false);
}

int main_offer_12(){
	test_offer_12_1();
	test_offer_12_2();
	test_offer_12_3();
	test_offer_12_4();
	test_offer_12_5();
	test_offer_12_6();
	test_offer_12_7();
	test_offer_12_8();
	test_offer_12_9();
	test_offer_12_10();
	test_offer_12_11();
	test_offer_12_12();
	system("pause");
	return 0;
}