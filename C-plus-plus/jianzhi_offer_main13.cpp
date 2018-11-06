//Copyright(c) 2018, RoseVorchid All rights reserved.
//--------------------------------------------------------------
//    ��ָOffer
//--------------------------------------------------------------
//--------------------------------------------------------------
//������13:�����˵��˶���Χ
//��Ŀ����:������һ��m��n�еķ���һ�������˴�����(0,0)�ĸ��Կ�ʼ�ƶ���
//��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
//����k�ĸ��ӡ�����,��kΪ18ʱ���������ܹ����뷽��(35,37)����Ϊ3+5+3+7=18.
//�������ܽ��뷽��(35,38)��Ϊ3+5+3+8=19.
//���ʸû������ܹ��ﵽ���ٸ�����?
//--------------------------------------------------------------

#include<cstdio>
#include<exception>
int movingCountCore(int threshold, int rows, int cols, int ros, int col, bool* visited);
bool check(int threshold, int rows, int cols, int ros, int col, bool* visited);
int getDigitSum(int number);
int movingCount(int threshold, int rows, int cols){
	if (threshold < 0 || rows <= 0 || cols <= 0){
		return 0;
	}
	bool * visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++){
		visited[i] = false;
	}
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)){
		visited[row*cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +
			movingCountCore(threshold, rows, cols, row, col - 1, visited) +
			movingCountCore(threshold, rows, cols, row, col + 1, visited) +
			movingCountCore(threshold, rows, cols, row + 1, col, visited);
	}
	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited){
	if (row >= 0 && row < rows&&col >= 0 && col < cols
		&&getDigitSum(row) + getDigitSum(col) <= threshold
		&&!visited[row*cols + col]){
		return true;
	}
	else{
		return false;
	}
}

int getDigitSum(int number){
	int sum = 0;
	while (number > 0){
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

//-----------��ʼ����------------
void TestDisplay(char* testName, int threshold, int rows, int cols, int expected){
	if (testName != nullptr){
		printf("���� %s ��ʼ���� .\n", testName);
	}
	if (movingCount(threshold, rows, cols) == expected){
		printf("����ͨ��.\n");
	}
	else{
		printf("����Ϊͨ��!\n");
	}
}

//�������޷���������һ������
void Test_none(){
	TestDisplay("Test_none", -10, 10, 10, 0);
}

//����Ϊһ��һ��
void Test_one_row_one_col(){
	TestDisplay("Test_one_row_one_col", 15, 1, 1, 1);
}

//
// ������ж���
void Test_dup_row_dup_col_1()
{
	TestDisplay("Test_dup_row_dup_col_1", 5, 10, 10, 21);
}

// ������ж���
void Test_dup_row_dup_col_2()
{
	TestDisplay("Test_dup_row_dup_col_2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void Test_one_row_some()
{
	TestDisplay("Test_one_row_some", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void Test_one_row_all()
{
	TestDisplay("Test_one_row_all", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void Test_one_col_some()
{
	TestDisplay("Test_one_col_some", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void Test_one_col_all()
{
	TestDisplay("Test_one_col_all", 15, 10, 1, 10);
}

int main_offer_13(){
	//�������޷���������һ������
	Test_none();
	//����Ϊһ��һ��
	Test_one_row_one_col();
	// ������ж���
	Test_dup_row_dup_col_1();
	// ������ж���
	Test_dup_row_dup_col_2();
	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	Test_one_row_some();
	// ����ֻ��һ�У��������ܵ������з���
	Test_one_row_all();
	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	Test_one_col_some();
	// ����ֻ��һ�У��������ܵ������з���
	Test_one_col_all();
	system("pause");
	return 0;
}