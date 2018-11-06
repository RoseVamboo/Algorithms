//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目6：用两个栈实现队列
//题目描述:用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendNode
//和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
//--------------------------------------------------------------

#include "Queue.h"

//------------测试代码-----------
void TestDisplay(char actual, char expected){
	if (actual == expected){
		printf("测试通过\n");
	}
	else{
		printf("测试失败\n");
	}
}

int main_offer_8(){
	CQueue<char> queue;
	queue.appendNode('a');
	queue.appendNode('b');
	queue.appendNode('c');

	char head = queue.deleteHead();
	TestDisplay(head, 'a');

	head = queue.deleteHead();
	TestDisplay(head, 'b');

	queue.appendNode('d');
	head = queue.deleteHead();
	TestDisplay(head, 'c');
	
	head = queue.deleteHead();
	TestDisplay(head, 'd');
	head = queue.deleteHead();


	system("pause");
	return 0;
}