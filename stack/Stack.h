#pragma once
#include "Vector.h"
template <typename T> class Stack : public Vector<T> { //����������/ĩ����Ϊջ��/��
public: //ԭ�нӿ�һ������
	void push(T const& e) { this->insert(e); } //��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
	T pop() { return this->remove(this->size() - 1); } //��ջ����Ч��ɾ��������ĩԪ��
	T& top() { return (*this)[this->size() - 1]; } //ȡ����ֱ�ӷ���������ĩԪ��
};