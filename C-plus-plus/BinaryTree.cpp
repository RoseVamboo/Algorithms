#include<cstdio>
#include"binaryTree.h"

BinaryTreeNode* createBinaryTreeNode(int value){
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight){
	if (pParent != nullptr){
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void printTreeNode(const BinaryTreeNode* pNode){
	if (pNode != nullptr){
		printf("该节点的值: %d\n", pNode->m_nValue);
		if (pNode->m_pLeft != nullptr){
			printf("其左节点的值是: %d.\n", pNode->m_pLeft->m_nValue);
		}
		else{
			printf("左节点为空!\n");
		}
		if (pNode->m_pRight != nullptr){
			printf("其右节点的值为: %d.\n", pNode->m_pRight->m_nValue);
		}
		else{
			printf("其右节点为空!\n");
		}
	}
	else{
		printf("该节点为空!\n");
	}
	printf("\n");
}

void printTree(const BinaryTreeNode* pRoot){
	printTreeNode(pRoot);
	if (pRoot != nullptr){
		if (pRoot->m_pLeft != nullptr)
			printTree(pRoot->m_pLeft);
		if (pRoot->m_pRight != nullptr)
			printTree(pRoot->m_pRight);
	}
}

void destroyTree(BinaryTreeNode* pRoot){
	if (pRoot != nullptr){
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		destroyTree(pLeft);
		destroyTree(pRight);
	}
}