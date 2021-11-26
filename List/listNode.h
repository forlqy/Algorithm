#pragma once
//#define Posi(T) ListNode<T>*   //列表节点位置（ISO C++.0x, template alias）
using Rank = int;
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*;//列表结点位置
template <typename T>//为了简洁，完全开放不再过度封装
struct ListNode {//列表节点模板类（以双向链表形式实现）
	T data;//数值
	ListNodePosi(T) pred;//前驱
	ListNodePosi(T) succ;//后继
	ListNode() {}//针对header和trailer的构造
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) : data(e), pred(p), succ(s){}//默认构造器
	ListNodePosi(T) insertAsPred(T const& e);//前插入
	ListNodePosi(T) insertAsSucc(T const& e);//后插入
};