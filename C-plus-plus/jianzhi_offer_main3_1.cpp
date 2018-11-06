//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//������3:�������ظ�������
//��Ŀһ���ҳ��������ظ�������
//��Ŀ����:��һ������Ϊn����������������ֶ���0~n-1�ķ�Χ��.
//������ĳЩ�������ظ��ģ�����֪���м��������ظ���Ҳ��֪��ÿ������
//�ظ��˼��Ρ����ҳ�����������һ���ظ����֡����磬������볤��Ϊ7��
//����{2,3,1,0,2,5,3},��ô��Ӧ��������ظ�������2��3.
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
				//�������ȣ��򽻻�numbers[i] �� numbers[numbers[i]]
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		}
	}
	return false;
}

//---------------��ʼ����----------------
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
	printf("���� %s ��ʼ����:", testName);
	int duplication;
	bool isExistOfDup = duplicate(numbers, length, &duplication);
	
	if (isExistOfDuplication == isExistOfDup){
		if (isExistOfDuplication){
			if (contains(expected, expectedLength, duplication)){
				printf("ͨ������!\n");
			}
			else{
				printf("����ʧ��!\n");
			}
		}
		else{
			printf("ͨ������!\n");
		}
		}else{
		printf("����ʧ��!\n");
	}
}
//û���ظ�����
void Test_none_dup(){
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 };
	TestDisplay("Test_none_dup", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

//ֻ��һ���ظ�����
void Test_one_dup(){
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	TestDisplay("Test_one_dup", numbers, sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
}

//�ж���ظ�����
void Test_dup_dup(){
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	TestDisplay("Test_dup_dup", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// ��Ч������
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