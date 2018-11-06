//------------
//  剑指Offer
//------------
//知识点:
//__declspec(dllexport):
//将一个函数声名为导出函数，就是说这个函数要被其他程序调用，
//即作为DLL的一个对外函数接口
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