/*
2、输入字符串，输出字符串中包含的数字，比如 2.3ABC0-2.3  输出 2.3 0 -2.3。
注意一些特殊的情况如+004.500值为+4.5。
*/
#include<iostream>
#include<string>
using namespace std;

void main_beili_2016_2(){
	string strs[105], str, s, str1, str2;
	int n = 0;
	while (getline(cin, strs[n])){
		n++;
	}
	for (int i = 0; i < n; i++){
		str1 = strs[i];
		int start = -1;//连续0时，0开始的位置
		int end = -1;//连续0时，0结束的位置
		int startdata = -1;
		int endnondata = -1;
		for (int j = str1.length() - 1; j >= 0; j--){
			if (str1[j] == '0'){

			}
			else if (str1[j] >= 'a'&&str1[j] <= 'z'){

			}
			else if (str1[j] >= 'A'&&str1[j] <= 'Z'){

			}
			else if (str[j] > '0'&&str[j] <= '9'){
				startdata = j;
				cout << str1[startdata] << "";
				break;
			}
			else{
				endnondata = j;
			}
		}
		if (endnondata == -1){
			str2 = str1.substr(0, startdata + 1);
		}
		else{
			str2 = str1.substr(0, endnondata + 1);
			str2 = str2.replace(startdata, endnondata - startdata, "");
		}
		
		cout << "位置1：" << startdata << "截取效果1:" << str2 << endl;

		 startdata = -1;
		 endnondata = -1;
		 for (int j = 0; j <str2.length(); j++){
			 if (str2[j] == '0'){

			}
			 else if (str2[j] >= 'a'&&str2[j] <= 'z'){

			}
			 else if (str2[j] >= 'A'&&str2[j] <= 'Z'){

			}
			 else if (str2[j] > '0'&&str2[j] <= '9'){
				startdata = j;
				cout << str2[startdata] << "";
				break;
			}
			else{
				endnondata = j;
			}
		}
		if (endnondata == -1){
			
			if (startdata != 0){
				str = str2.replace(0, startdata, "");
			}
			else{

			}
		}
		else if(endnondata==0){
			if (startdata > 1){
				str = str2.replace(1, startdata, "");
			}
		}
		else{
			
			if ((startdata -endnondata)>2){
				str = str2.replace(endnondata, startdata - endnondata, "");
			}
			str = str2.replace(0, endnondata, "");
		}

		cout << "位置2：" << startdata << "截取效果2:" << str << endl;
		for (int j = 0; j < str.length(); j++){
			if (j == 0){
				if (str[j]>'0'&&str[j] <= '9'){
					cout << str[j];
				}
				else if (str[j] == '0'){

				}
				else if (str[j] >= 'a'&&str[j] <= 'z'){

				}
				else if (str[j] >= 'A'&&str[j] <= 'Z'){

				}
				else{
					cout << str[j];
				}
			}
			else{
				if (str[j]>'0'&&str[j] <= '9'){
					cout << str[j];
				}
				else if (str[j] == '0'){
					cout << str[j];
				}
				else if (str[j] >= 'a'&&str[j] <= 'z'){

				}
				else if (str[j] >= 'A'&&str[j] <= 'Z'){

				}
				else{
					cout << str[j];
				}
			}
		}
		cout << endl;
	}
	system("pause");
}