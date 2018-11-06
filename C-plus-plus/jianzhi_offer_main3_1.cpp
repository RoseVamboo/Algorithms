//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//面试题3:数组中重复的数字
//题目一：找出数组中重复的数字
//题目描述:在一个长度为n的数组里的所有数字都在0~n-1的范围内.
//数组中某些数字是重复的，但不知道有几个数字重复。也不知道每个数字
//重复了几次。请找出数组中任意一个重复数字。例如，如果输入长度为7的
//数组{2,3,1,0,2,5,3},那么对应的输出是重复的数字2或3.
//--------------------------------------------------------------

#include <cstdio>
#include<exception>
bool duplicate(int numbers[], int length, int * duplication){
	if (numbers == nullptr || length <= 0){
		return false;
	}
	else{
		for (int i = 0; i < length; i++){
			if (numbers[i]<0 || numbers[i]>length - 1){
				return false;
			}
		}
		for (int i = 0; i < length; i++){

			while (numbers[i] != i){
				if (numbers[i] == numbers[numbers[i]]){
					*duplication = numbers[i];
					return true;
				}
				//如果不相等，则交换numbers[i] 与 numbers[numbers[i]]
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		}
	}
	return false;
}

//---------------开始测试----------------
bool contains(int array[], int length, int number){
	for (int i = 0; i < length; i++){
		if (array[i] == number){
			return true;
		}
	}
	return false;
}
void TestDisplay(char* testName, int numbers[],
	int length, int expected[], int expectedLength, bool isExistOfDuplication){
	printf("函数 %s 开始测试:", testName);
	int duplication;
	bool isExistOfDup = duplicate(numbers, length, &duplication);
	
	if (isExistOfDuplication == isExistOfDup){
		if (isExistOfDuplication){
			if (contains(expected, expectedLength, duplication)){
				printf("通过测试!\n");
			}
			else{
				printf("测试失败!\n");
			}
		}
		else{
			printf("通过测试!\n");
		}
		}else{
		printf("测试失败!\n");
	}
}
//没有重复数字
void Test_none_dup(){
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 };
	TestDisplay("Test_none_dup", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

//只有一个重复数字
void Test_one_dup(){
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	TestDisplay("Test_one_dup", numbers, sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
}

//有多个重复数字
void Test_dup_dup(){
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	TestDisplay("Test_dup_dup", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 无效的输入
void Test_invalid()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	TestDisplay("Test_invalid", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}
int main_offer_3_1(){
	Test_none_dup();
	Test_one_dup();
	Test_dup_dup();
	Test_invalid();
	system("pause");
	return 0;
}