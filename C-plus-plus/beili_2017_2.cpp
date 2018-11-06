/*
2、显示出如下数组中的所有元素，并使用二分查找法在数组中查找元素。

int a[]={-90,-32,12,16,24,36,45,59,98,120};

输入输出示例

-90   -32   12   16   24   36   45   59   98   120

请输入所要查找的元素：24

输出：第5个元素为24，比较次数为1

请输入所要查找的元素：120

输出：第10个元素，比较次数为4

请输入所要查找的元素：6

输出：查找失败 比较次数为3
*/
#include<stdio.h>
#include<stdlib.h>
int result1[2] = { 0, 0 };
int index1 = 0;
int* binarySearch(int start,int end,int* a,int target,int index){
	int media = (end + start) / 2;
	
	//index1 = 0;
	if (start<=end){
		index++;
		if (target < a[media]){
			end = media - 1;
			
			binarySearch(start, end, a, target,index);
		}
		else if (target>a[media]){
			start = media + 1;
			//index++;
			binarySearch(start, end, a, target,index);
		}
		else{
			result1[0] = media + 1;
			result1[1] = index;
			return result1;
		}
	}
	else{
		result1[1] = index;
		return result1;
	}
	result1[1] = index;
	return result1;
}

int* binary(int start, int end, int* a, int target){
	int index = 0;
	int result[2] = { 0, 0 };
	while (start <=end){
		index++;
		int media = (start + end) / 2;
		if (target == a[media]){
			result[0] = media+1;
			result[1] = index;
			return result;
		}
		else if(target<a[media]){
			end = media - 1;
		}
		else{
			start = media + 1;
		}
	}
	result[1] = index;
	return result;
}
void main_beili_2017_2(){
	int a[] = { -90, -32, 12, 16, 24, 36, 45, 59, 98, 120 };
	int target = 0;
	//int aa[2] = { 0, 0 };
	while (true){
		printf("请输入要查找的元素:");
		scanf("%d", &target);
		int len = sizeof(a) / sizeof(0);
		int start = 0;
		int end = len - 1;
		
		int* aa = binary(start, end, a, target);
		if (aa[0] == 0){
			printf("查找失败, 比较次数为:%d", aa[1]);
		}
		else{
			printf("第%d个元素为:%d, 比较次数为:%d", aa[0], target, aa[1]);
		}
		printf("\n");
	}
	system("pause");
}