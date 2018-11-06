/*
1、输入身份证号，通过计算比较校验位来判断身份证号是否正确。
如，aaaaaayyyymmddxxsp共18位，其中：
年份代码yyyy共4位。最后一位p为校验位。
校验规则是：
（1）对前17位数字的权求和 S=Sum(Ai*Wi)，i=0,...,16
Ai：表示第i位置上的身份证号码数字值
Wi：表示第i位置上的加权因子
Wi：7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
（2）计算模 Y=mod(S,11)
（3）通过模得到对应的校验码
        Y：0 1 2 3 4 5 6 7 8 9 10
		校验码：1 0 X 9 8 7 6 5 4 3 2
		例如，如果得到Y为9则最后的校验位p应该为3
		如果校验位不是3，则该身份证号码不正确。
		输入示例：
		110130197606175317
		输出示例：
		110130197606175317 正确.
		输入示例：
		110200197501175220
		输出示例：
		应为：11020019750117522X
*/

#include<stdio.h>
#include<stdlib.h>
int Wi[] = { 7 ,9, 10 ,5 ,8, 4, 2 ,1, 6, 3, 7 ,9 ,10 ,5, 8 ,4 ,2 };
char P[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

void main_2017_1(){
	char id[19];
	int idint[17];
	const char *str;
	while (true){
		printf("请输入18位身份证:\n");
		scanf("%s", &id);
		for (int i = 0; i < 17; i++){

			idint[i] = id[i] - '0';
		}
		int sum = 0;
		for (int i = 0; i < 17; i++){
			sum += idint[i] * Wi[i];
		}
		int Y = sum % 11;
		if (P[Y] == id[17]){
			printf("%s", id);
			printf("   正确.");
		}
		else{
			printf("应为: ");
			for (int i = 0; i < 17; i++){
				printf("%c", id[i]);
			}
			printf("%c", P[Y]);
		}
		printf("\n");
	}
	
	system("pause");
}

/*
printf("%s",s[0]); -- 不加&符号 s[0] 表示 整型值，数值等于s[]里第一个字符(你的情况是h) 的 ASCII 值，如果用%d 格式打印，得104,如果用%c 格式打印,得字母h, 用%s打印 得乱码。
printf("%d",s[0]); 打出 104
printf("%c",s[0]); 打出 h
%s 输出格式，用于字符串，要求给 字符串的首地址，
char s[] 的首地址 是 &s[0] 或 s.
printf("%s",s); 打出 how are you
printf("%s",&s[0]); 打出 how are you
printf("%s",&s[1]); 打出 ow are you
printf("%s",&s[2]); 打出 w are you
*/