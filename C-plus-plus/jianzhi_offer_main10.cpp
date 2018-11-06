//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//��Ŀ10��쳲���������
//��Ŀ����:дһ������,����n,��쳲�����Fibonacci���еĵ�n�
//쳲��������ж�������:
//f(n)=0,n=0;f(n)=1,n=1;f(n)=f(n-1)+f(n-2),n>1.
//--------------------------------------------------------------
//--------------------------------------------------------------
//��չ�⣺
//1.һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ��
//n����̨�׹��ж�����������--��ʵ����쳲��������е�Ӧ��
//2.���ǿ�����2x1��С���κ��Ż�����ȥ���Ǹ���ľ��Ρ�
//������8��2x1��С�������ص��ظ���һ��2x8�Ĵ���Σ��ܹ��ж����ַ�����
#include<cstdio>
#include<exception>
//�̿�����̵��ݹ�ľ�������
long long Fibonacci_1(unsigned int n){
	if (n <= 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

//ѭ������:�����������Ч�ʣ��������ظ����㣩�������ܷ�ֹ�ڴ������û�в��õݹ飩
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

//���ھ���˷�
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

//----------��ʼ����-----------
void TestDisplay(int n, int expected){
	if (Fibonacci_1(n) == expected){
		printf("Fibonacci_1 ͨ��!\n");
	}
	else{
		printf("Fibonacci_1 δͨ��!\n");
	}

	if (Fibonacci_2(n) == expected){
		printf("Fibonacci_2 ͨ��!\n");
	}
	else{
		printf("Fibonacci_2 δͨ��!\n");
	}

	if (Fibonacci_3(n) == expected){
		printf("Fibonacci_3 ͨ��!\n");
	}
	else{
		printf("Fibonacci_3 δͨ��!\n");
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
