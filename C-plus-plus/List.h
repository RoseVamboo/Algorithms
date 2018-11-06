//------------
//  ��ָOffer
//------------
//֪ʶ��:
//__declspec(dllexport):
//��һ����������Ϊ��������������˵�������Ҫ������������ã�
//����ΪDLL��һ�����⺯���ӿ�
//------------

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};
__declspec(dllexport) ListNode* createListNode(int value);
__declspec(dllexport) void connectListNodes(ListNode* pCurrent, ListNode* pNext);
__declspec(dllexport) void printListNode(ListNode* pNode);
__declspec(dllexport) void printList(ListNode* pHead);
__declspec(dllexport) void destroyList(ListNode* pHead);
__declspec(dllexport) void addToTail(ListNode** pHead, int value);
__declspec(dllexport) void removeNode(ListNode **pHead, int value);