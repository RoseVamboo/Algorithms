//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    剑指Offer
//--------------------------------------------------------------
//--------------------------------------------------------------
//题目10：斐波那契数列
//题目描述:写一个函数,输入n,求斐波那契Fibonacci数列的第n项。
//斐波那契数列定义如下:
//f(n)=0,n=0;f(n)=1,n=1;f(n)=f(n-1)+f(n-2),n>1.
//--------------------------------------------------------------
//--------------------------------------------------------------
//拓展题：
//1.一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个
//n级的台阶共有多少种跳法？--其实就是斐波那契数列的应用
//2.我们可以用2x1的小矩形横着或竖着去覆盖更大的矩形。
//请问用8个2x1的小矩形无重叠地覆盖一个2x8的大矩形，总共有多少种方法？
#include<cstdio>
#include<exception>
//教科书里教导递归的经典例子
long long Fibonacci_1(unsigned int n){
	if (n <= 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

//循环方法:不仅可以提高效率（减少了重复计算），而且能防止内存溢出（没有采用递归）
long long Fibonacci_2(unsigned int n){
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	long long fibonacci_one = 0;
	long long fibonacci_two = 1;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; i++){
		fibN = fibonacci_one + fibonacci_two;
		fibonacci_one = fibonacci_two;
		fibonacci_two = fibN;
	}
	return fibN;
}

//基于矩阵乘法
#include<cassert>
struct Matrix2Multiply{
	Matrix2Multiply(
	long long m00 = 0,
	long long m01 = 0,
	long long m10 = 0,
	long long m11 = 0
	)
	:m_00(m00), m_01(m01), m_10(m10), m_11(m11){}

	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
};

Matrix2Multiply MatrixMultiply(const Matrix2Multiply& matrix1, const Matrix2Multiply& matrix2){
	return Matrix2Multiply(
		matrix1.m_00*matrix2.m_00+matrix1.m_01*matrix2.m_10,
		matrix1.m_00*matrix2.m_01+matrix1.m_01*matrix2.m_11,
		matrix1.m_10*matrix2.m_00+matrix1.m_11*matrix2.m_10,
		matrix1.m_10*matrix2.m_01+matrix1.m_11*matrix2.m_11
		);
}
Matrix2Multiply MatrixPower(unsigned int n){
	assert(n > 0);

	Matrix2Multiply matrix;
	if (n == 1){
		matrix = Matrix2Multiply(1, 1, 1, 0);
	}
	else if (n % 2 == 0){
		matrix = MatrixPower(n / 2);
		matrix = MatrixMultiply(matrix, matrix);
	}
	else if (n % 2 == 1){
		matrix = MatrixPower((n - 1) / 2);
		matrix = MatrixMultiply(matrix, matrix);
		matrix = MatrixMultiply(matrix, Matrix2Multiply(1, 1, 1, 0));
	}
	return matrix;
}

long long Fibonacci_3(unsigned int n){
	if (n < 2){
		return n;
	}
	Matrix2Multiply matrixMinus2 = MatrixPower(n - 1);
	return matrixMinus2.m_00;
}

//----------开始测试-----------
void TestDisplay(int n, int expected){
	if (Fibonacci_1(n) == expected){
		printf("Fibonacci_1 通过!\n");
	}
	else{
		printf("Fibonacci_1 未通过!\n");
	}

	if (Fibonacci_2(n) == expected){
		printf("Fibonacci_2 通过!\n");
	}
	else{
		printf("Fibonacci_2 未通过!\n");
	}

	if (Fibonacci_3(n) == expected){
		printf("Fibonacci_3 通过!\n");
	}
	else{
		printf("Fibonacci_3 未通过!\n");
	}
}

int main_offer_10(){
	TestDisplay(0, 0);
	TestDisplay(1, 1);
	TestDisplay(2, 1);
	TestDisplay(3, 2);
	TestDisplay(4, 3);
	TestDisplay(5, 5);
	TestDisplay(6, 8);
	TestDisplay(7, 13);
	TestDisplay(8, 21);
	TestDisplay(9, 34);
	TestDisplay(10, 55);

	TestDisplay(40, 102334155);
	system("pause");
	return 0;
}
