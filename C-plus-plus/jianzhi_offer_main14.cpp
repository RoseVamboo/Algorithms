//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//������14:������
//��Ŀ����:����һ������Ϊn�����ӣ�������Ӽ���m��(m��n��������,n>1��
//m>=1)��ÿ�����ӵĳ��ȼ�Ϊk[0]��k[1]��...k[0]*k[1]*...*k[m]���ܵ�
//���˻��Ƕ���?���� �����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3
//�����Σ���ʱ�õ������ĳ˻�Ϊ18.
//--------------------------------------------------------------

#include<iostream>
#include<cmath>

//��̬�滮��
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

//̰���㷨
int maxProductAfterCutting_s2(int length){
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;

	//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�
	//��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2>3*1
	if (length - timesOf3 * 3 == 1){
		timesOf3 -= 1;
	}
	int timesOf2 = (length - timesOf3 * 3) / 2;
	
	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}

//----------��ʼ����-----------
void TestDisplay(const char* testName, int length, int expected){
	int result1 = maxProductAfterCutting_s1(length);
	if (result1 == expected){
		printf("��̬�滮����%s ͨ��!\n", testName);
	}
	else{
		printf("��̬�滮��: %s δͨ��!\n",testName);
	}

	int result2 = maxProductAfterCutting_s2(length);
	if (result2 == expected){
		printf("̰���㷨: %s ͨ��.\n", testName);
	}
	else{
		printf("̰���㷨: %s δͨ��.\n",testName);
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