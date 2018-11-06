#include<stdio.h>
#include<stdlib.h>
int* nixushu(int n){
	int data =0;
	
	int ss[20];
	int i = 0;
	while(n>0){

		data = n % 10;
		if (data == 0&&i==0){
			ss[i++] = 0;
		}
		else if (data != 0 && i == 0){
			ss[i++] = 1;
		}
		ss[i++] = data;
		n = n /10;
	}
	return ss;
}
void main_beihang_1(){
	int n;
	printf("«Î ‰»În=");
	scanf("%d", &n);
	//printf("n=%d", n);
	int* data=nixushu(n);
	int k = 0;
	if (data[0] == 1){
		
		printf("%d*%d=%d", n, k, data);
	}
	else{
		printf("%d %d", n, data);
	}
	system("pause");
}