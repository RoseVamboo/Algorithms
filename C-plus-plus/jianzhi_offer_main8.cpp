//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ6��������ջʵ�ֶ���
//��Ŀ����:������ջʵ��һ�����С����е��������£���ʵ��������������appendNode
//��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�
//--------------------------------------------------------------

#include "Queue.h"

//------------���Դ���-----------
void TestDisplay(char actual, char expected){
	if (actual == expected){
		printf("����ͨ��\n");
	}
	else{
		printf("����ʧ��\n");
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