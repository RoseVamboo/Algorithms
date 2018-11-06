//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目6：从尾到头打印链表
//题目描述:输入一个链表的头结点,从尾到头反过来打印出每个节点的值。
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
/*采用递归的方式来实现输出链表*/
/*递归在本质上就是一个栈结构*/
void PrintListReversingly_Recursively(ListNode* pHead){
	if (pHead != nullptr){
		if (pHead->m_pNext != nullptr){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

//-------------开始测试-------------

void TestDisplay(ListNode* pHead){
	printList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

/*空链表*/
void Test_Null(){
	printf("\nTest_Null 开始测试.\n");
	TestDisplay(nullptr);
}

/*只有一个节点的链表*/
void Test_One(){
	printf("\nTest_One 开始测试.\n");
	ListNode* pHead = createListNode(1);
	TestDisplay(pHead);
	destroyList(pHead);
}

/*多节点链表*/
void Test_Mutiply(){
	printf("\nTest_Mutiply 开始测试.\n");
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

