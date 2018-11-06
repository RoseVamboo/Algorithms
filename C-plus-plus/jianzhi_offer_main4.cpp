//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//面试题4:二维数组中的查找
//题目：二维数组中的查找
//题目描述:在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//--------------------------------------------------------------
#include<cstdio>
#include<exception>
bool Find(int* matrix, int rows, int columns,int number){
	bool found = false;
	if (matrix != nullptr&& rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1; 
		while (row < rows&&column >= 0){
			if (matrix[row*columns + column] == number){
				found = true;
				break;
			}
			else if (matrix[row*columns + column]>number){
				column--;
			}
			else{
				row++;
			}
		}
	}
	return found;
}

//----------开始测试------------
void TestDisplay(char* testName, int* matrix, int rows, int columns, int number, bool expected){
	printf("函数 %s 开始测试.", testName);
	bool result = Find(matrix, rows, columns, number);
	if (result == expected){
		printf("测试通过!\n");
	}
	else{
		printf("测试不通过!\n");
	}
}
// 输入空指针
void Test_nullptr_main4()
{
	TestDisplay("Test_nullptr", nullptr, 0, 0, 16, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test_exist()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TestDisplay("Test_exist", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test_not_exist()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TestDisplay("Test_not_exist", (int*)matrix, 4, 4, 5, false);
}


int main_offer_4()
{
	Test_nullptr_main4();
	Test_exist();
	Test_not_exist();

	system("pause");
	return 0;
}