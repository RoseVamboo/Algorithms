//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ11����������1�ĸ���
//��Ŀ����:��ʵ��һ������,����һ������,������������Ʊ�ʾ��1�ĸ�����
//�����9��ʾ�ɶ�������1001,��2λ1.����������9���ú������2��
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
//�÷���������n>0��������
int NumberOf1_s1(int n){
	int count = 0;
	
	while (n){
		if (n & 1){
			count++;
		}
		n = n >> 1;
	}
	return count;
}

int NumberOf1_s2(int n){
	int count = 0;
	unsigned int flag = 1;
	while (flag){
		if (n&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_s3(int n){
	int count = 0;
	while (n){
		count++;
		n = (n - 1)&n;
	}
	return count;
}

//------------��ʼ����---------
void TestDisplay(int n){
	int number = n;
	if (n < 0){
		printf("����NumberOf1_s1 ��������ѭ��.\n");
	}
	else{
		int actual = NumberOf1_s1(n);
		printf("����NumberOf1_s1�� n=%d �Ķ�������1�ĸ���Ϊ: %d \n", number, actual);
	}
	int actual1 = NumberOf1_s2(n);
	printf("����NumberOf1_s2�� n=%d �Ķ�������1�ĸ���Ϊ: %d \n", number, actual1);
	int actual2 = NumberOf1_s3(n);
	printf("����NumberOf1_s13�� n=%d �Ķ�������1�ĸ���Ϊ: %d \n", number, actual2);
}
int main_main11(){
	//����0
	TestDisplay(0);

	//����1
	TestDisplay(1);
	
	//����8
	TestDisplay(7);
	//���븺��
	TestDisplay(0x80000000);
	
	system("pause");
	return 0;
}