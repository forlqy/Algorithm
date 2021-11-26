#pragma once
//#define Posi(T) ListNode<T>*   //�б�ڵ�λ�ã�ISO C++.0x, template alias��
using Rank = int;
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*;//�б���λ��
template <typename T>//Ϊ�˼�࣬��ȫ���Ų��ٹ��ȷ�װ
struct ListNode {//�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
	T data;//��ֵ
	ListNodePosi(T) pred;//ǰ��
	ListNodePosi(T) succ;//���
	ListNode() {}//���header��trailer�Ĺ���
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) : data(e), pred(p), succ(s){}//Ĭ�Ϲ�����
	ListNodePosi(T) insertAsPred(T const& e);//ǰ����
	ListNodePosi(T) insertAsSucc(T const& e);//�����
};