//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目7：重建二叉树
//题目描述:输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如:输入前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6},
//则重建出图2.6所示的二叉树。
//--------------------------------------------------------------

#include "BinaryTree.h"
#include<exception>
#include<cstdio>

BinaryTreeNode* constructCore(
	int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder){
	//前序遍历序列的第一个数字是根节点的值
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
			throw std::exception("无效的输入!");
		}
	}

	//在中序遍历中找到根节点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder &&*rootInorder!=rootValue){
		throw std::exception("无效的输入!");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0){
		//构建左子树
		root->m_pLeft = constructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder){
		//构建右子树
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

//-------------------开始测试------------------
void testDiplay(int* preorder, int* inorder, int length, char* testName){
	if (testName != nullptr){
		printf("开始测试 %s \n", testName);
	}

	printf("前序遍历的序列为:");
	for (int i = 0; i < length; i++){
		printf("%d ", preorder[i]);
	}
	printf("\n");

	printf("中序遍历的序列为:");
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
		printf("无效输入!");
	}
}

//输入一个空指针
void test_nullptr(){
	testDiplay(nullptr, nullptr, 0, "test_nullptr");
}

//只有一个节点
void test_oneNode(){
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };
	testDiplay(preorder, inorder, length,"test_oneNode");
}

//所有节点都为左节点
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
//所有节点都为右节点
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
//普通二叉树
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

// 完全二叉树
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

// 输入两个不匹配的序列
void test_invald()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	testDiplay(preorder, inorder, length, "不匹配的两个序列");
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