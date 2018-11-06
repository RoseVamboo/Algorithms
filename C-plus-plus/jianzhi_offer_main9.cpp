//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ9����ת�������С����
//��Ŀ����:��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת
//����һ����������������һ����ת�������ת�������СԪ�ء�
//��������{3,4,5,1,2}��{1,2,3,4,5}��һ����ת�����������СֵΪ1.
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length){
	if (numbers == nullptr || length <= 0)
		throw new std::exception("��Ч�ı�����");
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMin = index1;
	while (numbers[index1] >= numbers[index2]){
		//���
		if (index2 - index1 == 1){
			indexMin = index2;
			break;
		}
		//����±�Ϊindex1,index2��indexMinָ��������������
		//��ֻ��˳�����
		indexMin = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMin] == numbers[index1]){
			return MinInOrder(numbers, index1, index2);
		}
		//��С���ҷ�Χ
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

//--------------��ʼ����----------
void TestDisplay(int* numbers, int length, int expected){
	int result = 0;
	try{
		result = Min(numbers, length);
		for (int i = 0; i < length; i++){
			printf("%d ", numbers[i]);
		}
		if (result == expected){
			printf("\t ͨ������!\n");
		}
		else{
			printf("\t δͨ������!\n");
		}
	}
	catch (...){
		if (numbers == nullptr){
			printf("��Ч�ı���!\n");
		}
		else{
			printf("����ʧ��!");
		}
	}
}
//��������
void Test_anli(){
	int array[] = { 3, 4, 5, 1, 2 };
	TestDisplay(array, sizeof(array) / sizeof(int), 1);
}
//��������
void Test_inOrder(){
	int array[] = { 1, 2, 3, 4, 5 };
	TestDisplay(array, sizeof(array) / sizeof(int), 1);
}

//����Ϊnullptr
void Test_nullptr(){
	TestDisplay(nullptr, 0, 0);
}

//������ֻ��һ��Ԫ��
void Test_one(){
	int array[] = { 3 };
	TestDisplay(array, sizeof(array) / sizeof(int), 3);
}

//���ظ�����
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