#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
struct ListNode{
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	//����ͷ���
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p = head;
	int carray = 0;//��λ
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
	//��������ϳ����������
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
	//�ж�����Ƿ��н�λ
	if (carray == 1){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = 1;
	}
	p->next = NULL;
	//���յ�ͷ����ͷţ��ӵڶ�����㷵��
	p = head;
	head = head->next;
	free(p);
	return head;
}