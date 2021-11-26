#pragma once
#include <iostream>
#include "Node.h"
class Zuma
{
public:
	Zuma();
	~Zuma();

	int size() { return size_; }
	void insert(Node* t, int pos);
	void push(Node* newNode);
	void elimTriElem();
	void erase(int aheadNum, Node* curr);
	friend std::ostream& operator<<(std::ostream& os, Zuma& ll);

private:
	Node header_;
	Node trailer_;
	Node* cursor_;
	int size_;

	void cursorTo(int pos);
};