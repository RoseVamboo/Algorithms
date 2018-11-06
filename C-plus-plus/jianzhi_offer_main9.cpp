//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目9：旋转数组的最小数字
//题目描述:把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//列如数组{3,4,5,1,2}是{1,2,3,4,5}的一个旋转，该数组的最小值为1.
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length){
	if (numbers == nullptr || length <= 0)
		throw new std::exception("无效的变量！");
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMin = index1;
	while (numbers[index1] >= numbers[index2]){
		//如果
		if (index2 - index1 == 1){
			indexMin = index2;
			break;
		}
		//如果下标为index1,index2和indexMin指向的三个数字相等
		//则只能顺序查找
		indexMin = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMin] == numbers[index1]){
			return MinInOrder(numbers, index1, index2);
		}
		//缩小查找范围
		if (numbers[indexMin] >= numbers[index1]){
			index1 = indexMin;
		}
		else if (numbers[indexMin] <= numbers[index2]){
			index2 = indexMin;
		}
	}
	return numbers[indexMin];
}

int MinInOrder(int* numbers, int index1, int index2){
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++){
		if (result > numbers[i]){
			result = numbers[i];
		}
	}
	return result;
}

//--------------开始测试----------
void TestDisplay(int* numbers, int length, int expected){
	int result = 0;
	try{
		result = Min(numbers, length);
		for (int i = 0; i < length; i++){
			printf("%d ", numbers[i]);
		}
		if (result == expected){
			printf("\t 通过测试!\n");
		}
		else{
			printf("\t 未通过测试!\n");
		}
	}
	catch (...){
		if (numbers == nullptr){
			printf("无效的变量!\n");
		}
		else{
			printf("测试失败!");
		}
	}
}
//案例输入
void Test_anli(){
	int array[] = { 3, 4, 5, 1, 2 };
	TestDisplay(array, sizeof(array) / sizeof(int), 1);
}
//递增数组
void Test_inOrder(){
	int array[] = { 1, 2, 3, 4, 5 };
	TestDisplay(array, sizeof(array) / sizeof(int), 1);
}

//数组为nullptr
void Test_nullptr(){
	TestDisplay(nullptr, 0, 0);
}

//数组中只有一个元素
void Test_one(){
	int array[] = { 3 };
	TestDisplay(array, sizeof(array) / sizeof(int), 3);
}

//有重复数字
void Test_duplicate(){
	int array[] = { 3, 4, 5, 1, 1, 2, 2 };
	TestDisplay(array, sizeof(array) / sizeof(int), 1);
}
int main_offer_9(){
	Test_anli();
	Test_inOrder();
	Test_nullptr();
	Test_one();
	Test_duplicate();
	system("pause");
	return 0;
}