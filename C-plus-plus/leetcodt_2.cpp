#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
struct ListNode{
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//创建头结点
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p = head;
	int carray = 0;//进位
	while (l1&&l2){
		int sum = l1->val + l2->val+carray;
		if (sum >= 10){
			sum -= 10;
			carray = 1;
		}
		else{
			carray = 0;
		}
		
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = sum;
		l1 = l1->next;
		l2 = l2->next;
	}
	//继续处理较长链表的数据
	l1 = l1 ? l1 : l2;
	while (l1){
		int sum = l1->val + carray;
		if (sum >=10){
			sum -= 10;
			carray = 1;
		}
		else{
			carray = 0;
		}
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = sum;
		l1 = l1->next;
	}
	//判断最后是否还有进位
	if (carray == 1){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = 1;
	}
	p->next = NULL;
	//将空的头结点释放，从第二个结点返回
	p = head;
	head = head->next;
	free(p);
	return head;
}