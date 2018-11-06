//------------
//  剑指Offer
//------------
//知识点:
//__declspec(dllexport):
//将一个函数声名为导出函数，就是说这个函数要被其他程序调用，
//即作为DLL的一个对外函数接口
//------------

#pragma once

struct BinaryTreeNode{
	int             m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

__declspec(dllexport) BinaryTreeNode* createBinaryTreeNode(int value);
__declspec(dllexport) void connectTreeNodes(BinaryTreeNode* pParent,
	BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
__declspec(dllexport) void printTreeNode(const BinaryTreeNode* pNode);
__declspec(dllexport) void printTree(const BinaryTreeNode* pRoot);
__declspec(dllexport) void destroyTree(BinaryTreeNode* pRoot);