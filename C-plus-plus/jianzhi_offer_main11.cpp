//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目11：二进制中1的个数
//题目描述:请实现一个函数,输入一个整数,输出该数二进制表示中1的个数。
//例如把9表示成二进制是1001,有2位1.因此如果输入9，该函数输出2。
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
//该方法适用于n>0的整数。
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

//------------开始测试---------
void TestDisplay(int n){
	int number = n;
	if (n < 0){
		printf("方法NumberOf1_s1 会陷入死循环.\n");
	}
	else{
		int actual = NumberOf1_s1(n);
		printf("方法NumberOf1_s1中 n=%d 的二进制中1的个数为: %d \n", number, actual);
	}
	int actual1 = NumberOf1_s2(n);
	printf("方法NumberOf1_s2中 n=%d 的二进制中1的个数为: %d \n", number, actual1);
	int actual2 = NumberOf1_s3(n);
	printf("方法NumberOf1_s13中 n=%d 的二进制中1的个数为: %d \n", number, actual2);
}
int main_main11(){
	//输入0
	TestDisplay(0);

	//输入1
	TestDisplay(1);
	
	//输入8
	TestDisplay(7);
	//输入负数
	TestDisplay(0x80000000);
	
	system("pause");
	return 0;
}