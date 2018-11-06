//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//面试题14:剪绳子
//题目描述:给你一根长度为n的绳子，请把绳子剪成m段(m、n都是整数,n>1且
//m>=1)。每段绳子的长度即为k[0]、k[1]、...k[0]*k[1]*...*k[m]可能的
//最大乘积是多少?例如 当绳子的长度是8时，我们把它剪成长度分别为2、3、3
//的三段，此时得到的最大的乘积为18.
//--------------------------------------------------------------

#include<iostream>
#include<cmath>

//动态规划法
int maxProductAfterCutting_s1(int length){
	if (length < 2){
		return 0;
	}
	else if (length == 2){
		return 1;
	}
	else if (length == 3){
		return 2;
	}

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++){
		max = 0;
		for (int j = 1; j <= i / 2; j++){
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}
	max = products[length];
	delete[] products;
	return max;
}

//贪婪算法
int maxProductAfterCutting_s2(int length){
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//尽可能多的减去长度为3的绳子段
	int timesOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候，不能再减去长度为3的绳子段
	//此时更好的方法是把绳子剪成长度为2的两段，因为2*2>3*1
	if (length - timesOf3 * 3 == 1){
		timesOf3 -= 1;
	}
	int timesOf2 = (length - timesOf3 * 3) / 2;
	
	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}

//----------开始测试-----------
void TestDisplay(const char* testName, int length, int expected){
	int result1 = maxProductAfterCutting_s1(length);
	if (result1 == expected){
		printf("动态规划法：%s 通过!\n", testName);
	}
	else{
		printf("动态规划法: %s 未通过!\n",testName);
	}

	int result2 = maxProductAfterCutting_s2(length);
	if (result2 == expected){
		printf("贪婪算法: %s 通过.\n", testName);
	}
	else{
		printf("贪婪算法: %s 未通过.\n",testName);
	}
}

void Test1_main14(){
	int length = 1;
	int expected = 0;
	TestDisplay("Test1_main14", length, expected);
}

void Test2_main14(){
	int length = 2;
	int expected = 1;
	TestDisplay("Test2_main14", length, expected);
}

void Test3_main14(){
	int length = 3;
	int expected =2;
	TestDisplay("Test3_main14", length, expected);
}

void Test4_main14(){
	int length = 4;
	int expected = 4;
	TestDisplay("Test4_main14", length, expected);
}

void Test5_main14(){
	int length = 5;
	int expected =6;
	TestDisplay("Test5_main14", length, expected);
}

void Test6_main14(){
	int length =6;
	int expected = 9;
	TestDisplay("Test6_main14", length, expected);
}

void Test7_main14(){
	int length = 7;
	int expected = 12;
	TestDisplay("Test7_main14", length, expected);
}

void Test8_main14(){
	int length = 8;
	int expected = 18;
	TestDisplay("Test8_main14", length, expected);
}

void Test9_main14(){
	int length = 9;
	int expected = 27;
	TestDisplay("Test9_main14", length, expected);
}

void Test10_main14(){
	int length = 10;
	int expected = 36;
	TestDisplay("Test10_main14", length, expected);
}

void Test11_main14(){
	int length = 50;
	int expected = 86093442;
	TestDisplay("Test11_main14", length, expected);
}

int main_jianzhi_offer_14(){

	Test1_main14();
	Test2_main14();
	Test3_main14();

	Test4_main14();
	Test5_main14();
	Test6_main14();

	Test7_main14();
	Test8_main14();
	Test9_main14();

	Test10_main14();
	Test11_main14();

	system("pause");
	return 0;
}