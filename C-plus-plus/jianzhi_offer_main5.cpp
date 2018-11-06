//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ5���滻�ո�
//��Ŀ����:��ʵ��һ������,���ַ����е�ÿһ���ո��滻��"%20".
//��������"We are happy.",�����"We%20are%20happy."
//--------------------------------------------------------------
//--------------------------------------------------------------
//�����Ŀ:
//���������������A1��A2,�ڴ���A1��ĩβ���㹻��Ŀ���ռ�����A2��
//��ʵ��һ������,��A2�е��������ֲ��뵽A1�в������е������������.

//��һ����:
//�ϲ���������(�����ַ���)ʱ,�����ǰ����ֵÿ������(���ַ���)
//��Ҫ�ظ��ƶ�����(�ַ���)���,��ô���ǿ��Կ��ǴӺ���ǰ����,
//�������ܼ����ƶ��Ĵ���,�Ӷ����Ч��.
//--------------------------------------------------------------
#include<cstdio>
#include<cstring>
#include<stdlib.h>
//length Ϊ�ַ�������string��������
void  ReplaceBlank(char str[], int length){
	if (str == nullptr&&length <= 0){
		return;
	}
	/*originalLengthΪ�ַ���str��ʵ�ʳ���*/
	int originalLength = 0;
	/*�ַ����пո���*/
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0'){
		++originalLength;
		if (str[i] == ' '){
			++numberOfBlank;
		}
		++i;
	}
	/*newLengthΪ�ѿո��滻��'%20'֮��ĳ���*/
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length){
		return;
	}
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >=0&&indexOfNew>indexOfOriginal){
		
		if (str[indexOfOriginal]!= ' '){

			str[indexOfNew--] = str[indexOfOriginal];
		}
		else{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}

		--indexOfOriginal;
	}
}

//--��ʼ����--
void TestDisplay(char str[], int length, char* testName){
	if (testName != nullptr){
		printf("%s ��ʼ���� ",testName);
	}
	ReplaceBlank(str, length);
	printf("�µ��ַ���=%s",str);
}

//
void Test1(){
	const int length = 100;
	char str[length] = "hello world  ";
	TestDisplay(str, length, "Test1");
}

int main_offer_5(int argc, char* argv[]){

	Test1();
	system("pause");
	return 0;
}