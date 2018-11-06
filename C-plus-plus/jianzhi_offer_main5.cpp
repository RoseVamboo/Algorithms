//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目5：替换空格
//题目描述:请实现一个函数,把字符串中的每一个空格替换成"%20".
//列如输入"We are happy.",则输出"We%20are%20happy."
//--------------------------------------------------------------
//--------------------------------------------------------------
//相关题目:
//有两个排序的数组A1和A2,内存在A1的末尾有足够多的空余空间容纳A2。
//请实现一个函数,把A2中的所有数字插入到A1中并且所有的数字是排序的.

//举一反三:
//合并两个数组(包括字符串)时,如果从前往后赋值每个数字(或字符串)
//需要重复移动数字(字符串)多次,那么我们可以考虑从后往前复制,
//这样就能减少移动的次数,从而提高效率.
//--------------------------------------------------------------
#include<cstdio>
#include<cstring>
#include<stdlib.h>
//length 为字符串数组string的总容量
void  ReplaceBlank(char str[], int length){
	if (str == nullptr&&length <= 0){
		return;
	}
	/*originalLength为字符串str的实际长度*/
	int originalLength = 0;
	/*字符串中空格数*/
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0'){
		++originalLength;
		if (str[i] == ' '){
			++numberOfBlank;
		}
		++i;
	}
	/*newLength为把空格替换成'%20'之后的长度*/
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

//--开始测试--
void TestDisplay(char str[], int length, char* testName){
	if (testName != nullptr){
		printf("%s 开始测试 ",testName);
	}
	ReplaceBlank(str, length);
	printf("新的字符串=%s",str);
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