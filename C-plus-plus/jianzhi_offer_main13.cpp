//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//面试题13:机器人的运动范围
//题目描述:地上有一个m行n列的方格。一个机器人从左右(0,0)的各自开始移动，
//它每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
//大于k的格子。例如,当k为18时，机器人能够进入方格(35,37)，因为3+5+3+7=18.
//但它不能进入方格(35,38)因为3+5+3+8=19.
//请问该机器人能够达到多少个格子?
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
int movingCountCore(int threshold, int rows, int cols, int ros, int col, bool* visited);
bool check(int threshold, int rows, int cols, int ros, int col, bool* visited);
int getDigitSum(int number);
int movingCount(int threshold, int rows, int cols){
	if (threshold < 0 || rows <= 0 || cols <= 0){
		return 0;
	}
	bool * visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++){
		visited[i] = false;
	}
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)){
		visited[row*cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +
			movingCountCore(threshold, rows, cols, row, col - 1, visited) +
			movingCountCore(threshold, rows, cols, row, col + 1, visited) +
			movingCountCore(threshold, rows, cols, row + 1, col, visited);
	}
	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited){
	if (row >= 0 && row < rows&&col >= 0 && col < cols
		&&getDigitSum(row) + getDigitSum(col) <= threshold
		&&!visited[row*cols + col]){
		return true;
	}
	else{
		return false;
	}
}

int getDigitSum(int number){
	int sum = 0;
	while (number > 0){
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

//-----------开始测试------------
void TestDisplay(char* testName, int threshold, int rows, int cols, int expected){
	if (testName != nullptr){
		printf("函数 %s 开始测试 .\n", testName);
	}
	if (movingCount(threshold, rows, cols) == expected){
		printf("测试通过.\n");
	}
	else{
		printf("测试为通过!\n");
	}
}

//机器人无法进入任意一个方格
void Test_none(){
	TestDisplay("Test_none", -10, 10, 10, 0);
}

//方格为一行一列
void Test_one_row_one_col(){
	TestDisplay("Test_one_row_one_col", 15, 1, 1, 1);
}

//
// 方格多行多列
void Test_dup_row_dup_col_1()
{
	TestDisplay("Test_dup_row_dup_col_1", 5, 10, 10, 21);
}

// 方格多行多列
void Test_dup_row_dup_col_2()
{
	TestDisplay("Test_dup_row_dup_col_2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void Test_one_row_some()
{
	TestDisplay("Test_one_row_some", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void Test_one_row_all()
{
	TestDisplay("Test_one_row_all", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void Test_one_col_some()
{
	TestDisplay("Test_one_col_some", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void Test_one_col_all()
{
	TestDisplay("Test_one_col_all", 15, 10, 1, 10);
}

int main_offer_13(){
	//机器人无法进入任意一个方格
	Test_none();
	//方格为一行一列
	Test_one_row_one_col();
	// 方格多行多列
	Test_dup_row_dup_col_1();
	// 方格多行多列
	Test_dup_row_dup_col_2();
	// 方格只有一行，机器人只能到达部分方格
	Test_one_row_some();
	// 方格只有一行，机器人能到达所有方格
	Test_one_row_all();
	// 方格只有一列，机器人只能到达部分方格
	Test_one_col_some();
	// 方格只有一列，机器人能到达所有方格
	Test_one_col_all();
	system("pause");
	return 0;
}