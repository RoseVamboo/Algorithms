//---------��ָOffer--------
//������ջʵ�ֶ���
//--------------------------
#pragma once
#include <stack>
#include<exception>

using namespace std;
template<typename T>class CQueue{
public:
	CQueue(void);
	~CQueue(void);

	/*�ڶ���ĩβ���ӽڵ�*/
	void appendNode(const T& node);

	/*ɾ�����е�ͷ���*/
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};
template <typename T> CQueue<T>::CQueue(void){}
template <typename T> CQueue<T>::~CQueue(void){}

template<typename T>void CQueue<T>::appendNode(const T& element){
	stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead(){
	if (stack2.size() <= 0){
		while (stack1.size() > 0){
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0){
		//throw new exception("�ö���û��ֵ!");
		printf("�ö�����û����!");
		return ' ';
	}
	else{
		T head = stack2.top();
		stack2.pop();

		return head;
	}
	
}