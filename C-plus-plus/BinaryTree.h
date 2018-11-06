//------------
//  ��ָOffer
//------------
//֪ʶ��:
//__declspec(dllexport):
//��һ����������Ϊ��������������˵�������Ҫ������������ã�
//����ΪDLL��һ�����⺯���ӿ�
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