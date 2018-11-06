//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ7���ؽ�������
//��Ŀ����:����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//����:����ǰ�����{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6},
//���ؽ���ͼ2.6��ʾ�Ķ�������
//--------------------------------------------------------------

#include "BinaryTree.h"
#include<exception>
#include<cstdio>

BinaryTreeNode* constructCore(
	int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder){
	//ǰ��������еĵ�һ�������Ǹ��ڵ��ֵ
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = nullptr;
	root->m_pRight = nullptr;

	if (startPreorder == endPreorder){
		if (startInorder == endInorder&&*startPreorder == *startInorder){
			return root;
		}
		else{
			throw std::exception("��Ч������!");
		}
	}

	//������������ҵ����ڵ��ֵ
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder &&*rootInorder!=rootValue){
		throw std::exception("��Ч������!");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0){
		//����������
		root->m_pLeft = constructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder){
		//����������
		root->m_pRight = constructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

BinaryTreeNode* construct(int* preorder, int* inorder, int length){
	
	if (preorder == nullptr || inorder == nullptr || length<=0){
		
		return nullptr;
	}
	return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

//-------------------��ʼ����------------------
void testDiplay(int* preorder, int* inorder, int length, char* testName){
	if (testName != nullptr){
		printf("��ʼ���� %s \n", testName);
	}

	printf("ǰ�����������Ϊ:");
	for (int i = 0; i < length; i++){
		printf("%d ", preorder[i]);
	}
	printf("\n");

	printf("�������������Ϊ:");
	for (int i = 0; i < length; i++){
		printf("%d ", inorder[i]);
	}
	printf("\n");
	try{
		BinaryTreeNode* root = construct(preorder, inorder, length);
		printTree(root);
		destroyTree(root);
	}
	catch (std::exception&exception){
		printf("��Ч����!");
	}
}

//����һ����ָ��
void test_nullptr(){
	testDiplay(nullptr, nullptr, 0, "test_nullptr");
}

//ֻ��һ���ڵ�
void test_oneNode(){
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };
	testDiplay(preorder, inorder, length,"test_oneNode");
}

//���нڵ㶼Ϊ��ڵ�
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void test_onlyLeft(){
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };
	testDiplay(preorder, inorder, length, "test_onlyLeft");
}
//���нڵ㶼Ϊ�ҽڵ�
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void test_onlyRight(){
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };
	testDiplay(preorder, inorder, length, "test_onlyRight");
}
//��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test_commonBinaryTree(){
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5,6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	testDiplay(preorder, inorder, length, "test_commonBinaryTree");
}

// ��ȫ������
//            1
//         /     \
//        2       3  
//       / \     / \
//      4   5   6   7
void test_completeBinaryTree(){
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };
	testDiplay(preorder, inorder, length, "test_completeBinaryTree");
}

// ����������ƥ�������
void test_invald()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	testDiplay(preorder, inorder, length, "��ƥ�����������");
}
int main_offer_7(){
	test_nullptr();
	test_oneNode();
	test_onlyLeft();
	test_onlyRight();
	test_commonBinaryTree();
	test_completeBinaryTree();
	test_invald();
	system("pause");
	return 0;
}