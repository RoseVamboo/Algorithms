//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ6����β��ͷ��ӡ����
//��Ŀ����:����һ�������ͷ���,��β��ͷ��������ӡ��ÿ���ڵ��ֵ��
//--------------------------------------------------------------
#include "List.h"
#include<stack>
void PrintListReversingly_Iteratively(ListNode* pHead){

	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()){
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}
/*���õݹ�ķ�ʽ��ʵ���������*/
/*�ݹ��ڱ����Ͼ���һ��ջ�ṹ*/
void PrintListReversingly_Recursively(ListNode* pHead){
	if (pHead != nullptr){
		if (pHead->m_pNext != nullptr){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

//-------------��ʼ����-------------

void TestDisplay(ListNode* pHead){
	printList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

/*������*/
void Test_Null(){
	printf("\nTest_Null ��ʼ����.\n");
	TestDisplay(nullptr);
}

/*ֻ��һ���ڵ������*/
void Test_One(){
	printf("\nTest_One ��ʼ����.\n");
	ListNode* pHead = createListNode(1);
	TestDisplay(pHead);
	destroyList(pHead);
}

/*��ڵ�����*/
void Test_Mutiply(){
	printf("\nTest_Mutiply ��ʼ����.\n");
	ListNode* pHead = createListNode(1);
	ListNode* pNode1 = createListNode(2);
	ListNode* pNode2= createListNode(3);
	ListNode* pNode3= createListNode(4);
	ListNode* pNode4 = createListNode(5);

	connectListNodes(pHead, pNode1);
	connectListNodes(pNode1, pNode2);
	connectListNodes(pNode2, pNode3);
	connectListNodes(pNode3, pNode4);
	
	TestDisplay(pHead);
	destroyList(pHead);
}

int main_offer_6(){
	Test_Null();
	Test_One();
	Test_Mutiply();
	system("pause");
	return 0;
}

