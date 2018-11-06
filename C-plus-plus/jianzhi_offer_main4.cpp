//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//������4:��ά�����еĲ���
//��Ŀ����ά�����еĲ���
//��Ŀ����:��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
//����������һ����ά�����һ���������ж��������Ƿ��и�������
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

//----------��ʼ����------------
void TestDisplay(char* testName, int* matrix, int rows, int columns, int number, bool expected){
	printf("���� %s ��ʼ����.", testName);
	bool result = Find(matrix, rows, columns, number);
	if (result == expected){
		printf("����ͨ��!\n");
	}
	else{
		printf("���Բ�ͨ��!\n");
	}
}
// �����ָ��
void Test_nullptr_main4()
{
	TestDisplay("Test_nullptr", nullptr, 0, 0, 16, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test_exist()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	TestDisplay("Test_exist", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
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