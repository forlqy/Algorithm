#pragma once
//#define Posi(T) ListNode<T>*   //�б�ڵ�λ�ã�ISO C++.0x, template alias��
//#include "listnode_implementation.h"
using Rank = int;
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*;//�б���λ��
template <typename T>//Ϊ�˼�࣬��ȫ���Ų��ٹ��ȷ�װ
struct ListNode {//�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
	T data;//��ֵ
	ListNodePosi<T> pred;//ǰ��
	ListNodePosi<T> succ;//���
//���캯��
	ListNode() {}//���header��trailer�Ĺ���
	ListNode(T e, ListNodePosi<T> p = nullptr, ListNodePosi<T> s = nullptr) : data(e), pred(p), succ(s){}//Ĭ�Ϲ�����
//�����ӿ�
	ListNodePosi<T> insertAsPred(T const& e);//ǰ����
	ListNodePosi<T> insertAsSucc(T const& e);//�����
};


